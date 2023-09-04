/*
  _    _ _______   __  __ _____ _____ _____   ____  _   _
 | |  | |__   __| |  \/  |_   _/ ____|  __ \ / __ \| \ | |
 | |__| |  | |    | \  / | | || |    | |__) | |  | |  \| |
 |  __  |  | |    | |\/| | | || |    |  _  /| |  | | . ` |
 | |  | |  | |    | |  | |_| || |____| | \ \| |__| | |\  |
 |_|  |_|  |_|    |_|  |_|_____\_____|_|  \_\\____/|_| \_|
 =================== Advanced R&D ========================

*/

/*!
 * \file main.h
 * \brief HTLRBL32L - LoRaWAN Push Button main file.
 * \author HT Micron Advanced R&D
 * \link support_iot@htmicron.com.br
 * \version 1.0
 * \date January 05, 2022
 */
/******************************************************************************
 * Copyright (c) 2022 Fundação CERTI
 * All rights reserved.
 *****************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/
#include "rf_driver_hal.h"
#include "rf_driver_ll_rtc.h"
#include "utils.h"
#include "uart.h"
#include "rtc.h"
#include "gpio.h"

#include "radio.h"
#include "hal_wrappers.h"

#include "ble_const.h"
#include "bluenrg_lp_stack.h"
#include "rf_driver_hal_power_manager.h"
#include "rf_driver_hal_vtimer.h"

#include "HT_push_button_cfg.h"
#include "bleplat.h"
#include "nvm_db.h"

#include "ble_controller.h"
#include "pka_manager.h"
#include "rng_manager.h"
#include "aes_manager.h"
#include "utils.h"

#include "HT_ble_api.h"
#include "HT_gatt_db.h"


/* Private includes ----------------------------------------------------------*/
#include <stdio.h>

#define LED_Port                      GPIOA
#define LED_Pin                       GPIO_PIN_5

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

void ModulesTick(void);
void ModulesInit(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ HT MICRON SEMICONDUCTORS S.A - main.h *****END OF FILE****/
