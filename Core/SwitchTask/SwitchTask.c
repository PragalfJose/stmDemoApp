//***************************** SwitchTask ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : SwitchTask.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 19/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "SwitchTask.h"
//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
int8 pcSwitchTaskLog[STR_LEN] = {0};
static int32 lKeyPressCount = 0;

//****************************** Local Functions ******************************

//****************************.switchTaskSwitch.*******************************
//Purpose   : Function for Switch thread
//Inputs    : None
//Outputs   : Sends Message to Blink thread when a switch is pressed
//Return    : None
//Notes     : None
//*****************************************************************************
void switchTaskSwitch(void *pvParameter)
{
	TASKPARAM stTaskParameter = {0};
	MESSAGE stMessageData = {0};
	ACKNOWLEDGE stAckData = {0};
//	uint32 ulMessageCount = 0;
	uint32 ulFreeSpace = 0;

	memcpy(&stTaskParameter, (TASKPARAM*)pvParameter, sizeof(TASKPARAM));
	memset(pcSwitchTaskLog, 0, sizeof(pcSwitchTaskLog));
	sprintf(pcSwitchTaskLog,
			"[%s] : Switch Task Started\r\n",
			__func__);
	consoleSerialPrint(pcSwitchTaskLog, strlen(pcSwitchTaskLog), TX_TIMEOUT);

	for(;;)
	{
		if(ledSwitchGetValue() == false)
		{
			while(ledSwitchGetValue() == false)
			{
			}

			lKeyPressCount++;
			if(mqMQueueFreeSpace(stTaskParameter.pmqMQueueID,
					             &ulFreeSpace) == true)
			{
				memset(&stMessageData, 0, sizeof(MESSAGE));
				sprintf(stMessageData.ucUUID, "%04d", lKeyPressCount);
				if(lKeyPressCount % 5 != ZERO)
				{
					stMessageData.ucCommand = 0X01;
				}
				sprintf(stMessageData.ucData, "-GET");
				if(mqMQueuePutData(stTaskParameter.pmqMQueueID,
								   &stMessageData,
								   0,
								   MQ_TIMEOUT) != true)
				{
					mutexMutexAcquire(stTaskParameter.pmutMutexID,
									  MUTEX_TIMEOUT);
					threadPrintError(__func__, ERR_Q_SEND_FAILED);
					mutexMutexRelease(stTaskParameter.pmutMutexID);
				}
				else
				{
					mutexMutexAcquire(stTaskParameter.pmutMutexID,
									  MUTEX_TIMEOUT);
					threadPrintError(__func__, ERR_MSG_OK);
					mutexMutexRelease(stTaskParameter.pmutMutexID);
				}
			}
			else
			{
				mutexMutexAcquire(stTaskParameter.pmutMutexID,
								  MUTEX_TIMEOUT);
				threadPrintError(__func__, ERR_Q_FULL);
				mutexMutexRelease(stTaskParameter.pmutMutexID);
			}

			semSemaphoreRelease(stTaskParameter.psemSWSemaphoreID);
			semSemaphoreAcquire(stTaskParameter.psemMSSemaphoreID, osWaitForever);
			memset(&stAckData, 0, sizeof(ACKNOWLEDGE));
			mqMQueueGetData(stTaskParameter.pmqMQueueID,
					        &stAckData,
							0,
							MQ_TIMEOUT);
			mutexMutexAcquire(stTaskParameter.pmutMutexID,
							  MUTEX_TIMEOUT);
			if(threadProcessAcknowledge(__func__, stAckData) != true)
			{
				threadPrintError(__func__, ERR_ACK_ERR);
			}

			mutexMutexRelease(stTaskParameter.pmutMutexID);
		}

		osDelay(1);
	}
}

// EOF
