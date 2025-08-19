//******************************* Console *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Console.h
// Summary  : Serial console related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************
#ifndef _CONSOLE_CONSOLE_H_
#define _CONSOLE_CONSOLE_H_

//******************************* Include Files *******************************
#include "UART.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define USART_TX_Pin            GPIO_PIN_2
#define USART_TX_GPIO_Port      GPIOA
#define USART_RX_Pin            GPIO_PIN_3
#define USART_RX_GPIO_Port      GPIOA
#define USART_BAUD_RATE         115200

//***************************** Global Variables ******************************
#define TX_TIMEOUT              100

//**************************** Function Declarations **************************
bool consoleSerialInit();
bool consoleSerialPrint(int8 *pcInputData, uint16 unDataLen, uint32 ulTimeout);

//*********************** Inline Method Implementations ***********************

#endif // _CONSOLE_CONSOLE_H_
// EOF
