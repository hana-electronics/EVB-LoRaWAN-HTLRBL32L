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

#include "AdcDriver.h"

#include <stdio.h>

#include "rf_driver_hal_adc.h"

#define ADC_TIMEOUT (100)

static ADC_HandleTypeDef hadc = {0};
static ADC_ConfigChannelTypeDef channel = {0};

Status_t AdcDriverInit(void) {
	__HAL_RCC_ADCDIG_CLK_ENABLE();
	__HAL_RCC_ADCANA_CLK_ENABLE();

	  /* Peripheral clock enable */
	  LL_APB1_EnableClock(LL_APB1_PERIPH_ADCDIG | LL_APB1_PERIPH_ADCANA);

	  LL_ADC_LDOEnable(ADC);

	  /* Enable the ADC */
	  LL_ADC_Enable(ADC);

	  hadc.Instance = ADC;
	  hadc.Init.DataRatio = ADC_DS_RATIO_128;
	  hadc.Init.DataWidth = ADC_DS_DATA_WIDTH_16_BIT;
	  hadc.Init.InvertOutputBitMode = ADC_INVERT_OUTBIT_NONE;
	  hadc.Init.OverrunMode = ADC_NEW_DATA_IS_KEPT;
	  hadc.Init.SampleRate = ADC_SAMPLE_RATE_16;
	  hadc.Init.SamplingMode = ADC_SAMPLING_AT_START;
	  hadc.Init.SequenceLength = ADC_SEQ_LEN_03;

	if (HAL_ADC_Init(&hadc) != HAL_OK) {
		return kErrorInit;
	}

	HAL_ADC_MspInit(&hadc);

	LL_ADC_SetCalibPoint1Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_3V6);
	LL_ADC_SetCalibPointForSinglePos3V6(ADC, LL_ADC_CALIB_POINT_1);
	return kOkay;
}

void AdcDriverSelectChannel(uint8_t number) {
	//PB3 = VINP0
	channel.ChannelType = ADC_CH_VINP0_TO_SINGLE_POSITIVE_INPUT;
	channel.SequenceNumber = ADC_SEQ_POS_01;
	channel.VoltRange = ADC_VIN_RANGE_3V6;
	if(HAL_ADC_ConfigChannel(&hadc, &channel) != HAL_OK) {
		printf("Error adc select channel\r\n");
	}
}

void AdcDriverStartConversion(void) {
	HAL_ADC_Start(&hadc);
}

uint32_t AdcDriverRead(void) {
	return HAL_ADC_GetValue(&hadc);
}

AdcStatus_t AdcDriverGetStatusConvertion(void) {
	return HAL_ADC_PollForConversion(&hadc, ADC_TIMEOUT) != HAL_OK ?
			kAdcDone : kAdcBusy;
}

const ADC_HandleTypeDef* getHadc(void) {
	return &hadc;
}
