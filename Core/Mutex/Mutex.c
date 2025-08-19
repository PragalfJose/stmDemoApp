//******************************** Mutex **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Mutex.c
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 18/08/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "Mutex.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//***************************.mutexMutexCreate.********************************
//Purpose   : Create Mutex
//Inputs    : pstAttr - Attributes to mutex
//Outputs   : pmutMutexID - Created Mutex ID
//Return    : true - Mutex created, false - failed to create Mutex
//Notes     : None
//*****************************************************************************
bool mutexMutexCreate(osMutexId_t *pmutMutexID,
		                const osMutexAttr_t *pstAttr)
{
	bool blReturn = false;

	if(*pmutMutexID == NULL)
	{
		*pmutMutexID = osMutexNew(pstAttr);
		if(*pmutMutexID != NULL)
		{
			blReturn = true;
		}
	}

	return blReturn;
}

//**************************.mutexMutexDelete.*********************************
//Purpose   : Delete Mutex
//Inputs    : pmutMutexID - Mutex ID
//Outputs   : None
//Return    : true - Semaphore deleted, false - failed to delete Semaphore
//Notes     : None
//*****************************************************************************
bool mutexMutexDelete(osMutexId_t pmutMutexID)
{
	bool blReturn = false;

	if(pmutMutexID != NULL)
	{
		if(osMutexDelete(pmutMutexID) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//**************************.mutexMutexAcquire.********************************
//Purpose   : Acquire Mutex
//Inputs    : pmutMutexID - Mutex ID
//Inputs    : ulTimeout - wait Timeout
//Outputs   : None
//Return    : true - Mutex acquired, false - failed to acquire mutex
//Notes     : None
//*****************************************************************************
bool mutexMutexAcquire(osMutexId_t pmutMutexID, uint32 ulTimeout)
{
	bool blReturn = false;

	if(pmutMutexID != NULL)
	{
		if(osMutexAcquire (pmutMutexID, ulTimeout) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

//**************************.mutexMutexRelease.********************************
//Purpose   : Release Semaphore
//Inputs    : pmutMutexID - Mutex ID
//Outputs   : None
//Return    : true - Mutex released, false - failed to release mutex
//Notes     : None
//*****************************************************************************
bool mutexMutexRelease(osMutexId_t pmutMutexID)
{
	bool blReturn = false;

	if(pmutMutexID != NULL)
	{
		if(osMutexRelease(pmutMutexID) == osOK)
		{
			blReturn = true;
		}
	}

	return blReturn;

}

// EOF
