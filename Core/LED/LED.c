//******************************** LED ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : LED.c
// Summary  : Functions to handle an LED and switch
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "LED.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//****************************.ledGpioDeviceInit.******************************
//Purpose   : Initialise GPIO related devices
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : Initialise LED and Switch and set directions
//*****************************************************************************
bool ledGpioDeviceInit()
{
	bool blReturn = false;

	gpioInit();
	ledLedInit();
	ledSwitchInit();
	blReturn = true;

	return blReturn;

}

//********************************.ledLedInit.*********************************
//Purpose   : Initialise LED pin by setting direction to output
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
bool ledLedInit()
{
	bool blReturn = false;

	gpioSetDirOutput(LED_GPIO_Port, LED_Pin);
	gpioClearPin(LED_GPIO_Port, LED_Pin);
	blReturn = true;

	return blReturn;
}

//******************************.ledSwitchInit.********************************
//Purpose   : Initialise Switch pin by setting direction to input
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
bool ledSwitchInit()
{
	bool blReturn = false;

	gpioSetDirInput(SW1_GPIO_Port, SW1_Pin);
	blReturn = true;

	return blReturn;
}

//********************************.ledLedOn.***********************************
//Purpose   : Turn ON LED
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
bool ledLedOn()
{
	bool blReturn = false;

	gpioSetPin(LED_GPIO_Port, LED_Pin);
	blReturn = true;

	return blReturn;

}

//********************************.ledLedOff.**********************************
//Purpose   : Turn OFF LED
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
bool ledLedOff()
{
	bool blReturn = false;

	gpioClearPin(LED_GPIO_Port, LED_Pin);
	blReturn = true;

	return blReturn;

}

//*******************************.ledLedToggle.********************************
//Purpose   : Toggle state of LED
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - failed
//Notes     : None
//*****************************************************************************
bool ledLedToggle()
{
	bool blReturn = false;

	gpioTogglePin(LED_GPIO_Port, LED_Pin);
	blReturn = true;

	return blReturn;

}

//*****************************.ledSwitchGetValue.*****************************
//Purpose   : Get input value of a switch
//Inputs    : None
//Outputs   : None
//Return    : true - input HIGH, false - input LOW
//Notes     : None
//*****************************************************************************
bool ledSwitchGetValue()
{
	bool blReturn = false;

	if(gpioGetPinStatus(SW1_GPIO_Port, SW1_Pin) == true)
	{
		blReturn = true;
	}

	return blReturn;

}

// EOF
