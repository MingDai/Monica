#ifndef NMSP_CORE_CALLLOG_SESSIONEVENT_H
#define NMSP_CORE_CALLLOG_SESSIONEVENT_H

/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/

/** \file nmsp_core_calllog_sessionevent.h
*           
*           Nuance Mobile Application Server Resource
*
*   \section Legal_Notice Legal Notice
*
*   Copyright 2006-2011, Nuance Communications Inc. All rights reserved.      
*                                                                           
*   Nuance Communications, Inc. provides this document without representation 
*   or warranty of any kind. The information in this document is subject to   
*   change without notice and does not represent a commitment by Nuance       
*   Communications, Inc. The software and/or databases described in this      
*   document are furnished under a license agreement and may be used or       
*   copied only in accordance with the terms of such license agreement.       
*   Without limiting the rights under copyright reserved herein, and except   
*   as permitted by such license agreement, no part of this document may be   
*   reproduced or transmitted in any form or by any means, including, without 
*   limitation, electronic, mechanical, photocopying, recording, or otherwise,
*   or transferred to information storage and retrieval systems, without the  
*   prior written permission of Nuance Communications, Inc.                   
*                                                                           
*   Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are      
*   trademarks or registered trademarks of Nuance Communications, Inc. or its 
*   affiliates in the United States and/or other countries. All other         
*   trademarks referenced herein are the property of their respective owners. 
*  
*   \section Overview
*
*   This Resource provides access to Nuance Mobile Application Server(NMAS).
*   It allows the user to access the functionalities provided by NMAS
*   and drives the applications that wish to use NMAS services.<BR><BR>
*
*   See the section on NMAS in the Introduction on the
*   Main Page tab as well as the <em>Programmer's Guide</em> for detailed
*   information on NMAS and the NMAS Resource module of the SDK.
*
*/

