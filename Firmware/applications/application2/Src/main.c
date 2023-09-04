/*
  _    _ _______   __  __ _____ _____ _____   ____  _   _
 | |  | |__   __| |  \/  |_   _/ ____|  __ \ / __ \| \ | |
 | |__| |  | |    | \  / | | || |    | |__) | |  | |  \| |
 |  __  |  | |    | |\/| | | || |    |  _  /| |  | | . ` |
 | |  | |  | |    | |  | |_| || |____| | \ \| |__| | |\  |
 |_|  |_|  |_|    |_|  |_|_____\_____|_|  \_\\____/|_| \_|
 =================== Advanced R&D ========================

*/
/******************************************************************************
 * Copyright (c) 2022 Fundação CERTI
 * All rights reserved.
 *****************************************************************************/

#include "main.h"

#include "AppLoraWanEvents.h"

#define REGION_US915 8

#define LED_Port                      GPIOA
#define LED_Pin                       GPIO_PIN_5

static void AppGpioInit(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	__HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_WritePin(LED_Port, LED_Pin, GPIO_PIN_SET);

	    /* Configure PA4 pin as input floating */
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LED_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(LED_Port, &GPIO_InitStruct);
}

int main(void) {
	/* System initialization function */
	if (SystemInit(SYSCLK_64M, BLE_SYSCLK_NONE) != SUCCESS){
		/* Error during system clock configuration take appropriate action */
		while (1);
	}

	HAL_Init();
	IRQHandler_Config();
	MX_GPIO_Init();
	AppGpioInit();
	MX_USART1_UART_Init();
	MX_SPI1_Init();
	MX_RTC_Init();

	printf("HTLRBL32L - Application-2\r\n");

	LORAWAN_init(REGION_US915);
	AppLoraWanEventsInit();

	while (1) {
		LORAWAN_tick();
		if(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)) {
		  HAL_Delay(160);
			printf("--------> Button pressed\r\n");
			AppLoraWanEventsSendUplink();
		}
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {

	/* User can add his own implementation to report the HAL error return state */
	printf("Error_Handler!\n");
	while (1);
}
