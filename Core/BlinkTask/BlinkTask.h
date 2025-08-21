//******************************* BlinkTask ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : BlinkTask.h
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 19/08/2025
//
//*****************************************************************************
#ifndef _BLINKTASK_H_
#define _BLINKTASK_H_

//******************************* Include Files *******************************
#include "cmsis_os2.h"
#include "ThreadFunction.h"
#include "LED.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
void blinkTaskBlink(void *pvParameter);

//*********************** Inline Method Implementations ***********************

#endif // _BLINKTASK_H_
// EOF
