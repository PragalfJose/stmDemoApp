//******************************** GPIO ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : GPIO.h
// Summary  : GPIO functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************
#ifndef _GPIO_H_
#define _GPIO_H_

//******************************* Include Files *******************************
#include "stm32f1xx_hal.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
//#define TMS_Pin GPIO_PIN_13
//#define TMS_GPIO_Port GPIOA
//#define TCK_Pin GPIO_PIN_14
//#define TCK_GPIO_Port GPIOA

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
void gpioInit(void);
void gpioSetDirInput(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin);
void gpioSetDirOutput(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin);
void gpioSetPin(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin);
void gpioClearPin(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin);
void gpioTogglePin(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin);
bool gpioGetPinStatus(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin);

//*********************** Inline Method Implementations ***********************

#endif /* _GPIO_H_ */
