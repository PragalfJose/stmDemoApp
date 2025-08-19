//******************************* Semaphore ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Semaphore.h
// Summary  : Semaphore related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 18/08/2025
//
//*****************************************************************************
#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

//******************************* Include Files *******************************
#include "cmsis_os2.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define SEM_TIMEOUT             0      // No time out

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool semSemaphoreCreate(osSemaphoreId_t *psemSemaphoreID,
		                uint32 ulMaxCount,
		                uint32 ulInitCount,
						const osSemaphoreAttr_t *pstAttr);
bool semSemaphoreDelete(osSemaphoreId_t psemSemaphoreID);
bool semSemaphoreAcquire(osSemaphoreId_t psemSemaphoreID, uint32 ulTimeout);
bool semSemaphoreRelease(osSemaphoreId_t psemSemaphoreID);

//*********************** Inline Method Implementations ***********************

#endif // _SEMAPHORE_H_
// EOF