#ifdef __cplusplus
extern "C" {
#endif
    
/*
 *  Include headers for external data types required by this interface.
 */
#include <nmsp_oem/nmsp_platform.h>
#include <nmsp_oem/nmsp_general.h>
#include <nmsp_core/nmsp_core_defines.h>

//#define NMSP_CALLLOG_SESSION_EVENT_PREFIX              "NMSP_"
/* Events */
#define NMSP_CALLLOG_NMSPSDK_EVENT             "CLIENT"
#define NMSP_CALLLOG_SHUTDOWN_EVENT            "NMSP_ShutDown"

#define NMSP_CALLLOG_NMSPSESSION               "NMSPSession"
#define NMSP_CALLLOG_CONNECT_EVENT             "Connect"
#define NMSP_CALLLOG_CONNECTED_EVENT           "ConnectionEstablished"

#define NMSP_CALLLOG_STREAM_START_EVENT        "StreamStart"
#define NMSP_CALLLOG_STREAM_STOP_EVENT         "StreamStop"

#define NMSP_CALLLOG_NMSPGW_EVENT              "NMSP_GATEWAY"

#define NMSP_CALLLOG_NMSPSOCKET_EVENT          "NMSPSocket"
#define NMSP_CALLLOG_OPENSOCKET_EVENT          "OpenSocket"
#define NMSP_CALLLOG_SOCKETOPENED_EVENT        "SocketOpened"
#define NMSP_CALLLOG_CLOSESOCKET_EVENT         "CloseSocket"
#define NMSP_CALLLOG_SOCKETCLOSED_EVENT        "SocketClosed"

#define NMSP_CALLLOG_NMASCOMMAND_EVENT         "NMASCommand"
#define NMSP_CALLLOG_NMASRESPONSE_EVENT        "NMASResponse"
#define NMSP_CALLLOG_COMMANDABORT_EVENT        "CommandAbort"
#define NMSP_CALLLOG_COMMANDEXPIRED_EVENT      "CommandExpired"
#define NMSP_CALLLOG_NMASAUDIOPARAM_EVENT      "NMASAudioParameter"

#define NMSP_CALLLOG_RECORDER_EVENT            "NMSPRecorder"
#define NMSP_CALLLOG_RECORDERSTART_EVENT       "RecorderStart"
#define NMSP_CALLLOG_RECORDERSTOP_EVENT        "RecorderStop"
#define NMSP_CALLLOG_RECORDSTREAMSTART_EVENT   "RecorderStreamStart"
#define NMSP_CALLLOG_RECORDSTREAMSTOP_EVENT    "RecorderStreamStop"

#define NMSP_CALLLOG_PLAYER_EVENT              "NMSPPlayer"
#define NMSP_CALLLOG_PLAYERSTART_EVENT         "PlayerStart"
#define NMSP_CALLLOG_PLAYERSTOP_EVENT          "PlayerStop"
#define NMSP_CALLLOG_PLAYSTREAMSTART_EVENT     "PlayerStreamStart"
#define NMSP_CALLLOG_PLAYSTREAMSTOP_EVENT      "PlayerStreamStop"

#define NMSP_CALLLOG_APP_REMOTEEVENT           "APP_REMOTEEVENT"
#define NMSP_CALLLOG_ORIGIN_CLIENT             "Client"

/**
 * \enum nmsp_calllog_Attribute_Type
 *
 * \brief Defines the possible attribute value types.
 *
 */
typedef enum {
    TYPE_BINARY,
    TYPE_BOOLEAN,
    TYPE_FLOAT,
    TYPE_INTEGER,
    TYPE_LONG,
    TYPE_STRING,
    TYPE_EVENT_REFERENCE
} nmsp_calllog_Attribute_Type;

/**
 * \typedef nmsp_calllog_SessionEvent
 **/
typedef struct nmsp_calllog_SessionEvent_ nmsp_calllog_SessionEvent;

/**
 * \typedef nmsp_calllog_SessionEventBuilder
 **/
typedef struct nmsp_calllog_SessionEventBuilder_ nmsp_calllog_SessionEventBuilder;

/**
 * Session Event
**/

/**
 * \brief Method to create a session event builder as a child 
 * of the current session event.
 *
 * Returns a pointer to application session event builder.
 *
 * \param calllog        Pointer to session event object.
 *                       Must not be NULL.
 *
 * \param eventName      Session Event name.
 *                       Must not be NULL.
 *
 * \param schemaVersion  The schema version of the new event, usually defined by the server
 *                       May be NULL or Empty string if there is no schema version.
 *
 * \return               Pointer to application session event builder. Returns NULL if error occurs.
 *
 **/
NMSP_CORE_EXPORT nmsp_calllog_SessionEventBuilder* nmsp_calllog_SessionEvent_createChildEventBuilder(const nmsp_calllog_SessionEvent* sessionEvent,
	                                                                                                 const char* eventName,
																									 const char* schemaVersion);

/**
 * \brief Method to retrieve the number of ref ids once they have been generated
 *
 * \param session_event    Pointer to the session event which contains the ref ids
 *
 * \param refIdsCount[out] This will hold the number of ref ids in the session event
 *
 * \return                 NMSP_CORE_STATUS
 *
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEvent_getRefIdsCount(const nmsp_calllog_SessionEvent* sessionEvent, unsigned long* refIdsCount);

/**
 * \brief Method to retrieve the reference id and associated reference event name (by
 *        the given index) once they have been generated. The application needs to copy
 *        those values. The name and reference id strings are owned by the session event
 *        object and they will be destroyed once the session event object is destroyed.
 *
 * \param session_event  Pointer to the session event which contains the ref ids
 *
 * \param refIdName[out] Pointer that will contain the event name of the retrieved ref id
 *
 * \param refId[out]     Pointer that will contain the ref id 
 *
 * \param index          Index of the ref id to retrieve
 *
 * \return               NMSP_CORE_STATUS
 *
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEvent_getRefIdByIndex(const nmsp_calllog_SessionEvent* session_event, char** refIdName, char** refId, unsigned long index);

/**
 * \brief Commit current session events attributes and generate session event.
 *
 * Returns a pointer to application session event.
 *
 * \param event_builder  Pointer to session event builder object.
 *                       Must not be NULL.
 *
 * \return               Pointer to session event . Returns NULL if the commitment fails, the current
 *                       session event builder is already committed or the current call log session has
 *                       been closed already.
 *
 **/
NMSP_CORE_EXPORT nmsp_calllog_SessionEvent* nmsp_calllog_SessionEventBuilder_commit(nmsp_calllog_SessionEventBuilder* event_builder);
/**
 * \brief Destroy session event.
 *
 * Destroy a session event, it has to be called before destroying the manager.
 *
 * \param sessionEvent  Pointer to session event object to be destroyed.
 *                      Must not be NULL.
 *
 **/
NMSP_CORE_EXPORT void nmsp_calllog_SessionEvent_destroy(nmsp_calllog_SessionEvent* sessionEvent);

/**
 * \brief               Method to retrieve the session event Id. This id is the concatenation of the root parent id and
 *                      the sequence id of the event. The sequence Id is generated after the builder commit
 *                      callback has been called. 
 *
 * \return              Pointer to the string buffer that holds the session id. Client must copy this buffer
 *                      Returns NULL if this is called before the commit callback has been called.
 **/
NMSP_CORE_EXPORT const char* nmsp_calllog_SessionEvent_getId(const nmsp_calllog_SessionEvent* sessionEvent);

/**
 * Session Event Builder operations
**/
/**
 * \brief Put binary value into session event attribute.
 *
 * \param event_builder  Pointer to session event builder object which will hold the new value
 *                       Must not be NULL.
 *
 * \param key            Attribute key string.
 *
 * \param value          Attribute value of binary string.
 *
 * \param length         length of value.
 *                       
 * \return               NMSP_CORE_STATUS.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEventBuilder_putBinary(nmsp_calllog_SessionEventBuilder* event_builder, const char* key, const unsigned char* value, unsigned long length);

/**
 * \brief Put boolean value into session event attribute.
 *
 * \param event_builder  Pointer to session event builder object which will hold the new value
 *                       Must not be NULL.
 *
 * \param key            Attribute key string.
 *                     
 * \param value          Attribute boolean value.
 *                     
 * \return               NMSP_CORE_STATUS.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEventBuilder_putBoolean(nmsp_calllog_SessionEventBuilder* event_builder, const char* key, const NMSP_BOOL value);

/**
 * \brief Put float value into session event attribute.
 *
 * \param event_builder  Pointer to session event builder object which will hold the new value
 *                       Must not be NULL.
 *
 * \param key            Attribute key string.
 *                 
 * \param value          Attribute float value.
 *                 
 * \return               NMSP_CORE_STATUS.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEventBuilder_putFloat(nmsp_calllog_SessionEventBuilder* event_builder, const char* key, const double value);

/**
 * \brief Put integer value into session event attribute.
 *
 * \param event_builder  Pointer to session event builder object which will hold the new value
 *                       Must not be NULL.
 *
 * \param key            Attribute key string.
 *                     
 * \param value          Attribute integer value.
 *                     
 * \return               NMSP_CORE_STATUS.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEventBuilder_putInteger(nmsp_calllog_SessionEventBuilder* event_builder, const char* key, const long value);

/**
 * \brief Put 64-bit long value into session event attribute.
 *
 * \param event_builder  Pointer to session event builder object which will hold the new value
 *                       Must not be NULL.
 *
 * \param key            Attribute key string.
 *               
 * \param value          64 bit integer value (both 32-bit and 64-bit system)
 *               
 * \return               NMSP_CORE_STATUS.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEventBuilder_putLong(nmsp_calllog_SessionEventBuilder* event_builder, const char* key, long long value);

/**
 * \brief Put string value into session event attribute.
 *
 * \param event_builder  Pointer to session event builder object which will hold the new value
 *                       Must not be NULL.
 *
 * \param key            Attribute key string.
 *                   
 * \param value          Attribute string value with string terminator. Could be empty but cannot be NULL.
 *                   
 * \return               NMSP_CORE_STATUS.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEventBuilder_putString(nmsp_calllog_SessionEventBuilder* event_builder, const char* key, const char* value);

/**
 * \brief create a remote event with the given name.
 *
 * \param event_builder  Pointer to session event builder object which will hold the new value
 *                       Must not be NULL.
 *
 * \param event_name    Name of the new remote event
 *
 * \return              NMSP_CORE_STATUS.
 */
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllog_SessionEventBuilder_createRemoteEvent(nmsp_calllog_SessionEventBuilder* event_builder, const char* event_name);
    
/**
 * \brief Destroy session event builder.
 *
 * \param event_builder  Pointer to session event builder object to be destroyed.
 *                       Must not be NULL.
 *
 **/
NMSP_CORE_EXPORT void nmsp_calllog_SessionEventBuilder_destroy(nmsp_calllog_SessionEventBuilder* event_builder);

    
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // NMSP_CORE_CALLLOG_SESSIONEVENT_H