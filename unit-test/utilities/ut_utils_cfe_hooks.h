/************************************************************************
 * NASA Docket No. GSC-18,447-1, and identified as “CFS CFDP (CF)
 * Application version 3.0.0”
 *
 * Copyright (c) 2019 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

#ifndef UT_UTILS_CFE_HOOKS_H
#define UT_UTILS_CFE_HOOKS_H

/* cfe includes */
#include "cfe.h"

/* UT includes */
#include "utstubs.h"

typedef struct
{
    CFE_MSG_Message_t *MsgPtr;
    CFE_TIME_SysTime_t Time;
} CFE_MSG_SetMsgTime_context_t;

typedef struct
{
    const CFE_MSG_Message_t *MsgPtr;
    CFE_SB_MsgId_t *         returned_MsgId;
} CFE_MSG_GetMsgId_context_t;

typedef struct
{
    uint16      EventID;
    uint16      EventType;
    const char *Spec;
} CFE_EVS_SendEvent_context_t;

typedef struct
{
    const CFE_MSG_Message_t *MsgPtr;
    CFE_MSG_Size_t *         Size;
} CFE_MSG_GetSize_context_t;

typedef struct
{
    CFE_MSG_Message_t *MsgPtr;
    CFE_SB_MsgId_t     MsgId;
} CFE_MSG_SetMsgId_context_t;

typedef struct
{
    CFE_MSG_Message_t *MsgPtr;
    bool               IncrementSequenceCount;
} CFE_SB_TransmitMsg_context_t;

typedef struct
{
    const CFE_MSG_Message_t *MsgPtr;
    CFE_MSG_FcnCode_t *      FcnCode;
} CFE_MSG_GetFcnCode_context_t;

typedef struct
{
    CFE_MSG_Message_t *MsgPtr;
    CFE_MSG_Size_t     Size;
} CFE_MSG_SetSize_context_t;

int32 UT_Hook_CFE_EVS_SendEvent(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);
int32 UT_Hook_CFE_MSG_SetSize(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);
int32 UT_Hook_CFE_MSG_GetSize(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);
int32 UT_Hook_CFE_MSG_SetMsgId(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);
int32 UT_Hook_CFE_MSG_GetMsgId(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);
int32 UT_Hook_CFE_MSG_GetFcnCode(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);
int32 UT_Hook_CFE_MSG_SetMsgTime(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);
int32 UT_Hook_CFE_SB_TransmitMsg(void *UserObj, int32 StubRetcode, uint32 CallCount, const UT_StubContext_t *Context);

#endif