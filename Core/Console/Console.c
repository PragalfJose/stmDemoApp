//******************************* Console *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Console.c
// Summary  : Serial Console related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "Console.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
UART_HandleTypeDef stUart2 = {0};

//****************************** Local Functions ******************************

//****************************.consoleSerialInit.******************************
//Purpose   : Initialise UART for Serial Terminal Access
//Inputs    : None
//Outputs   : None
//Return    : true - Serial Console Initialised, false - failed to initialise
//Notes     : None
//*****************************************************************************
bool consoleSerialInit()
{
	bool blReturn = false;

	stUart2.Instance = USART2;
	stUart2.Init.BaudRate = USART_BAUD_RATE;
	stUart2.Init.WordLength = UART_WORDLENGTH_8B;
	stUart2.Init.StopBits = UART_STOPBITS_1;
	stUart2.Init.Parity = UART_PARITY_NONE;
	stUart2.Init.Mode = UART_MODE_TX_RX;
	stUart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	stUart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if(uartInit(&stUart2) == true)
	{
		blReturn = true;
	}

	return blReturn;

}

//******************************.consoleWrite.*********************************
//Purpose   : Print a string using UART
//Inputs    : cInputData - Input data to transfer
//Inputs    : unDataLen - length of data
//Inputs    : ulTimeout - Timeout
//Outputs   : None
//Return    : None
//Notes     : None
//*****************************************************************************
bool consoleSerialPrint(int8 *pcInputData, uint16 unDataLen, uint32 ulTimeout)
{
	bool blReturn = false;

	if((pcInputData != NULL) && unDataLen != ZERO)
	{
		if(uartTransfer(&stUart2, pcInputData, unDataLen, ulTimeout) == true)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

// EOF
