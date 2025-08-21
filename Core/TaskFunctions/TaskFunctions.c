//******************************** Name ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Name.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "TaskFunctions.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//****************************.taskCreateTask.*********************************
//Purpose   : Create a Task using given parameters
//Inputs    : None
//Outputs   : Created Task handle
//Return    : true - Task created, false - failed to create task
//Notes     : None
//*****************************************************************************
bool taskCreateTask(TASKS *stTask,
		            void *pvTaskParameter,
					osThreadId_t *pTaskHandle)
{
	bool blReturn = false;

	if(NULL != stTask)
	{
		const osThreadAttr_t stTask_attributes =
			{
			  .name       = (int8*)stTask->pucTaskName,
			  .stack_size = stTask->ulStackSize,
			  .priority   = stTask->ucTaskPriority,
			};
		*pTaskHandle = osThreadNew(stTask->pTaskFunction,
				                  pvTaskParameter,
								  &stTask_attributes);
		if(NULL != *pTaskHandle)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

// EOF
