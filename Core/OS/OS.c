//********************************* OS ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : OS.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "OS.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
TASKS stTask[TASK_COUNT] =
{
		{(uint8*)"SwitchTask", STACK_SIZE*4, PRIORITY_LVL1, switchTaskSwitch},
		{(uint8*)"BlinkTask",  STACK_SIZE*4, PRIORITY_LVL1, blinkTaskBlink}
};
osThreadId_t posSwitchTread = NULL;
osThreadId_t posBlinkTread = NULL;
osSemaphoreId_t psemSwitchSemaphore = NULL;
osSemaphoreId_t psemMessageSemaphore = NULL;
osMutexId_t pmutConsoleMutex = NULL;
osMessageQueueId_t pmqMessageQueue = NULL;
int8 pcOSLog[STR_LEN] = {0};
static TASKPARAM stTaskParameter = {0};

//****************************** Local Functions ******************************

//*********************************.osInit.************************************
//Purpose   : Initialise RTOS OS Kernel
//Inputs    : None
//Outputs   : None
//Return    : true - Kernel initialized, false - failed to initialize Kernel
//Notes     : None
//*****************************************************************************
bool osInit()
{
	bool blReturn = false;

	if(osKernelInitialize() == osOK)
	{
		blReturn = false;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Kernal Init failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//********************************.osStart.************************************
//Purpose   : Start OS scheduler
//Inputs    : None
//Outputs   : Created tasks will run after this function.
//Return    : true - Scheduler started, false - failed to start scheduler
//Notes     : None
//*****************************************************************************
bool osStart()
{
	bool blReturn = false;
	if(osKernelStart() == osOK)
	{
		blReturn = true;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Kernal Start failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//**************************.osCreateSwitchTask.*******************************
//Purpose   : Create Switch Task
//Inputs    : None
//Outputs   : Created Task handle
//Return    : true - Task created, false - failed to create task
//Notes     : None
//*****************************************************************************
bool osCreateSwitchTask()
{
	bool blReturn = false;

	stTaskParameter.psemSWSemaphoreID = psemSwitchSemaphore;
	stTaskParameter.psemMSSemaphoreID = psemMessageSemaphore;
	stTaskParameter.pmutMutexID = pmutConsoleMutex;
	stTaskParameter.pmqMQueueID = pmqMessageQueue;

	if(taskCreateTask(&stTask[0], &stTaskParameter, &posSwitchTread) == true)
	{
		blReturn =true;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Switch Task Creation failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//**************************.osCreateBlinkTask.********************************
//Purpose   : Create Blink Task
//Inputs    : None
//Outputs   : Created Task handle
//Return    : true - Task created, false - failed to create task
//Notes     : None
//*****************************************************************************
bool osCreateBlinkTask()
{
	bool blReturn = false;

	stTaskParameter.psemSWSemaphoreID = psemSwitchSemaphore;
	stTaskParameter.psemMSSemaphoreID = psemMessageSemaphore;
	stTaskParameter.pmutMutexID = pmutConsoleMutex;
	stTaskParameter.pmqMQueueID = pmqMessageQueue;

	if(taskCreateTask(&stTask[1], &stTaskParameter, &posBlinkTread) == true)
	{
		blReturn = true;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Blink Task Creation failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//****************************.osCreateMutex.**********************************
//Purpose   : Create Mutex
//Inputs    : None
//Outputs   : Created Mutex address
//Return    : true - Mutex created, false - failed to create Mutex
//Notes     : None
//*****************************************************************************
bool osCreateMutex()
{
	bool blReturn = false;
	osMutexAttr_t stMutexAttributs =
	{
			.name = "ConsoleMutex"
	};

	if(mutexMutexCreate(&pmutConsoleMutex, &stMutexAttributs) == true)
	{
		blReturn = true;
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Mutex Created - %s\r\n",
				GET_VAR_NAME(pcOSLog),
				stMutexAttributs.name);
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Mutex Creation failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//****************************.osDeleteMutex.**********************************
//Purpose   : Delete Mutex
//Inputs    : None
//Outputs   : None
//Return    : true - Mutex deleted, false - failed to delete Mutex
//Notes     : None
//*****************************************************************************
bool osDeleteMutex()
{
	bool blReturn = false;

	if(mutexMutexDelete(pmutConsoleMutex) == true)
	{
		blReturn = true;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Mutex Deletion failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//***********************.osCreateSwitchSemaphore.*****************************
//Purpose   : Create Switch Semaphore
//Inputs    : None
//Outputs   : Created Semaphore address
//Return    : true - Semaphore created, false - failed to create Semaphore
//Notes     : None
//*****************************************************************************
bool osCreateSwitchSemaphore()
{
	bool blReturn = false;
	osSemaphoreAttr_t stSemAttributes =
	{
	  .name = "SwitchTaskSem"
	};

	if(semSemaphoreCreate(&psemSwitchSemaphore, 1, 0, &stSemAttributes) == true)
	{
		blReturn = true;
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Semaphore Created - %s\r\n",
				GET_VAR_NAME(pcOSLog),
				stSemAttributes.name);
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Switch Semaphore Creation failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//***********************.osCreateMessageSemaphore.****************************
//Purpose   : Create Message Semaphore
//Inputs    : None
//Outputs   : Created Semaphore address
//Return    : true - Semaphore created, false - failed to create Semaphore
//Notes     : None
//*****************************************************************************
bool osCreateMessageSemaphore()
{
	bool blReturn = false;
	osSemaphoreAttr_t stSemAttributes =
	{
	  .name = "BlinkTaskSem"
	};

	if(semSemaphoreCreate(&psemMessageSemaphore, 1, 0, &stSemAttributes) == true)
	{
		blReturn = true;
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Semaphore Created - %s\r\n",
				GET_VAR_NAME(pcOSLog),
				stSemAttributes.name);
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Message Semaphore Creation failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//***********************.osDeleteSwitchSemaphore.*****************************
//Purpose   : Delete Switch Semaphore
//Inputs    : None
//Outputs   : None
//Return    : true - Semaphore deleted, false - failed to delete semaphore
//Notes     : None
//*****************************************************************************
bool osDeleteSwitchSemaphore()
{
	bool blReturn = false;

	if(semSemaphoreDelete(psemSwitchSemaphore) == true)
	{
		blReturn = true;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Semaphore Delete failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//***********************.osDeleteMessageSemaphore.****************************
//Purpose   : Delete Switch Semaphore
//Inputs    : None
//Outputs   : None
//Return    : true - Semaphore deleted, false - failed to delete semaphore
//Notes     : None
//*****************************************************************************
bool osDeleteMessageSemaphore()
{
	bool blReturn = false;

	if(semSemaphoreDelete(psemMessageSemaphore) == true)
	{
		blReturn = true;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Semaphore Delete failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//**************************.osCreateSemaphore.********************************
//Purpose   : Create Semaphore
//Inputs    : None
//Outputs   : Created Semaphore address
//Return    : true - Semaphore created, false - failed to create Semaphore
//Notes     : None
//*****************************************************************************
bool osCreateMQueue()
{
	bool blReturn = false;
	osMessageQueueAttr_t stMQAttributes =
	{
	  .name = "MessageQueue"
	};

	if(mqMQueueOpen(&pmqMessageQueue,
	                MSG_COUNT,
			        MSG_SIZE,
			        &stMQAttributes) == true)
	{
		blReturn = true;
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Message Queue Created - %s\r\n",
				GET_VAR_NAME(pcOSLog),
				stMQAttributes.name);
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Message Queue Creation failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

//**************************.osCreateSemaphore.********************************
//Purpose   : Create Semaphore
//Inputs    : None
//Outputs   : Created Semaphore address
//Return    : true - Semaphore created, false - failed to create Semaphore
//Notes     : None
//*****************************************************************************
bool osDeleteMQueue()
{
	bool blReturn = false;

	if(mqMQueueClose(pmqMessageQueue) == true)
	{
		blReturn = true;
	}
	else
	{
		memset(pcOSLog, 0, sizeof(pcOSLog));
		sprintf(pcOSLog,
				"[%s] : Message Queue Delete failed\r\n",
				GET_VAR_NAME(pcOSLog));
		consoleSerialPrint(pcOSLog, strlen(pcOSLog), TX_TIMEOUT);
	}

	return blReturn;

}

// EOF
