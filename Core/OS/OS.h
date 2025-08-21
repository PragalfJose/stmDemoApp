//********************************** OS ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : OS.h
// Summary  : None
// Note     : None
// Author   : Pragalf T Jose
// Date     : 13/08/2025
//
//*****************************************************************************
#ifndef _OS_H_
#define _OS_H_

//******************************* Include Files *******************************
#include "cmsis_os.h"
#include "TaskFunctions.h"
#include "MQueue.h"
#include "SwitchTask.h"
#include "BlinkTask.h"
#include "Semaphore.h"
#include "Mutex.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define STACK_SIZE              256
#define TASK_COUNT              2
#define PRIORITY_LVL1           24     // Normal Priority
#define PRIORITY_LVL2           25

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************
bool osInit();
bool osStart();
bool osCreateSwitchTask();
bool osCreateBlinkTask();
bool osDeleteSwitchTask();
bool osDeleteBlinkTask();
bool osCreateMutex();
bool osDeleteMutex();
bool osCreateSwitchSemaphore();
bool osDeleteSwitchSemaphore();
bool osCreateMessageSemaphore();
bool osDeleteMessageSemaphore();
bool osCreateMQueue();
bool osDeleteMQueue();

//*********************** Inline Method Implementations ***********************

#endif // _OS_H_
// EOF
