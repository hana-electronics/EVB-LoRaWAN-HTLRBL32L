/*
 Copyright (c) 2023 Hana Electronics Industria e Comercio LTDA

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

RNG_HandleTypeDef hrng;

lora_AppData_t package; //variable to storage the message to be sent
uint32_t timeToSend; // time to send the next lorawan package
uint32_t NextSendTime = 0; // variable to storage the next time to sent the next package
/*
LoRaWAN related configs
#include "lorawandefines.h"
 */

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

#ifdef HT_CRYPTO

	if(keys_provisioned()){
		status_code = ht_crypto_init();
		if(status_code){
			printf("STSAFE-A1xx NOT initialized. \n");
		while(1){}
		}
	}else{
		printf("LoRaWAN keys are NOT set, please flash&run provisioner firmware to set the keys\n");
		while(1);
	}
#endif

	LORAWAN_init(DEFAULT_REGION);

	timeToSend = 10000; //10 seconds

	// Constructs the package to be sent via LoRaWAN (LoRaWAN settings found in lorawandefinas.h file)
	package.Buff = (uint8_t*)"Hi!! this is a LoRaWAN package!"; // Message
	package.BuffSize = strlen((const char*)package.Buff); // Message size
	package.Port = LORAWAN_APP_PORT;					//LoRaWAN port

	while (1){
		LORAWAN_tick();
		// only sends the package when the time is reached
		if (HAL_GetTick() >= NextSendTime) {
			NextSendTime += timeToSend; // adding the next time that the package will be sent
			// Sends the LoRaWAN package
			printf("\n\n==== Sending package ===\n\n");
			lorawan_send(&package);	//function that sends the package
		}
	}
}
/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* User can add his own implementation to report the HAL error return state */
	printf("Error_Handler\n");
	while(1);
}



#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{ 
	/* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* Infinite loop */
	while (1)
	{
	}
}
#endif /* USE_FULL_ASSERT */

/***** Hana Electronics Industria e Comercio LTDA ****** END OF FILE ****/
