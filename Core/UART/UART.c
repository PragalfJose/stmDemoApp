//******************************** UART ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : UART.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "UART.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
uint8 pucUartLog[STR_LEN] = {0};

//****************************** Local Functions ******************************

//*******************************.uartInit.************************************
//Purpose   : Initialise a UART Port
//Inputs    : stUart - structure pointer to Uart instance
//Outputs   : None
//Return    : True - UART initialised, false - Initialisation failed
//Notes     : None
//*****************************************************************************
bool uartInit(UART_HandleTypeDef *stUart)
{
	bool blReturn = false;

	if(stUart != NULL)
	{
		if (HAL_UART_Init(stUart) == HAL_OK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//*****************************.uartTransfer.**********************************
//Purpose   : Transfer a data through UART
//Inputs    : stUart - structure pointer to Uart instance
//Inputs    : cInputData - Input data to transfer
//Inputs    : unDataLen - length of data
//Inputs    : ulTimeout - Timeout
//Outputs   : None
//Return    : None
//Notes     : None
//*****************************************************************************
bool uartTransfer(UART_HandleTypeDef *stUart,
		          int8 *pcInputData,
				  uint16 unDataLen,
				  uint32 ulTimeout)
{
	bool blReturn = false;

	if((stUart != NULL) && (pcInputData != NULL) && (unDataLen != ZERO))
	{
		HAL_StatusTypeDef eStatus = 0;
		eStatus = HAL_UART_Transmit(stUart,
				 (uint8*)pcInputData,
	             unDataLen,
				 ulTimeout);
		if(eStatus == HAL_OK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

// EOF
