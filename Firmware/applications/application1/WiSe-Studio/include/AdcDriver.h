/*
  _    _ _______   __  __ _____ _____ _____   ____  _   _
 | |  | |__   __| |  \/  |_   _/ ____|  __ \ / __ \| \ | |
 | |__| |  | |    | \  / | | || |    | |__) | |  | |  \| |
 |  __  |  | |    | |\/| | | || |    |  _  /| |  | | . ` |
 | |  | |  | |    | |  | |_| || |____| | \ \| |__| | |\  |
 |_|  |_|  |_|    |_|  |_|_____\_____|_|  \_\\____/|_| \_|
 =================== Advanced R&D ========================

*/

#pragma once

#include <stdint.h>

#include <rf_driver_hal.h>

typedef enum {
	kOkay,
	kErrorInit,
	kInvalidParameter
} Status_t;

typedef enum {
	kAdcDone,
	kAdcBusy
} AdcStatus_t;

Status_t AdcDriverInit(void);

uint32_t AdcDriverRead(void);

void AdcDriverSelectChannel(uint8_t number);

void AdcDriverStartConversion(void);

AdcStatus_t AdcDriverGetStatusConvertion(void);

const ADC_HandleTypeDef* getHadc(void);
