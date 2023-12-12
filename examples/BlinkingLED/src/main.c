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
#include "peripheral_init.h"
#include "ht_crypto.h"
#include "stsafea_core.h"

#define LED_PIN                      GPIO_PIN_5
#define LED_Port                     GPIOA

RNG_HandleTypeDef hrng;

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
	HAL_Init(); 			 // Inicialize the HAL
	MX_GPIO_Init(); 		 // Inicialize and the GPIOs (check for configs also)
	MX_USART1_UART_Init();   // Inicialize UART communication

	printf("Blinking LED project\r\n");

	while (1){

		HAL_GPIO_TogglePin(LED_Port, LED_PIN); // Function to toggle the LED on and off
		HAL_Delay(200); 					   // Delay before the function toggles again in milliseconds
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

/***** Hana Electronics Ind�stria e Com�rcio LTDA ****** END OF FILE ****/
