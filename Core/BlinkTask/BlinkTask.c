//******************************* BlinkTask ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : BlinkTask.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 19/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "BlinkTask.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
int8 pcBlinkTaskLog[STR_LEN] = {0};

//****************************** Local Functions ******************************

//*****************************.blinkTaskBlink.********************************
//Purpose   : Function for Blink thread
//Inputs    : None
//Outputs   : Changes the state of LED according to message from Switch thread
//Return    : None
//Notes     : None
//*****************************************************************************
void blinkTaskBlink(void *pvParameter)
{
	TASKPARAM stTaskParameter = {0};
	MESSAGE stMessageData = {0};
	ACKNOWLEDGE stAckData = {0};
	uint32 ulMessageCount = 0;
//	uint32 ulFreeSpace = 0;

	memcpy(&stTaskParameter, (TASKPARAM*)pvParameter, sizeof(TASKPARAM));

	memset(pcBlinkTaskLog, 0, sizeof(pcBlinkTaskLog));
	sprintf(pcBlinkTaskLog,
			"[%s ] : Blink Task Started\r\n",
			__func__);
	consoleSerialPrint(pcBlinkTaskLog, strlen(pcBlinkTaskLog), TX_TIMEOUT);
	for(;;)
	{
		if(semSemaphoreAcquire(stTaskParameter.psemSWSemaphoreID,
				               SEM_TIMEOUT) == true)
		{
			if(mqMQueueDataCount(stTaskParameter.pmqMQueueID,
					             &ulMessageCount) == true)
			{
				memset(&stMessageData, 0, sizeof(MESSAGE));
				if(mqMQueueGetData(stTaskParameter.pmqMQueueID,
						           &stMessageData,
								   0,
								   MQ_TIMEOUT) == true)
				{
					mutexMutexAcquire(stTaskParameter.pmutMutexID,
							          osWaitForever);
					if(threadProcessMessage(__func__, &stMessageData) == true)
					{
						ledLedToggle();
						memset(&stAckData, 0, sizeof(ACKNOWLEDGE));
						strcpy(stAckData.ucUUID,stMessageData.ucUUID);
						stAckData.ucCommand = 0X02;
						stAckData.ucState = 0X00;
						sprintf(stAckData.ucData, "-SET");
					}
					else
					{
						memset(&stAckData, 0, sizeof(ACKNOWLEDGE));
						strcpy(stAckData.ucUUID,stMessageData.ucUUID);
						stAckData.ucCommand = 0X00;
						stAckData.ucState = 0X01;
						sprintf(stAckData.ucData, "-ERR");
						threadPrintError(__func__, ERR_MSG_WRONG_CMND);
					}

					mutexMutexRelease(stTaskParameter.pmutMutexID);
					if(mqMQueuePutData(stTaskParameter.pmqMQueueID,
							        &stAckData,
									0,
									MQ_TIMEOUT) == true)
					{
						mutexMutexAcquire(stTaskParameter.pmutMutexID,
										  MUTEX_TIMEOUT);
						threadPrintError(__func__, ERR_ACK_OK);
						mutexMutexRelease(stTaskParameter.pmutMutexID);
					}
				}
				else
				{
					mutexMutexAcquire(stTaskParameter.pmutMutexID,
									  MUTEX_TIMEOUT);
					threadPrintError(__func__, ERR_Q_REC_FAILED);
					mutexMutexRelease(stTaskParameter.pmutMutexID);
				}
			}
			else
			{
				mutexMutexAcquire(stTaskParameter.pmutMutexID,
								  MUTEX_TIMEOUT);
				threadPrintError(__func__, ERR_Q_EMPTY);
				mutexMutexRelease(stTaskParameter.pmutMutexID);
			}

			semSemaphoreRelease(stTaskParameter.psemMSSemaphoreID);
		}

		osDelay(1);
	}
}

// EOF
