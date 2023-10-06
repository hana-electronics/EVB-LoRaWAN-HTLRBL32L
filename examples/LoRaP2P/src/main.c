/*
 Copyright (c) 2023 Hana Electronics Indústria e Comércio LTDA

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

//DEBUG CONFIG FILE:
#ifdef DEBUG
#include "debug_configs.h"
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "uart.h"
#include "spi.h"
#include "rtc.h"
#include "crc.h"
#include "i2c.h"
#include "sx126x.h"
#include "sx126x_board.h"
#include "radio.h"
#include "peripheral_init.h"
#include "lorawan_setup.h"
#include "lora-test.h"
#include "LoRaMac.h"
#include "hal_wrappers.h"
#include "ht_crypto.h"
#include "stsafea_core.h"

#define RF_FREQUENCY 868000000  // Hz
#define TX_OUTPUT_POWER 22		// dBm
#define LORA_BANDWIDTH 0		// [0: 125 kHz, 1: 250 kHz, 2: 500 kHz, 3: Reserved]
#define LORA_SPREADING_FACTOR 7 // [SF7..SF12]
#define LORA_CODINGRATE 1		// [1: 4/5, 2: 4/6,  3: 4/7,  4: 4/8]
#define LORA_PREAMBLE_LENGTH 8  // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT 0   // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON false
#define LORA_IQ_INVERSION_ON false
#define RX_TIMEOUT_VALUE 3000
#define TX_TIMEOUT_VALUE 3000

#define BUFFER_SIZE 64 // Define the payload size here

#define LED_BUILTIN 				  GPIO_PIN_5
#define LED_Port                      GPIOA


RNG_HandleTypeDef hrng;

static RadioEvents_t RadioEvents;
static uint16_t BufferSize = BUFFER_SIZE;
static uint8_t RcvBuffer[BUFFER_SIZE];
static uint8_t TxdBuffer[BUFFER_SIZE];
static bool isMaster = true;
const uint8_t PingMsg[] = "PING";
const uint8_t PongMsg[] = "PONG";

ulong timeToSend 	= 0;
ulong cadTime 		= 0;

uint8_t pingCnt = 0;
uint8_t pongCnt = 0;

// Function declarations
void OnTxDone(void);
void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);
void OnTxTimeout(void);
void OnRxTimeout(void);
void OnRxError(void);
void OnCadDone(bool cadResult);

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	uint8_t status_code = 0;

	/* System initialization function */
	if (SystemInit(SYSCLK_64M, BLE_SYSCLK_NONE) != SUCCESS) {
		/* Error during system clock configuration take appropriate action */
		while(1);
	}
	HAL_Init();
	IRQHandler_Config();
	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_SPI1_Init();
	MX_I2C2_Init();
	MX_CRC_Init();
	MX_RTC_Init();
	MX_GPIO_LP_Init();
	MX_RNG_Init(&hrng);

	RadioEvents.TxDone 		= OnTxDone;
	RadioEvents.RxDone 		= OnRxDone;
	RadioEvents.TxTimeout 	= OnTxTimeout;
	RadioEvents.RxTimeout 	= OnRxTimeout;
	RadioEvents.RxError 	= OnRxError;
	RadioEvents.CadDone  	= OnCadDone;

	RadioInit(&RadioEvents);

	RadioStartCad();

	RadioSetChannel(RF_FREQUENCY);

	RadioSetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
			  LORA_SPREADING_FACTOR, LORA_CODINGRATE,
			  LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
			  true, 0, 0, LORA_IQ_INVERSION_ON, TX_TIMEOUT_VALUE);

	RadioSetRxConfig(MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
			  LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH,
			  LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
			  0, true, 0, 0, LORA_IQ_INVERSION_ON, true);

	RadioRx(RX_TIMEOUT_VALUE);

	timeToSend = HAL_GetTick();

	while(1){

		RadioIrqProcess();
	}

}

