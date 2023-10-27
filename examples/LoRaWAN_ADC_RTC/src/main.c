
/*******************************************************
 * File Name        : main.c
 * Author             : Christian Lehmen
 * Date               : 20-November-2020
 * Description      : Certification Firmware - LoRaWAN 1.0.2
 *********************************************************/

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
#include "lora-test.h"
#include "LoRaMac.h"
#include "hal_wrappers.h"
#include "ht_crypto.h"
#include "stsafea_core.h"
#include "rf_driver_hal_gpio.h"
#include "adcSetup.h"

RNG_HandleTypeDef hrng;
lora_AppData_t package;
uint16_t VPB1Returned;
ulong CheckerDelayHelper; 					//Variable to help with the non-blocking delay
uint32_t CheckerTime;

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
	CheckerTime 	 	= 10000; 				//10 seconds to start a new measure

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
	adc_config_INIT();

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

	// Performs the calculation of interruptions using the microcontroller clock after RTC initialization
	CheckerDelayHelper = CheckerTime + HAL_GetTick();

	// Initializes and configures LoRaWAN settings
	LORAWAN_init(DEFAULT_REGION);

	while (1) {

	    // This function should always remain in the main loop to ensure that the LoRaWAN machine is always running
	    LORAWAN_tick();

	    if (HAL_GetTick() >= CheckerDelayHelper) {
	        CheckerDelayHelper = CheckerTime + HAL_GetTick();

	        // Reads the ADC value from GPIO_B1 port
	        VPB1Returned = pin_voltage_measure(PB1_CHANNEL);

	        // Prints the analog value read on port PB1 to the serial output
	        printf("\n\nVoltage at port PB1: %d mV\n\n", VPB1Returned);

	        // Toggles the state of the LED on GPIO_A5
	        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	        // Constructs the package to be sent via LoRaWAN (LoRaWAN settings found in lorawandefinas.h file)
	        package.Buff = (uint8_t*)"Hello_World!";
	        package.BuffSize = strlen((const char*)package.Buff);
	        package.Port = LORAWAN_APP_PORT;

	        // Sends the LoRaWAN package
	        lorawan_send(&package);
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
	F
	/* Infinite loop */
	while (1)
	{
	}
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
