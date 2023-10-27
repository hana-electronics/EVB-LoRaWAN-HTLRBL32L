
#include "adcSetup.h"
#include "main.h"

ADC_HandleTypeDef adc_handle;
ADC_ConfigChannelTypeDef xChannel; // Configures one channel for the measures. On each measure, must set the input type.


void adc_config_INIT(void){

	GPIO_InitTypeDef  GPIO_InitStruct;

    /* Parameters for ADC initialization */
    __HAL_RCC_ADCDIG_CLK_ENABLE();
    __HAL_RCC_ADCANA_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();


	/* Configure ADC PINs */
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode  = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


	/* Enable the ADC peripheral */
	HAL_ADC_StructInit(&adc_handle);
	adc_handle.Init.DataRatio = USER_RATIO;
	adc_handle.Init.DataWidth = USER_DATAWIDTH;
	adc_handle.Init.SampleRate = USER_SAMPLERATE;
	adc_handle.Init.SequenceLength = ADC_SEQ_LEN_01; // One measure each time.
	adc_handle.Init.SamplingMode = ADC_SAMPLING_AT_START;

  if (HAL_ADC_Init(&adc_handle) != HAL_OK)
   {
     Error_Handler();
   }
}


float batt_measure(void)
{
	uint32_t nVBattRawVal = 0;
	float adcValueBatt = 0.0;
	int8_t offset_vinm0 = 0;

	/* Set the input channel */
	  xChannel.ChannelType = ADC_CH_BATTERY_LEVEL_DETECTOR; //Set the input type on this measure.
	  xChannel.SequenceNumber = ADC_SEQ_POS_01;
	  xChannel.VoltRange = ADC_VIN_RANGE_3V6;

	  if (HAL_ADC_ConfigChannel(&adc_handle, &xChannel)!= HAL_OK) {
	          Error_Handler();
	        }

	  /* Set the GAIN */
	  if(LL_ADC_GET_CALIB_GAIN_FOR_VINMX_3V6() != 0xFFF) {
	    LL_ADC_SetCalibPoint1Gain(ADC, LL_ADC_GET_CALIB_GAIN_FOR_VINMX_3V6() );
	    offset_vinm0 = LL_ADC_GET_CALIB_OFFSET_FOR_VINMX_3V6();
		{
	      LL_ADC_SetCalibPoint1Offset(ADC, offset_vinm0);
	      offset_vinm0 = 0;
	    }
	  }
	  else {
		LL_ADC_SetCalibPoint1Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_3V6);
	  }

    /* Start ADC conversion */
    HAL_ADC_Start(&adc_handle);

	/* Check the ADC flag End Of Down Sampler conversion */
	while( HAL_ADC_PollForConversion(&adc_handle, 100) != HAL_OK);

	/* Get the battery raw value from the Down Sampler */
	nVBattRawVal = HAL_ADC_GetValue(&adc_handle);
	HAL_ADC_Stop(&adc_handle);
	adcValueBatt = (float)LL_ADC_GetADCConvertedValueBatt(adc_handle.Instance, nVBattRawVal, USER_DATAWIDTH, offset_vinm0);

	return adcValueBatt;
}


float cpu_temp_measure(void)
{
	xChannel.ChannelType = ADC_CH_TEMPERATURE_SENSOR;
	xChannel.SequenceNumber = ADC_SEQ_POS_01;
	xChannel.VoltRange = ADC_VIN_RANGE_1V2;

	 if (HAL_ADC_ConfigChannel(&adc_handle, &xChannel)!= HAL_OK) {
	    Error_Handler();
	  }
    if(LL_ADC_GET_CALIB_GAIN_FOR_VINPX_1V2() != 0xFFF) {
    	LL_ADC_SetCalibPoint2Gain(ADC, LL_ADC_GET_CALIB_GAIN_FOR_VINPX_1V2() );
    }
    else {
    	LL_ADC_SetCalibPoint2Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_1V2);
    }
    LL_ADC_SetCalibPointForSinglePos1V2(ADC, LL_ADC_CALIB_POINT_2);

    uint32_t TEMPrawVAL = 0;
	float adcValueTEMP = 0.0;

    /* Start ADC conversion */
    HAL_ADC_Start(&adc_handle);
	/* Check the ADC flag End Of Down Sampler conversion */
	while( HAL_ADC_PollForConversion(&adc_handle, 100) != HAL_OK);

	/* Get the battery raw value from the Down Sampler */
	TEMPrawVAL = HAL_ADC_GetValue(&adc_handle);
	HAL_ADC_Stop(&adc_handle);
	adcValueTEMP = (float)LL_ADC_GetADCConvertedValueTemp(adc_handle.Instance, TEMPrawVAL, USER_DATAWIDTH)/100.0;

	return adcValueTEMP;
}

uint16_t pin_voltage_measure(uint8_t channel)
{
	uint8_t offset_vinp0;
	uint32_t VPinRawVal = 0;
	uint16_t adcValuePin = 0.0;

	  xChannel.ChannelType = channel; // Set the input type on this measure.
	  xChannel.SequenceNumber = ADC_SEQ_POS_01;
	  xChannel.VoltRange = ADC_VIN_RANGE_3V6;

	  if (HAL_ADC_ConfigChannel(&adc_handle, &xChannel)!= HAL_OK) {
	          Error_Handler();
	        }

	  /* Set the GAIN */
	    if(LL_ADC_GET_CALIB_GAIN_FOR_VINPX_3V6() != 0xFFF) {
	      LL_ADC_SetCalibPoint1Gain(ADC, LL_ADC_GET_CALIB_GAIN_FOR_VINPX_3V6() );
	      offset_vinp0 = LL_ADC_GET_CALIB_OFFSET_FOR_VINPX_3V6();
	      {
	        LL_ADC_SetCalibPoint1Offset(ADC, offset_vinp0);
	        offset_vinp0 = 0;
	      }
	    }
	    else {
	      LL_ADC_SetCalibPoint1Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_3V6);
	    }
	    LL_ADC_SetCalibPointForSinglePos3V6(ADC, LL_ADC_CALIB_POINT_1);

    /* Start ADC conversion */
    HAL_ADC_Start(&adc_handle);

	/* Check the ADC flag End Of Down Sampler conversion */
	while( HAL_ADC_PollForConversion(&adc_handle, 100) != HAL_OK);

	/* Get the battery raw value from the Down Sampler */
	VPinRawVal = HAL_ADC_GetValue(&adc_handle);
	HAL_ADC_Stop(&adc_handle);
	adcValuePin = (float)LL_ADC_GetADCConvertedValueSingle(adc_handle.Instance, VPinRawVal, LL_ADC_VIN_RANGE_3V6, USER_DATAWIDTH, offset_vinp0);

	/* Printout the output value */
//	printf("\n\nPin voltage %d.%03d mV\r\n\n", PRINT_INT(adcValuePin),PRINT_FLOAT(adcValuePin));
	return adcValuePin;
}
