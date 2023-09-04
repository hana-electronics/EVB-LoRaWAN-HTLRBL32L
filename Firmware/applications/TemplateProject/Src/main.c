/******************************************************************************
 * Copyright (c) 2022 Fundação CERTI
 * All rights reserved.
 *****************************************************************************/
/**
 *
 * Copyright (c) 2022 HT Micron Semicondutors S.A.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "main.h"

#define LED_Port                      GPIOA
#define LED_Pin                       GPIO_PIN_5


void GpioInit(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	__HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_WritePin(LED_Port, LED_Pin, GPIO_PIN_SET);

	GPIO_InitStruct.Pin = LED_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(LED_Port, &GPIO_InitStruct);
}

int main(void) {

	/* System initialization function */
	if (SystemInit(SYSCLK_64M, BLE_SYSCLK_NONE) != SUCCESS) {
		/* Error during system clock configuration take appropriate action */
		while (1);
	}

	HAL_Init();
	GpioInit();
	MX_USART1_UART_Init();

	printf("HTLRBL32L - Template Project\r\n");

	while (1) {
		HAL_GPIO_TogglePin( LED_Port, LED_Pin);
		HAL_Delay(1000);
	}
}

void Error_Handler(void) {
	printf("Error_Handler!\r\n");
	while (1);
}