void OnTxDone(void)
{
	Radio.Rx(RX_TIMEOUT_VALUE);
}

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
	HAL_Delay(10);
	BufferSize = size;

	memcpy(RcvBuffer, payload, BufferSize);

	HAL_GPIO_WritePin(LED_Port,LED_BUILTIN, SET);

	if (isMaster == true)
	{
		if (BufferSize > 0)
		{
			if (strncmp((const char *)RcvBuffer, (const char *)PongMsg, 4) == 0)
			{
				printf("\n\n\nReceived a PONG in OnRxDone as Master\n\n\n");

				// Wait 500ms before sending the next package
				HAL_Delay(500);

				// Check if our channel is available for sending
				Radio.Standby();
				SX126xSetCadParams(LORA_CAD_08_SYMBOL, LORA_SPREADING_FACTOR + 13, 10, LORA_CAD_ONLY, 0);
				cadTime = HAL_GetTick();
				Radio.StartCad();
				// Sending next Ping will be started when the channel is free
			}
			else if (strncmp((const char *)RcvBuffer, (const char *)PingMsg, 4) == 0)
			{ // A master already exists then become a slave

				printf("\n\n\nReceived a PING in OnRxDone as Master\n\n\n");
				isMaster = false;
				Radio.Rx(RX_TIMEOUT_VALUE);
			}
			else // valid reception but neither a PING or a PONG message
			{	// Set device as master and start again
				isMaster = true;
				Radio.Rx(RX_TIMEOUT_VALUE);
			}
		}
	}
	else
	{
		if (BufferSize > 0)
		{
			if (strncmp((const char *)RcvBuffer, (const char *)PingMsg, 4) == 0)
			{
				printf("\n\n\nReceived a PING in OnRxDone as Slave\n\n\n");

				// Check if our channel is available for sending
				Radio.Standby();
				SX126xSetCadParams(LORA_CAD_08_SYMBOL, LORA_SPREADING_FACTOR + 13, 10, LORA_CAD_ONLY, 0);
				cadTime = HAL_GetTick();
				Radio.StartCad();
				// Sending Pong will be started when the channel is free
			}
			else // valid reception but not a PING as expected
			{	// Set device as master and start again
				printf("\n\n\nReceived something in OnRxDone as Slave\n\n\n");
				isMaster = true;
				Radio.Rx(RX_TIMEOUT_VALUE);
			}
		}
	}
}

void OnTxTimeout(void)
{
//	Radio.Sleep();
	HAL_GPIO_WritePin(LED_Port,LED_BUILTIN, RESET);
	Radio.Rx(RX_TIMEOUT_VALUE);
}

void OnRxTimeout(void)
{
	HAL_GPIO_WritePin(LED_Port, LED_BUILTIN, RESET);

	if (isMaster == true)
	{
		// Wait 500ms before sending the next package
		HAL_Delay(500);

		// Check if our channel is available for sending
		Radio.Standby();
		SX126xSetCadParams(LORA_CAD_08_SYMBOL, LORA_SPREADING_FACTOR + 13, 10, LORA_CAD_ONLY, 0);
		cadTime = HAL_GetTick();
		Radio.StartCad();
		// Sending the ping will be started when the channel is free
	}
	else
	{
		// No Ping received within timeout, switch to Master
		isMaster = true;
		// Check if our channel is available for sending
		Radio.Standby();
		SX126xSetCadParams(LORA_CAD_08_SYMBOL, LORA_SPREADING_FACTOR + 13, 10, LORA_CAD_ONLY, 0);
		cadTime = HAL_GetTick();
		Radio.StartCad();
		// Sending the ping will be started when the channel is free
	}
}

void OnRxError(void)
{
	HAL_GPIO_WritePin(LED_Port, LED_BUILTIN, RESET);

	if (isMaster == true)
	{
		// Wait 500ms before sending the next package
		HAL_Delay(500);

		// Check if our channel is available for sending
		Radio.Standby();
		SX126xSetCadParams(LORA_CAD_08_SYMBOL, LORA_SPREADING_FACTOR + 13, 10, LORA_CAD_ONLY, 0);
		cadTime = HAL_GetTick();
		Radio.StartCad();
		// Sending the ping will be started when the channel is free
	}
	else
	{
		Radio.Rx(RX_TIMEOUT_VALUE);
	}
}

void OnCadDone(bool cadResult)
{
	ulong duration = HAL_GetTick() - cadTime;
	if (cadResult)
	{
		printf("CAD returned channel busy after %ldms\n\n", duration);
		Radio.Rx(RX_TIMEOUT_VALUE);
	}
	else
	{
		printf("CAD returned channel free after %ldms\n\n", duration);
		if (isMaster)
		{
			printf("\n\n\nSending a PING in OnCadDone as Master\n\n\n");
			// Send the next PING frame

			memcpy(TxdBuffer, PingMsg, strlen(PingMsg));
			printf("Payload transmited: %s \n\n",TxdBuffer);

		}
		else
		{
			printf("\n\n\nSending a PONG in OnCadDone as Slave\n\n\n");
			// Send the reply to the PONG string

			memcpy(TxdBuffer, PongMsg, strlen(PongMsg));

			printf("Payload transmited: %s \n\n",TxdBuffer);
		}
		// We fill the buffer with numbers for the payload
		for (int i = 4; i < BufferSize; i++)
		{
			TxdBuffer[i] = i - 4;
		}

		Radio.Send(TxdBuffer, BufferSize);
	}
}

void Error_Handler(void)
{
	/* User can add his own implementation to report the HAL error return state */
	printf("Error Handler\n");
	while(1);
}
/***** Hana Electronics Indústria e Comércio LTDA ****** END OF FILE ****/
