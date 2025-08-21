//***************************** Semaphore *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Semaphore.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 18/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "Semaphore.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//***************************.semSemaphoreCreate.******************************
//Purpose   : Create a Semaphore
//Inputs    : ulMaxCount - Maximum number of Tokens
//Inputs    : ulInitCount - Initial token Value
//Inputs    : pstAttr - Attributes for semaphore
//Outputs   : psemSemaphoreID - Created semaphore ID
//Return    : true - Semaphore Created, false - failed to create semaphore
//Notes     : None
//*****************************************************************************
bool semSemaphoreCreate(osSemaphoreId_t *psemSemaphoreID,
		                uint32 ulMaxCount,
		                uint32 ulInitCount,
						const osSemaphoreAttr_t *pstAttr)
{
	bool blReturn = false;

	if((NULL == *psemSemaphoreID) && (ulMaxCount != 0))
	{
		*psemSemaphoreID = osSemaphoreNew(ulMaxCount, ulInitCount, pstAttr);
		if(NULL != *psemSemaphoreID)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//****************************.psemSemaphoreID.********************************
//Purpose   : Delete a semaphore
//Inputs    : psemSemaphoreID - Semaphore ID
//Outputs   : None
//Return    : true - Semaphore deleted, false - failed to delete semaphore
//Notes     : None
//*****************************************************************************
bool semSemaphoreDelete(osSemaphoreId_t psemSemaphoreID)
{
	bool blReturn = false;

	if(NULL != psemSemaphoreID)
	{
		if(osSemaphoreDelete(psemSemaphoreID) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//***************************.semSemaphoreAcquire.*****************************
//Purpose   : Acquire a semaphore if available
//Inputs    : psemSemaphoreID - Semaphore ID
//Inputs    : ulTimeout - Timeout
//Outputs   : None
//Return    : true - Semaphore acquired, false - failed to acquire semaphore
//Notes     : None
//*****************************************************************************
bool semSemaphoreAcquire(osSemaphoreId_t psemSemaphoreID, uint32 ulTimeout)
{
	bool blReturn = false;

	if(NULL != psemSemaphoreID)
	{
		if(osSemaphoreAcquire(psemSemaphoreID, ulTimeout) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//***************************.semSemaphoreRelease.*****************************
//Purpose   : Release a semaphore
//Inputs    : psemSemaphoreID - semaphore ID
//Outputs   : None
//Return    : true - Semaphore released, false - failed to release semaphore
//Notes     : None
//*****************************************************************************
bool semSemaphoreRelease(osSemaphoreId_t psemSemaphoreID)
{
	bool blReturn = false;

	if(NULL != psemSemaphoreID)
	{
		if(osSemaphoreRelease (psemSemaphoreID) == osOK)
		{
			blReturn  = true;
		}
	}

	return blReturn;

}

// EOF
