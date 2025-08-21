//******************************** GPIO ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : GPIO.c
// Summary  : Basic GPIO related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "GPIO.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*********************************.gpioInit.**********************************
//Purpose   : Initialise Gpio ports and pins
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - Initialisation failed
//Notes     : None
//*****************************************************************************
void gpioInit(void)
{

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

//******************************.gpioSetDirInput.******************************
//Purpose   : Set direction of a pin as input
//Inputs    : pstGpioPort - structure pointer to GPIO port
//Inputs    : unGpioPin - GPIO pin number
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
void gpioSetDirInput(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin)
{
	if(NULL != pstGpioPort)
	{
		GPIO_InitTypeDef GPIO_InitStruct = {0};

		GPIO_InitStruct.Pin = unGpioPin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		HAL_GPIO_Init(pstGpioPort, &GPIO_InitStruct);
	}
}

//*****************************.gpioSetDirOutput.******************************
//Purpose   : Set direction of a pin Output
//Inputs    : pstGpioPort - structure pointer to GPIO port
//Inputs    : unGpioPin - GPIO pin number
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
void gpioSetDirOutput(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin)
{
	if(NULL != pstGpioPort)
	{
		GPIO_InitTypeDef GPIO_InitStruct = {0};

		GPIO_InitStruct.Pin = unGpioPin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(pstGpioPort, &GPIO_InitStruct);
	}
}

//********************************.gpioSetPin.*********************************
//Purpose   : SET a Gpio pin
//Inputs    : pstGpioPort - structure pointer to GPIO port
//Inputs    : unGpioPin - GPIO pin number
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
void gpioSetPin(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin)
{
	if(NULL != pstGpioPort)
	{
		HAL_GPIO_WritePin(pstGpioPort, unGpioPin, GPIO_PIN_SET);
	}
}

//*******************************.gpioClearPin.********************************
//Purpose   : CLEAR a Gpio pin
//Inputs    : pstGpioPort - structure pointer to GPIO port
//Inputs    : unGpioPin - GPIO pin number
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
void gpioClearPin(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin)
{
	if(NULL != pstGpioPort)
	{
		HAL_GPIO_WritePin(pstGpioPort, unGpioPin, GPIO_PIN_RESET);
	}
}

//*******************************.gpioTogglePin.*******************************
//Purpose   : Toggle a Gpio pin
//Inputs    : pstGpioPort - structure pointer to GPIO port
//Inputs    : unGpioPin - GPIO pin number
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
void gpioTogglePin(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin)
{
	if(NULL != pstGpioPort)
	{
		HAL_GPIO_TogglePin(pstGpioPort, unGpioPin);
	}
}

//*****************************.gpioGetPinStatus.******************************
//Purpose   : Get status of a GPIO pin
//Inputs    : pstGpioPort - structure pointer to GPIO port
//Inputs    : unGpioPin - GPIO pin number
//Outputs   : None
//Return    : true - Pin status High, false - Pin status LOW
//Notes     : None
//*****************************************************************************
bool gpioGetPinStatus(GPIO_TypeDef *pstGpioPort, uint16 unGpioPin)
{
	bool blReturn = false;

	if(NULL != pstGpioPort)
	{
		if(HAL_GPIO_ReadPin(pstGpioPort, unGpioPin) == GPIO_PIN_SET)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

// EOF
