//********************************* Name **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Name.h
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************
#ifndef _TASK_H_
#define _TASK_H_

//******************************* Include Files *******************************
#include "cmsis_os.h"
#include "Common.h"

//******************************* Global Types ********************************
typedef struct _TASKS_
{
	uint8 *pucTaskName;
	uint32 ulStackSize;
	uint8 ucTaskPriority;
	void (*pTaskFunction)(void *pvTaskParameter);
}TASKS;

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool taskCreateTask(TASKS *stTask,
		            void *pvTaskParameter,
					osThreadId_t *pTaskHandle);

//*********************** Inline Method Implementations ***********************

#endif // _TASK_H_
// EOF
