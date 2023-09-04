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

#pragma once

/**
 * \enum HT_Fsm
 * \brief Finite State Machine definition.
 */
typedef enum {
	SM_WAIT_FOR_EVENT = 0,										/* </ Wait for an event state. */
	SM_PUSH_BUTTON_HANDLER,										/* </ Push button handler state. */
	SM_SEND_FRAME,												/* </ Send LoRa frame state. */
	SM_RX_LORA													/* </ RX LoRa state. */
} HT_Fsm;

void AppLoraWanEventsInit(void);

void AppLoraWanEventsSendUplink(void);

void HT_PB_SetState(HT_Fsm new_state);
