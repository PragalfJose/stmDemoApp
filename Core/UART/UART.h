//********************************* UART **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : UART.h
// Summary  : Uart periphoral realted functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************
#ifndef _UART_H_
#define _UART_H_

//******************************* Include Files *******************************
#include "stm32f1xx_hal.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************

bool uartInit(UART_HandleTypeDef *stUart);
bool uartTransfer(UART_HandleTypeDef *stUart,
		          int8 *pcInputData,
				  uint16 unDataLen,
				  uint32 ulTimeout);

//*********************** Inline Method Implementations ***********************

#endif // _UART_H_
// EOF
