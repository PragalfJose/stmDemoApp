//********************************* LED ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : LED.h
// Summary  : LED and Switch related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************
#ifndef _LED_H_
#define _LED_H_

//******************************* Include Files *******************************
#include "GPIO.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define SW1_Pin                 GPIO_PIN_13
#define SW1_GPIO_Port           GPIOC
#define SW1_EXTI_IRQn           EXTI15_10_IRQn
#define LED_Pin                 GPIO_PIN_5
#define LED_GPIO_Port           GPIOA
//#define SWO_Pin               GPIO_PIN_3
//#define SWO_GPIO_Port         GPIOB

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool ledGpioDeviceInit();
bool ledLedInit();
bool ledSwitchInit();
bool ledLedOn();
bool ledLedOff();
bool ledLedToggle();
bool ledSwitchGetValue();

//*********************** Inline Method Implementations ***********************

#endif // _LED_H_
// EOF
