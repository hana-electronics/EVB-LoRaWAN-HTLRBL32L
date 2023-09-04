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

#include "SensorTemperature.h"
#include "AppLoraWanEvents.h"

#define REGION_US915 8

int main(void) {
	/* System initialization function */
	if (SystemInit(SYSCLK_64M, BLE_SYSCLK_NONE) != SUCCESS){
		/* Error during system clock configuration take appropriate action */
		while (1);
	}

	HAL_Init();
	IRQHandler_Config();
	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_SPI1_Init();
	MX_RTC_Init();

	printf("HTLRBL32L - Application-1\r\n");

	SensorInit();
	LORAWAN_init(REGION_US915);
	AppLoraWanEventsInit();

	while (1) {
		LORAWAN_tick();
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

/************************ HT MICRON SEMICONDUCTORS S.A - main.c *****END OF FILE****/
