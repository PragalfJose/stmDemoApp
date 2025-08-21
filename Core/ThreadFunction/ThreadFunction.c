//**************************** ThreadFunction *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : ThreadFunction.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "ThreadFunction.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//************************.threadProcessAcknowledge.***************************
//Purpose   : Process acknowledge received
//Inputs    : stAckData - Acknowledge received
//Outputs   : None
//Return    : true - Ack state success, false - ack state error
//Notes     : None
//*****************************************************************************
bool threadProcessAck(const int8 *pcFunctionName, ACKNOWLEDGE *stAckData)
{
	bool blReturn = false;
	int8 pcThreadLog[STR_LEN] = {0};

	if((NULL != pcFunctionName) && (NULL != stAckData))
	{
		if((stAckData->ucCommand == 0X02) && (stAckData->ucState == 0X00))
		{
			memset(pcThreadLog, 0, sizeof(pcThreadLog));
			sprintf(pcThreadLog,
					"[%s] : ACK - |%s|0X%02x|%s|0X%02x|\r\n",
					pcFunctionName,
					stAckData->ucUUID,
					stAckData->ucCommand,
					stAckData->ucData,
					stAckData->ucState);
			consoleSerialPrint(pcThreadLog, strlen(pcThreadLog), TX_TIMEOUT);
			blReturn = true;
		}
	}

	return blReturn;

}

//**************************.threadProcessMessage.*****************************
//Purpose   : Process message data
//Inputs    : stMessageData - Message received
//Outputs   : None
//Return    : true - Message receive success, false - message error
//Notes     : None
//*****************************************************************************
bool threadProcessMessage(const int8 *pcFunctionName, MESSAGE *stMessageData)
{
	bool blReturn = false;
	int8 pcThreadLog[STR_LEN] = {0};

	if((NULL != pcFunctionName) && (NULL != stMessageData))
	{
		if(stMessageData->ucCommand == 0X01)
		{
			memset(pcThreadLog, 0, sizeof(pcThreadLog));
			sprintf(pcThreadLog,
					"[ %s ] : MSG - |%s|0X%02x|%s|\r\n",
					pcFunctionName,
					stMessageData->ucUUID,
					stMessageData->ucCommand,
					stMessageData->ucData);
			consoleSerialPrint(pcThreadLog, strlen(pcThreadLog), TX_TIMEOUT);
			blReturn = true;
		}
	}

	return blReturn;

}

//****************************.threadPrintError.*******************************
//Purpose   : Print error messages
//Inputs    : pcFunctionName - Function name having error
//Inputs    : enErrorValue - enum to error type
//Outputs   : None
//Return    : None
//Notes     : None
//*****************************************************************************
void threadPrintError(const int8 *pcFunctionName, ERRORVALUE enErrorValue)
{
	int8 pcThreadLog[STR_LEN] = {0};

	if((NULL != pcFunctionName) &&
			(enErrorValue >= ERR_OK) &&
			(enErrorValue <= ERR_ACK_ERR))
	{
		memset(pcThreadLog, 0, sizeof(pcThreadLog));
		switch(enErrorValue)
		{
			case ERR_OK:
				break;
			case ERR_Q_FULL:
				sprintf(pcThreadLog,
						"[%s] : MESSAGE QUEUE FULL\r\n",
						pcFunctionName);
				break;
			case ERR_Q_EMPTY:
				sprintf(pcThreadLog,
						"[%s] : MESSAGE QUEUE EMPTY\r\n",
						pcFunctionName);
				break;
			case ERR_Q_SEND_FAILED:
				sprintf(pcThreadLog,
						"[%s] : MESSAGE SEND FAILED\r\n",
						pcFunctionName);
				break;
			case ERR_Q_REC_FAILED:
				sprintf(pcThreadLog,
						"[%s] : MESSAGE RECEIVE FAILED\r\n",
						pcFunctionName);
				break;
			case ERR_MSG_OK:
				sprintf(pcThreadLog,
						"[%s] : MESSAGE SEND\r\n",
						pcFunctionName);
				break;
			case ERR_MSG_WRONG_CMND:
				sprintf(pcThreadLog,
						"[%s] : WRONG COMMAND IN MESSAGE\r\n",
						pcFunctionName);
				break;
			case ERR_ACK_OK:
				sprintf(pcThreadLog,
						"[%s] : ACKNOWLEDGE SEND\r\n",
						pcFunctionName);
				break;
			case ERR_ACK_ERR:
				sprintf(pcThreadLog,
						"[%s] : ERROR ACKNOLEDGE\r\n",
						pcFunctionName);
				break;
			default:

		}
	}

	consoleSerialPrint(pcThreadLog, strlen(pcThreadLog), TX_TIMEOUT);
}

// EOF
