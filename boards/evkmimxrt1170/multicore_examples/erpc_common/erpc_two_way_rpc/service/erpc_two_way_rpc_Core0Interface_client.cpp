/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * Generated by erpcgen 1.10.0 on Thu Oct 13 21:22:09 2022.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "erpc_client_manager.h"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include "erpc_port.h"
#endif
#include "erpc_codec.hpp"
extern "C"
{
#include "erpc_two_way_rpc_Core0Interface.h"
// import callbacks declaration from other groups
#include "erpc_two_way_rpc_Core1Interface.h"
}

#if 11000 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

extern ClientManager *g_client;

static const getNumberCallback_t _getNumberCallback_t[] = { getNumberFromCore1, getNumberFromCore0 };


// Core0Interface interface setGetNumberFunction function client shim.
void setGetNumberFunction(const getNumberCallback_t getNumberCallbackParam)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kOnewayMessage, kCore0Interface_service_id, kCore0Interface_setGetNumberFunction_id, request.getSequence());

        codec->writeCallback((arrayOfFunPtr)(_getNumberCallback_t), 2, (funPtr)(getNumberCallbackParam));

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kCore0Interface_setGetNumberFunction_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// Core0Interface interface getGetNumberFunction function client shim.
void getGetNumberFunction(getNumberCallback_t * getNumberCallbackParam)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kCore0Interface_service_id, kCore0Interface_getGetNumberFunction_id, request.getSequence());

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        codec->readCallback((arrayOfFunPtr)(_getNumberCallback_t), 2, (funPtr *)(&*getNumberCallbackParam));

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kCore0Interface_getGetNumberFunction_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// Core0Interface interface nestedCallGetNumber function client shim.
void nestedCallGetNumber(const getNumberCallback_t getNumberCallbackParam)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kCore0Interface_service_id, kCore0Interface_nestedCallGetNumber_id, request.getSequence());

        codec->writeCallback((arrayOfFunPtr)(_getNumberCallback_t), 2, (funPtr)(getNumberCallbackParam));

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kCore0Interface_nestedCallGetNumber_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// Core0Interface interface getNumberFromCore1 function client shim.
void getNumberFromCore1(uint32_t * number)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kCore0Interface_service_id, kCore0Interface_getNumberFromCore1_id, request.getSequence());

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        codec->read(number);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kCore0Interface_getNumberFromCore1_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}
