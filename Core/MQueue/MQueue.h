//******************************** MQueue *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : MQueue.h
// Summary  : Message Queue related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 19/08/2025
//
//*****************************************************************************
#ifndef _MQUEUE_H_
#define _MQUEUE_H_

//******************************* Include Files *******************************
#include "cmsis_os2.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define MQ_TIMEOUT              0
#define MSG_SIZE                64
#define MSG_COUNT               10

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool mqMQueueOpen(osMessageQueueId_t *pvmqMQueueID,
		          uint32 ulMessageCount,
				  uint32 ulMessageSize,
				  osMessageQueueAttr_t *pstMQueueAttr);
bool mqMQueueClose(osMessageQueueId_t pvmqMQueueID);
bool mqMQueuePutData(osMessageQueueId_t pvmqMQueueID,
		             const void *pvMessageData,
					 uint8 ucMessagePriority,
					 uint32 ulTimeout);
bool mqMQueueGetData(osMessageQueueId_t pvmqMQueueID,
                     void *pvMessageData,
		             uint8 ucMessagePriority,
		             uint32 ulTimeout);
bool mqMQueueDataCount(osMessageQueueId_t pvmqMQueueID, uint32 *ulMessageCount);
bool mqMQueueFreeSpace(osMessageQueueId_t pvmqMQueueID, uint32 *ulFreeSpace);
bool mqMQueueReset(osMessageQueueId_t pvmqMQueueID);

//*********************** Inline Method Implementations ***********************

#endif // _MQUEUE_H_
// EOF
