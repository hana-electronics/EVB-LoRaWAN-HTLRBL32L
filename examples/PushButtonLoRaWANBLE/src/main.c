/*
 Copyright (c) 2023 Hana Electronics Ind�stria e Com�rcio LTDA

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

/*LoRaWAN related configs -> lorawandefines.h
 *
 * LoRaWAN functions 	  -> loranwan_setup.c
 *
 * DON'T FORGET:
 *
 * LORAWAN_TICK() on the while(1) loop if you're gonna use LoRa
 *
 * If you're gonna use BLE put the function BLE_STACK_Tick() in the loop;
 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	uint8_t status_code = 0;

	/* System initialization function */
	if (SystemInit(SYSCLK_64M, BLE_SYSCLK_32M) != SUCCESS) {
		/* Error during system clock configuration take appropriate action */
		while(1);
	}
	HAL_Init();
	IRQHandler_Config();
	HAL_NVIC_DisableIRQ(GPIOA_IRQn);
	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_SPI1_Init();
	MX_I2C2_Init();
	MX_CRC_Init();
	MX_RTC_Init();


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
	
	while (1){

	}
}

PowerSaveLevels App_PowerSaveLevel_Check(PowerSaveLevels level) {
	return POWER_SAVE_LEVEL_STOP_NOTIMER;
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

/***** Hana Electronics Ind�stria e Com�rcio LTDA ****** END OF FILE ****/
