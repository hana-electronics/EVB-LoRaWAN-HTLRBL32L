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

#include "SensorTemperature.h"

#include <stdio.h>

#include "AdcDriver.h"

#define SENSOR_CHANNEL (0)
#define ADC_RESOLUTION (0.0805664)

void SensorInit(void) {
	AdcDriverInit();
	AdcDriverSelectChannel(SENSOR_CHANNEL);
	AdcDriverStartConversion();
}

float SensorReadTemperature(void) {
	//while (AdcDriverGetStatusConvertion());
	uint16_t adcValue = AdcDriverRead();
	float vout = adcValue * (3.3 / 4096.0);
	float temperature = vout * 10;
	LL_ADC_ClearFlag_EODS(ADC);
	AdcDriverStartConversion();
	return temperature;
}
