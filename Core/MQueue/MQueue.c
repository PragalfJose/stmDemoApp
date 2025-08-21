//******************************* MQueue **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : MQueue.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 19/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "MQueue.h"
//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//****************************.mqMQueueOpen.***********************************
//Purpose   : Open a message queue with given parameters
//Inputs    : ulMessageCount - Maximum message count
//Inputs    : ulMessageSize - Message size
//Inputs    : pstMQueueAttr - MQueue attributes
//Outputs   : pvmqMQueueID - Created Message Queue ID
//Return    : true - Queue Opened, false - failed to open queue
//Notes     : None
//*****************************************************************************
bool mqMQueueOpen(osMessageQueueId_t *pvmqMQueueID,
		          uint32 ulMessageCount,
				  uint32 ulMessageSize,
				  osMessageQueueAttr_t *pstMQueueAttr)
{
	bool blReturn = false;

	if((NULL == *pvmqMQueueID) &&
	   (ZERO != ulMessageCount) &&
	   (ZERO != ulMessageSize))
	{
		*pvmqMQueueID = osMessageQueueNew(ulMessageCount,
										  ulMessageSize,
										  pstMQueueAttr);
		if(NULL != *pvmqMQueueID)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//***************************.mqMQueueClose.***********************************
//Purpose   : Close a message queue
//Inputs    : pvmqMQueueID - Message queue ID
//Outputs   : None
//Return    : true - Queue Closed, false - failed to close queue
//Notes     : None
//*****************************************************************************
bool mqMQueueClose(osMessageQueueId_t pvmqMQueueID)
{
	bool blReturn = false;

	if(NULL != pvmqMQueueID)
	{
		if(osMessageQueueDelete(pvmqMQueueID) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//***************************.mqMQueuePutData.*********************************
//Purpose   : Put data into queue
//Inputs    : pvmqMQueueID - Message queue ID
//Inputs    : pvMessageData - Message Data
//Inputs    : ucMessagePriority - Message priority
//Inputs    : ulTimeout - Timeout
//Outputs   : None
//Return    : true - Data posted, false - failed to post data
//Notes     : None
//*****************************************************************************
bool mqMQueuePutData(osMessageQueueId_t pvmqMQueueID,
		             const void *pvMessageData,
					 uint8 ucMessagePriority,
					 uint32 ulTimeout)
{
	bool blReturn = false;

	if((NULL != pvmqMQueueID) && (NULL != pvMessageData))
	{
		if(osMessageQueuePut(pvmqMQueueID,
							 pvMessageData,
							 ucMessagePriority,
							 ulTimeout) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//***************************.mqMQueueGetData.*********************************
//Purpose   : Get data from a queue
//Inputs    : pvmqMQueueID - Message queue ID
//Inputs    : ucMessagePriority - Message priority
//Inputs    : ulTimeout - Timeout
//Outputs   : pvMessageData - Message Data
//Return    : true - Data Received, false - failed to Receive data
//Notes     : None
//*****************************************************************************
bool mqMQueueGetData(osMessageQueueId_t pvmqMQueueID,
                     void *pvMessageData,
		             uint8 ucMessagePriority,
		             uint32 ulTimeout)
{
	bool blReturn = false;

	if((NULL != pvmqMQueueID) && (NULL != pvMessageData))
	{
		if(osMessageQueueGet(pvmqMQueueID,
				             pvMessageData,
				             &ucMessagePriority,
				             ulTimeout) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//*************************.mqMQueueDataCount.*********************************
//Purpose   : Get number of data waiting in Queue
//Inputs    : None
//Outputs   : None
//Return    : true - Message waiting in queue, false - Queue is empty
//Notes     : None
//*****************************************************************************
bool mqMQueueDataCount(osMessageQueueId_t pvmqMQueueID, uint32 *ulMessageCount)
{
	bool blReturn = false;

	if((NULL != pvmqMQueueID) && (NULL != ulMessageCount))
	{
		*ulMessageCount = osMessageQueueGetCount (pvmqMQueueID);
		if(*ulMessageCount > ZERO)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//*************************.mqMQueueFreeSpace.*********************************
//Purpose   : Get free space available in queue
//Inputs    : None
//Outputs   : None
//Return    : true - Free space in queue, false - Queue is full
//Notes     : None
//*****************************************************************************
bool mqMQueueFreeSpace(osMessageQueueId_t pvmqMQueueID, uint32 *ulFreeSpace)
{
	bool blReturn = false;

	if((NULL != pvmqMQueueID) && (NULL != ulFreeSpace))
	{
		*ulFreeSpace = osMessageQueueGetSpace(pvmqMQueueID);
		if(*ulFreeSpace > ZERO)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//***************************.mqMQueueReset.***********************************
//Purpose   : Reset a message queue to initial state
//Inputs    : None
//Outputs   : None
//Return    : true - Reset Success, false - failed to reset
//Notes     : None
//*****************************************************************************
bool mqMQueueReset(osMessageQueueId_t pvmqMQueueID)
{
	bool blReturn = false;

	if(NULL != pvmqMQueueID)
	{
		if(osMessageQueueReset(pvmqMQueueID) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

// EOF
