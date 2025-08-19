//**************************** ThreadFunction *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : ThreadFunction.h
// Summary  : None
// Note     : Function defenition for threads
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************
#ifndef _THREAD_FUNCTION_H_
#define _THREAD_FUNCTION_H_

//******************************* Include Files *******************************
#include "cmsis_os2.h"
#include "Semaphore.h"
#include "Mutex.h"
#include "MQueue.h"
#include "Console.h"
#include "Common.h"

//******************************* Global Types ********************************
typedef struct _TASKPARAM_
{
	osSemaphoreId_t psemSWSemaphoreID;
	osSemaphoreId_t psemMSSemaphoreID;
	osMutexId_t pmutMutexID;
	osMessageQueueId_t pmqMQueueID;
}TASKPARAM;

typedef struct _MESSAGE_
{
	int8 ucUUID[5];
	uint8 ucCommand;
	int8 ucData[5];
	uint8 RESERVED[53];
}MESSAGE;

typedef struct _ACKNOWLEDGE_
{
	int8 ucUUID[5];
	uint8 ucCommand;
	int8 ucData[5];
	uint8 ucState;
	uint8 RESERVED[52];
}ACKNOWLEDGE;

typedef enum _ERRORVALUE_
{
	ERR_OK,
	ERR_Q_FULL,
	ERR_Q_EMPTY,
	ERR_Q_SEND_FAILED,
	ERR_Q_REC_FAILED,
	ERR_MSG_OK,
	ERR_MSG_WRONG_CMND,
	ERR_ACK_OK,
	ERR_ACK_ERR
}ERRORVALUE;

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool threadProcessAcknowledge(const int8 *pcFunctionName,
		                      ACKNOWLEDGE stAckData);
bool threadProcessMessage(const int8 *pcFunctionName, MESSAGE stMessageData);
void threadPrintError(const int8 *pcFunctionName, ERRORVALUE enErrorValue);

//*********************** Inline Method Implementations ***********************

#endif // _THREAD_FUNCTION_H_
// EOF
