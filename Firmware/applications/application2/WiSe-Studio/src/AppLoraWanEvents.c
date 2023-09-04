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

#include "AppLoraWanEvents.h"

#include "lora.h"
#include "timeServer.h"
#include "lorawan_setup.h"

#include <stdio.h>

#define APP_TIME_TX_EVENTS   15000		/* </ Timer timeout in milliseconds. */

static TimerEvent_t appTimer;

/*!******************************************************************
 * \fn static void TxLora(const uint8_t* payload)
 * \brief Send a LoRa uplink to a network application.
 *
 * \param[in]  none
 * \param[out] none
 *
 * \retval none
 *******************************************************************/
static void TxLora(const uint8_t* payload);

/*!******************************************************************
 * \fn static void InitTimer(void)
 * \brief Initializes a timer that manage the periodicity of the measurements with the sensors board.
 *
 * \param[in]  none
 * \param[out] none
 *
 * \retval none
 *******************************************************************/
static void InitTimer(void);

/*!******************************************************************
 * \fn static void OnSensorsTimerEvent(void)
 * \brief Sensor timer callback.
 *
 * \param[in]  none
 * \param[out] none
 *
 * \retval none
 *******************************************************************/
static void OnMessageTimerEvent(void *context);

static void OnMessageTimerEvent( void* context ) {
	TimerStart(&appTimer);
}

static void InitTimer(void){
	TimerInit( &appTimer, OnMessageTimerEvent); /* Timer initialization */
    TimerSetValue( &appTimer, APP_TIME_TX_EVENTS);	/* Sets alarm total time */
	TimerStart(&appTimer);	/* Callback call */
}

static void TxLora(const uint8_t* payload) {
	lora_AppData_t appData;
	appData.Buff = (uint8_t*) payload;
	appData.BuffSize = strlen(payload);
	appData.Port = LORAWAN_APP_PORT;
	lorawan_send(&appData);
}

void AppLoraWanEventsInit(void) {
	InitTimer();
}

void AppLoraWanEventsSendUplink(void) {
	TxLora("1");
}
