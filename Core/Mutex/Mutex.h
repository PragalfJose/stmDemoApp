//********************************* Mutex *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Mutex.h
// Summary  : Mutex Related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 18/08/2025
//
//*****************************************************************************
#ifndef _MUTEX_H_
#define _MUTEX_H_

//******************************* Include Files *******************************
#include "cmsis_os2.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define MUTEX_TIMEOUT           0      // No time out

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool mutexMutexCreate(osMutexId_t *pmutMutexID,
		                const osMutexAttr_t *pstAttr);
bool mutexMutexDelete(osMutexId_t pmutMutexID);
bool mutexMutexAcquire(osMutexId_t pmutMutexID, uint32 ulTimeout);
bool mutexMutexRelease(osMutexId_t pmutMutexID);

//*********************** Inline Method Implementations ***********************

#endif // _MUTEX_H_
// EOF
