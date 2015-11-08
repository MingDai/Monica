#ifndef NMSP_RESOURCE_COMMON
#define NMSP_RESOURCE_COMMON
/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/
/** \file nmsp_resource_common.h
 *  
 *               Common Definitions for NMSP Resources
 *
 *  \section Legal_Notice Legal Notice
 *
 *  Copyright 2006-2011, Nuance Communications Inc. All rights reserved.      
 *                                                                           
 *  Nuance Communications, Inc. provides this document without representation 
 *  or warranty of any kind. The information in this document is subject to   
 *  change without notice and does not represent a commitment by Nuance       
 *  Communications, Inc. The software and/or databases described in this      
 *  document are furnished under a license agreement and may be used or       
 *  copied only in accordance with the terms of such license agreement.       
 *  Without limiting the rights under copyright reserved herein, and except   
 *  as permitted by such license agreement, no part of this document may be   
 *  reproduced or transmitted in any form or by any means, including, without 
 *  limitation, electronic, mechanical, photocopying, recording, or otherwise,
 *  or transferred to information storage and retrieval systems, without the  
 *  prior written permission of Nuance Communications, Inc.                   
 *                                                                           
 *  Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are      
 *  trademarks or registered trademarks of Nuance Communications, Inc. or its 
 *  affiliates in the United States and/or other countries. All other         
 *  trademarks referenced herein are the property of their respective owners.
 *
 *  \section Overview
 *
 *  Defines functions that are common to all NMSP SDK resources: Recognition,
 *  Dictation, TTS (text-to-speech), and NMAS. These common functions are
 *  implemented by an SDK resource when that resource is created.
 *
 */

#include <nmsp_oem/nmsp_platform.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <nmsp_oem/nmsp_defines.h>
#include <nmsp_oem/nmsp_vector.h>
#include <nmsp_core/nmsp_core_calllog_sessionevent.h>

/**
 * \enum NMSP_STATUS
 *
 * \brief Defines the possible status of NMSP functions.
 **/
typedef enum
{
    NMSP_OK                   = 0x00,               /*!< Indicates success */
    NMSP_ERROR                = 0x01,               /*!< Indicates a generic error */
    NMSP_OUT_OF_MEMORY_ERROR  = 0x02,               /*!< Indicates an out-of-memory error */
    NMSP_RESOURCE_UNLOADED    = 0x04                /*!< Indicates that the NMSP resource was unloaded */
} NMSP_STATUS;

/**
 *      \typedef nmsp_Manager
 *
 * \brief An opaque data structure.
 *
 *        This structure defines and maintains the connection between the 
 *        NMSP Gateway and the client. It is required to create any NMSP SDK resources.
 * \see nmsp_manager_create
 **/
typedef struct nmsp_Manager_ nmsp_Manager;

/**
 *      \typedef nmsp_Resource
 *
 * \brief An opaque data structure.
 *
 *        This structure defines functionalities that are implemented by all SDK
 *        resources. It provides basic operations such as: getParam, setParam, 
 *        and freeResource. Every NMSP SDK resource will implicitly create its own 
 *        nmsp_Resource structure.
 *
 *        When a resource is created, it is possible to access the corresponding 
 *        nmsp_Resource reference. For example, for an NMAS Resource, after calling
 *        nmsp_nmas_resource_create(), the nmsp_Resource can be retrieved by calling
 *        nmsp_nmas_resource_get_nmsp_resource(). Obtaining a reference to the 
 *        nmsp_Resource allows calling the common operations: getParam, setParam,
 *        and freeResource.        
 *
 * \see nmsp_RecognitionResource
 * \see nmsp_DictationResource
 * \see nmsp_TTSResource
 * \see nmsp_NmasResource
 **/
typedef struct nmsp_Resource_ nmsp_Resource;


/**
 * \enum NMSP_MANAGER_EVENT
 *
 * \brief Defines the possible events between the NMSP manager and the NMSP Gateway.
 * 
 * These events are used to indicate to the nmsp_manager_eventCB callback 
 * that a particular manager event has occurred.
 *
 * \see nmsp_manager_eventCB
 **/
typedef enum {
    NMSP_MANAGER_CONNECTED         = 0x01,          /*!< Indicates that manager successfully connected to gateway */
    NMSP_MANAGER_DISCONNECTED      = 0x02,          /*!< Indicates that manager diconnected from gateway */
    NMSP_MANAGER_CONNECTION_FAILED = 0x03,          /*!< Indicates that manager failed to connect to gateway */
    NMSP_MANAGER_DESTROYED         = 0x04,          /*!< Indicates that manager was destroyed, and corresponding memory freed */
    NMSP_MANAGER_OUT_OF_MEMORY     = 0x05           /*!< Indicates that manager failed due to an out-of-memory error */
} NMSP_MANAGER_EVENT;

/**
 *\enum NMSP_REMOTE_DISCONNECT_REASON
 *
 * \brief Defines the possible disconnect reason received from NMSP Gateway.
 * 
 * \see nmsp_manager_eventCB
 **/
typedef enum {
    NMSP_REMOTE_DISCONNECT_NORMAL                = 0x0000,
    NMSP_REMOTE_DISCONNECT_TIMEOUT               = 0x0001,
    NMSP_REMOTE_DISCONNECT_SERVER_SHUTDOWN       = 0x0002,
    NMSP_REMOTE_DISCONNECT_CRITICAL_ERROR        = 0x0003,
    NMSP_REMOTE_DISCONNECT_PING_TIME_OUT         = 0x0004,
    NMSP_REMOTE_DISCONNECT_SERVER_UNAVAILABLE    = 0x0005,
    NMSP_REMOTE_DISCONNECT_ENDPOINT_EXCEPTION    = 0x0006,
    NMSP_REMOTE_DISCONNECT_MAXAUDIO_PERSESSION   = 0x0007,
    NMSP_REMOTE_DISCONNECT_MAXBYTE_PERAUDIO      = 0x0008,
    NMSP_REMOTE_DISCONNECT_CONNECT_FORBIDDEN     = 0x0193, //403
    NMSP_REMOTE_DISCONNECT_UNKNOWN               = 0x0009,
    NMSP_REMOTE_DISCONNECT_SECURITY              = 0x000A,
} NMSP_REMOTE_DISCONNECT_REASON;

/**
 * \brief Callback function. Called to notify the application of manager events.
 *
 * An implementation of this callback function needs to be passed to the 
 * nmsp_manager_create function in order to create a manager. 
 *
 * \param event               Event occurring between the NMSP manager and the NMSP Gateway.
 *                            Possible events are defined in NMSP_MANAGER_EVENT.
 *
 * \param event_data          event_data is associated with event. There are three meanings:
 *                            1) if the event is NMSP_MANAGER_CONNECTED, event_data is session id.
 *                               Session id is UUID of the session between client and the NMSP 
 *                               Gateway server. The type of session id is const char string.
 *                            2) if the event is NMSP_MANAGER_DISCONNECTED or NMSP_MANAGER_CONNECTION_FAILED,
 *                               event_data is remote disconnect reason. Remote disconnect reason indicates
 *                               the reason that gateway server disconnected the connection.
 *                               possible reasons are defined in enum NMSP_REMOTE_DISCONNECT_REASON.
 *                               For more details about disconnection reason code, please check the
 *                               NMSP Gateway documents.
 *                            3) if the event is NMSP_MANAGER_DESTROYED, the event_data is the serialized
 *                               call log data (if the call log is not disabled). The application needs to
 *                               use the CalllogSender to transmit the binary call log to the server
 *                               separately.
 *
 * \param event_dataLen       event_dataLen is data length of event_data.
 *
 * \param user_data           Pointer to the application data needed to re-create the context 
 *                            of a function call. Originally passed in nmsp_manager_create. 
 *                            Might be NULL, if application originally passed NULL.
 *
 * \see NMSP_MANAGER_EVENT
 * \see nmsp_manager_create
 **/
typedef void (*nmsp_manager_eventCB)(NMSP_MANAGER_EVENT event, const void * event_data, int event_dataLen, void* user_data);

/**
 * \brief Callback function. Called by the SDK when there are some more call log data to offer to the application.
 *
 * An implementation of this callback function needs to be passed to the  nmsp_manager_create function
 * in order to create a manager. The application needs to copy the buffer and manage to save it in properly.
 * (e.g. save in memory and back up in persistent storage). The memory contained in the \p buffer parameter
 * will be freed by the SDK internally after this call back is called.
 *
 * When the buffer is NULL and the size is 0, it indicates that this is the end of the call log data output. And there
 * is no more data will be delivered to the application via the nmsp_manager_calllog_outputCB call back.
 *
 * \p buffer                The buffer contains the call log data generated inside SDK, could be NULL if there is no
 *                          more data to be read, this happens after shutting down the manager.
 *
 * \p size                  The size of the \p buffer in bytes
 *
 * \p sessionEventIds       The pointer to an array of session event ids (as ASCII strings) packaged inside the
 *                          \ref buffer, could be NULL, if the buffer is NULL
 *
 * \p numOfSessionEvents    The number of the packaged session events inside the \ref buffer, could be 0 if the
 *                          buffer is NULL.
 *
 * \p user_data             Pointer to the application data needed to re-create the context 
 *                          of a function call. Originally passed in nmsp_manager_create. 
 *                          Might be NULL, if application originally passed NULL.
 *
 * \see nmsp_manager_create
 **/
typedef void (*nmsp_manager_calllog_outputCB)(const void* buffer, unsigned long size, const char** sessionEventIds, unsigned long numOfSessionEvents, void* user_data);

/**
 * \brief Creates an nmsp_Manager structure.
 *
 * This function returns a pointer to a newly allocated nmsp_Managerstructure. 
 * If the allocation failed, NULL is returned.  The nmsp_Manager structure defines  
 * and maintains the connection between the NMSP Gateway and the client. It is 
 * required to create any NMSP SDK resources.
 * To delete the nmsp_Manager, the function nmsp_manager_destroy() must be used.
 *
 * \param server              NMSP Gateway IP address or host name. This address 
 *                            indicates to the manager which NMSP Gateway it should
 *                            attempt to connect to. Specifying an address that 
 *                            does not have a NMSP Gateway running on it causes the 
 *                            connection to fail.
 *                            Must not be NULL.
 *
 * \param port                NMSP Gateway port number. This port number indicates 
 *                            to the manager which NMSP port it should attempt
 *                            to connect to. Specifying an incorrect port number
 *                            causes the connection to fail.
 *                            Must not be NULL.
 *
 * \param applicationId       Application ID provided by Nuance Communications, Inc
 *
 * \param applicationKey      Application key provided by Nuance Communications, Inc.
 *                            Must not be NULL
 *
 * \param applicationKeyLen   Length of the application key, in bytes.
 *                            Must match the length of application key.
 *
 * \param unique_id           Unique identifier. e.g.: phone number (UTF8).
 *                            Must not be NULL.
 *
 * \param input_codec         Input codec as defined in NMSP_DEFINES_CODEC.
 *
 * \param output_codec        Output codec as defined in NMSP_DEFINES_CODEC.
 *
 * \param parameters          Pointer to an array of nmsp_Parameter for this nmsp_Manager.
 *                            <br>Allowed parameter types:
 *                            <br> ::NMSP_PARAM_TYPE_APP
 *                            <br> ::NMSP_PARAM_TYPE_SDK
 *                            <br> ::NMSP_PARAM_TYPE_NMSP
 *                            <br>Sending any other parameter type causes an error.
 *                              
 *
 * \param manager_eventCB     The nmsp_manager_eventCB function. Called when a event
 *                            occurs, for example, if a connection is established or 
 *                            memory allocation fails.
 *                            Must not be NULL.
 *
 * \param calllog_outputCB    The nmsp_manager_calllog_outputCB function. Called when SDK
 *                            delivers some call logs, 
 *
 * \param user_data           Void pointer to application data. This pointer is returned in the
 *                            nmsp_manager_EventCB function, and allows identifying and/or 
 *                            recreating the original context of the callback.
 *
 * \return      Pointer to an nmsp_Manager. If an error occurs, NULL is returned.
 *
 * \see NMSP_DEFINES_CODEC
 * \see nmsp_manager_eventCB
 **/
NMSP_RESOURCE_COMMON_EXPORT nmsp_Manager* nmsp_manager_create(const char*                         server,
                                                              const short                         port,
                                                              const char*                         applicationId,
                                                              const char*                         applicationKey,
                                                              const int                           applicationKeyLen,
                                                              const char*                         unique_id,
                                                              const NMSP_DEFINES_CODEC            input_codec,
                                                              const NMSP_DEFINES_CODEC            output_codec,
                                                              const nmsp_Vector*                  parameters,
                                                              const nmsp_manager_eventCB          manager_eventCB,
                                                              const nmsp_manager_calllog_outputCB calllog_outputCB,
                                                              void*                               user_data);

/**
 * \brief Terminates the connection to the NMSP Gateway and release underlying resources.
 *
 * This function disconnects from the NMSP Gateway and deletes the memory allocated by the nmsp_Manager.
 * \note This function <em>must</em> be the <em>last</em> SDK function called. The nmsp_Resource used must 
 * be deleted using nmsp_resource_freeResource before deleting this function.
 * \warning The application must wait for the NMSP_MANAGER_DESTROYED event and call nmsp_manager_cleanup before
 * creating a new nmsp_Manager.
 *
 * \param manager           An nmsp_Manager.
 *                          Must not be NULL.
 *
 * \return      NMSP_OK    if the request to shutdown/destroy the manager was sent successfully.
 *              NMSP_ERROR if an error occurs.
 **/
NMSP_RESOURCE_COMMON_EXPORT NMSP_STATUS nmsp_manager_destroy(nmsp_Manager* manager);

/**
 * \brief Does the final synchronous cleanup of the nmsp_Manager.
 *
 * This function is responsible for doing the final cleanup of the nmsp_Manager that is
 * required to be done from the application thread, most notably stopping/destroying the
 * message system. This is a synchronous, though not heavy call.
 * \warning The application must wait for the NMSP_MANAGER_DESTROYED event before making this call.
 *
 * \param manager           An nmsp_Manager.
 *                          Must not be NULL.
 *
 * \return      NMSP_OK     cleanup done successfully. Cannot fail.
 */
NMSP_RESOURCE_COMMON_EXPORT NMSP_STATUS nmsp_manager_cleanup(nmsp_Manager* manager);

/**
 * \brief Set certain parameters into the nmsp_Manager object after the creation of the nmsp_Manager.
 * 
 * This function gives the application the opportunities to reset some of the parameters set into
 * the nmsp_Manager during the \ref nmsp_manager_create call. Not all the nmsp_Manager parameters
 * are allowed to be reset after the nms_manager creation. Currently the allowed parameters include
 * \ref NMSP_DEFINES_IDLE_SESSION_TIMEOUT_PARAM
 *
 * The parameter objects in the parameters array should be of type \ref nmsp_Parameter.
 *
 * \param manager           An nmsp_Manager, must not be NULL.
 *
 * \param parameters        Pointer to an array of nmsp_Parameter for this nmsp_Manager.
 *                          <br> Allowed parameter types:
 *                          <br> ::NMSP_PARAM_TYPE_SDK
 *                          <br> Sending any other parameter type causes an error.
 *                          Must not be NULL.
 *
 * \return      NMSP_OK     if the parameters have been set to the nmsp_Manager successfully.
 *              NMSP_ERROR  if an error occurs.
 *
 * \see NMSP_DEFINES_IDLE_SESSION_TIMEOUT_PARAM
 **/
NMSP_RESOURCE_COMMON_EXPORT NMSP_STATUS nmsp_manager_setParameter(nmsp_Manager* manager, const nmsp_Vector* parameters);

/**
 * \brief Log an application event by creating a SessionEventBuilder. This session event
 * is a child of the current SDK root session event. The application can call this method
 * multiple times to retrieve session event builders at different time.
 *  
 * For example, logging user behaviors for different recognition transactions.
 * 
 * The application can also use the returned SessionEventBuilder to log associated sub
 * log events.
 *
 * Returns a pointer to application session event builder.
 *
 * \param manager        A pointer to nmsp_Manager object
 *                       Must not be NULL.
 *
 * \param appEventName   Application event name.
 *                       Must not be NULL or empty.
 *
 * \param schemaVersion  The application event schema version, usually provided by the server
 *                       May be NULL or empty string if schema version is unknown.
 *
 * \return               Pointer to application session event builder. Returns NULL if
 *                       error occurs (check log) or call log feature is disabled upon
 *                       creating the nmsp Manager.
 * 
 * \see NMSP_DEFINES_CALLLOG_DISABLE
 **/
NMSP_RESOURCE_COMMON_EXPORT nmsp_calllog_SessionEventBuilder* nmsp_manager_logAppEvent(nmsp_Manager* manager, const char* appEventName, const char* schemaVersion);

/**
 * \brief Retrieves the root parent Id of the current Calllog session, the root parent
 * Id is Unique per Manager.
 * 
 * \param manager        Pointer to the nmsp_Manager object, must not be NULL.
 * 
 * \return               The root parent Id of the current call log session
 *                       NULL if the call log feature is disabled upon creating the NMSP Manager
 *
 * \see NMSP_DEFINES_CALLLOG_DISABLE
 **/
NMSP_RESOURCE_COMMON_EXPORT const char* nmsp_manager_getCalllogRootParentId(nmsp_Manager* manager);

/**
 * \brief Processes any pending call logs to the callback nmsp_manager_calllog_outputCB
 * This should be used whenever the client wants the logs to be flushed before the chunk 
 * size limit has been reached.
 *
 * There will be only one buffer to be produced once this function is called, because
 * the current internal call log data will always be smaller than the chunk size limit
 * otherwise it would have been already generated.
 *
 * In the case that there is no internal call log data at the moment when this function
 * is called, an empty buffer will be produced as well to notify the client this is the
 * end of the call log outputting.
 * 
 * \param manager        Pointer to the nmsp_Manager object, must not be NULL.
 * 
 * \see NMSP_DEFINES_CALLLOG_CHUNK_SIZE
 **/
NMSP_RESOURCE_COMMON_EXPORT void nmsp_manager_flushCallLogData(nmsp_Manager* manager);

/**
 * \enum NMSP_RESOURCE_EVENT
 *
 * \brief Defines the possible events delivered by nmsp_Resource.
 * 
 * These events are used to indicate to the nmsp_Resource callback 
 * that the resource event that has occurred.
 *
 * \see nmsp_resource_eventCB
 **/
typedef enum {
    NMSP_RESOURCE_SET_PARAM_COMPLETED = 0x01,          /*!< Indicates that a set parameter request completed successfully */
    NMSP_RESOURCE_SET_PARAM_FAILED    = 0x02,          /*!< Indicates that a set parameter request failed */
    NMSP_RESOURCE_GET_PARAM_COMPLETED = 0x03,          /*!< Indicates that a get parameter request completed successfully */
    NMSP_RESOURCE_GET_PARAM_FAILED    = 0x04,          /*!< Indicates that a get parameter request failed */
    NMSP_RESOURCE_RESOURCE_UNLOADED   = 0x05,          /*!< Indicates that the resource was unloaded */
	NMSP_RESOURCE_RESOURCE_DESTROYED  = 0x06           /*!< Indicates that the resource was destroyed */
} NMSP_RESOURCE_EVENT;

/**
 * \enum RESOURCE_EVENT_CODE
 *
 * \brief Event code delivered by the NMSP Gateway.
 *
 * These events are used to provide the nmsp_Resource callback 
 * more insight about the resource event that has occurred.
 *
 * \see nmsp_resource_eventCB
 **/
typedef enum {
    CLIENT_DISCONNECTED_NORMALLY           = 0x0000,          /*!< Indicates that the NMSP SDK Client disconnected normally */
    CLIENT_SOCKET_SHUTDOWN_UNEXPECTEDLY    = 0x0001,          /*!< Indicates that the connection socket shutdown unexpectedly */
    CLIENT_PING_TIMEOUT                    = 0x0002,          /*!< Indicates that a ping request timed out */
    CLIENT_IDLE_TIMEOUT                    = 0x0003,          /*!< Indicates that a timeout occurred because Client was idle for to long */
    NSS_TERMINATED_SESSION_TIMEOUT         = 0x0004,          /*!< Indicates that the Nuance Speech Server terminated the session because of a timeout*/
    NSS_TERMINATED_SESSION_ERROR           = 0x0005,          /*!< Indicates that the Nuance Speech Server terminated the session because of an error*/
    GW_TERMINATED_SESSION_ERROR            = 0x0006,          /*!< Indicates that the NMSP Gateway terminated the session because of an error*/
    APP_SERVER_SESSION_TERMINATED_NORMALLY = 0x0007,          
    APP_SERVER_SESSION_TERMINATED_ERROR    = 0x0008,

    RESOURCE_EVENT_CODE_EMPTY              = 0xffff            /*!< Indicates that there is no resource event code to report */
} RESOURCE_EVENT_CODE;

/**
 * \enum RESOURCE_STATUS_CODE
 *
 * \brief Resource status code delivered by the NMSP Gateway.
 *
 * These events are used to provide the nmsp_Resource callback 
 * more insight about the resource event that has occurred.
 *
 * These status codes are used as defined in the Media Resource
 * Control Protocol version 2 (MRCPv2) Standard.
 *
 * \see nmsp_resource_eventCB
 **/
typedef enum {
    STATUS_CODE_SUCCESS                        = 200,               /*!< */
    STATUS_CODE_PARTIAL_SUCCESS                = 201,               /*!< */
    STATUS_CODE_METHOD_NOT_ALLOWED             = 401,               /*!< */
    STATUS_CODE_METHOD_NOT_VALID_IN_THIS_STATE = 402,               /*!< */
    STATUS_CODE_UNSUPPORTED_PARAMETER          = 403,               /*!< */
    STATUS_CODE_ILLEGAL_VALUE_FOR_PARAMETER    = 404,               /*!< */
    STATUS_CODE_NOT_FOUND                      = 405,               /*!< */
    STATUS_CODE_MANDATORY_PARAMETER_MISSING    = 406,               /*!< */
    STATUS_CODE_METHOD_OR_OPERATION_FAILED     = 407,               /*!< */
    STATUS_CODE_UNRECOGNIZED_MESSAGE_ENTITY    = 408,               /*!< */
    STATUS_CODE_UNSUPPORTED_PARAMETER_VALUE    = 409,               /*!< */
    STATUS_CODE_OUT_OF_ORDER_NUMBER_ID         = 410,               /*!< */
    STATUS_CODE_SERVER_INTERNAL_ERROR          = 501,               /*!< */
    STATUS_CODE_PROTOCOL_VERSION_NOT_SUPPORTED = 502,               /*!< */
    STATUS_CODE_PROXY_TIMEOUT                  = 503,               /*!< */
    STATUS_CODE_MESSAGE_TOO_LARGE              = 504,               /*!< */
    RESOURCE_STATUS_CODE_RESOURCE_UNLOADED     = 997,               /*!< */
    RESOURCE_STATUS_CODE_OUT_OF_MEMORY         = 998,               /*!< */
    RESOURCE_STATUS_CODE_EMPTY                 = 999               /*!< */
} RESOURCE_STATUS_CODE;

/**
 * \enum RESOURCE_COMPLETION_CAUSE
 *
 * \brief The completion cause delivered by the NMSP Gateway
 *        specifically for nmsp_Resource callbacks.
 *
 * These events are used to provide the nmsp_Resource callback 
 * more insight about a particular resource event that occurred.
 *
 * \see nmsp_resource_eventCB
 **/
typedef enum {
    RESOURCE_COMPLETION_CAUSE_RESOURCE_UNAVAILABLE = 0x0259,          /*!< Indicates that a resource was unavailable */
    RESOURCE_COMPLETION_CAUSE_3RD_PARTY_APP_ERROR  = 0x0260,          /*!< Indicates that a third pary error occurred */
    RESOURCE_COMPLETION_CAUSE_EMPTY                = 0x7FFF           /*!< Indicates that there is no resource event code to report */
} RESOURCE_COMPLETION_CAUSE;


/**
 * \brief Callback function.
 *
 * This callback delivers nmsp_Resource events to the application. 
 * This callback has to be implemented has to be passed by the application
 * when it creates a specific resource.
 *
 * \param event                 Type of the event. Used to specify the
 *                              kind of request and/or its outcome. The
 *                              events sent are defined in NMSP_RESOURCE_EVENT
 *
 * \param parameters            Array of the parameters delivered by the
 *                              resource. 
 *                              This array contains valid data only if 
 *                              event is:
 *                              NMSP_RESOURCE_EVENT_SET_PARAM_COMPLETED
 *                              NMSP_RESOURCE_EVENT_GET_PARAM_COMPLETED
 *                              Otherwise, it is NULL.
 *
 * \param status_code           Status code of the submitted request,
 *                              as defined in RESOURCE_STATUS_CODE.
 *                              This code contains a valid value if 
 *                              event is:
 *                              NMSP_RESOURCE_EVENT_SET_PARAM_COMPLETED
 *                              NMSP_RESOURCE_EVENT_GET_PARAM_COMPLETED
 *                              NMSP_RESOURCE_EVENT_SET_PARAM_FAILED
 *                              NMSP_RESOURCE_EVENT_GET_PARAM_FAILED
 *                              Otherwise it is set to:
 *                              RESOURCE_STATUS_CODE_EMPTY
 *
 * \param completion_cause      Reason explaining the outcome of a request,
 *                              as defined in RESOURCE_COMPLETION_CAUSE.
 *                              This code contains a valid value if 
 *                              event is:
 *                              NMSP_RESOURCE_EVENT_SET_PARAM_FAILED
 *                              NMSP_RESOURCE_EVENT_GET_PARAM_FAILED
 *                              Otherwise it is set to:
 *                              RESOURCE_COMPLETION_CAUSE_EMPTY
 *
 * \param event_code            Event code of the submitted request,
 *                              as defined in RESOURCE_EVENT_CODE.
 *                              This code contains a valid value if
 *                              event is:
 *                              NMSP_RESOURCE_EVENT_RESOURCE_UNLOADED
 *                              Otherwise it is set to:
 *                              RESOURCE_EVENT_CODE_EMPTY                                        
 *
 * \param user_data            Pointer to the application data needed to re-create the context 
 *                             of a function call. Originally passed in the function that created
 *                             this resource. Might be NULL, if application originally passed NULL.
 *
 * \see NMSP_RESOURCE_EVENT
 * \see RESOURCE_EVENT_CODE
 * \see RESOURCE_COMPLETION_CAUSE
 * \see RESOURCE_STATUS_CODE
 **/
typedef void (*nmsp_resource_eventCB)(NMSP_RESOURCE_EVENT       event,
                                      nmsp_Vector*              parameters,
                                      RESOURCE_STATUS_CODE      status_code,
                                      RESOURCE_COMPLETION_CAUSE completion_cause,
                                      RESOURCE_EVENT_CODE       event_code,
                                      void*                     user_data);

/**
 * \brief Sets parameters for a given resource.
 *
 * This function sets a certain parameter of a given resource.
 * The corresponding results will be delivered by nmsp_resource_eventCB.
 *
 * \param resource          The nmsp_Resource object.
 *                          Must not be NULL.
 *
 * \param parameters        An nmsp_Vector contains a list of nmsp_Parameters to
 *                          be set on the NMSP Gateway.
 *                          Must not be NULL.
 *
 * \return      NMSP_OK if the set-param request is submitted successfully.
 *              NMSP_ERROR if an error occurs.
 *              NMSP_OUT_OF_MEMORY_ERROR if memory allocation fails.
 **/
NMSP_RESOURCE_COMMON_EXPORT NMSP_STATUS nmsp_resource_setParams(nmsp_Resource* resource,
                                                                nmsp_Vector*   parameters);

/**
 * \brief Gets parameters for a given resource.
 *
 * This function gets a certain parameter of a given resource.
 * The corresponding results will be delivered by nmsp_resource_eventCB.
 *
 * \param resource          The nmsp_Resource object.
 *                          Must not be NULL.
 *
 * \param parameters        An nmsp_Vector contains a list of nmsp_Parameters to
 *                          be retrieved from the NMSP Gateway.
 *                          Must not be NULL.
 *
 * \return      NMSP_OK if the get-param request is submitted successfully.
 *              NMSP_ERROR if an error occurs.
 *              NMSP_OUT_OF_MEMORY_ERROR if memory allocation fails.
 **/
NMSP_RESOURCE_COMMON_EXPORT NMSP_STATUS nmsp_resource_getParams(nmsp_Resource* resource,
                                                                nmsp_Vector*   parameters);

/**
 * \brief Frees the given resource from the NMSP Gateway.
 *
 * This function deletes a previously allocated resource and releases the
 * corresponding memory.
 * The results will be delivered by nmsp_resource_eventCB.
 *
 * \param resource               The nmsp_Resource object.
 *                               Must not be NULL.
 *
 * \param disconnect_timeout     Timeout, in milliseconds, before the resource is released.
 *
 * \return      NMSP_OK if the free-resource request is submitted successfully.
 *              NMSP_ERROR if an error occurs.
 *              NMSP_OUT_OF_MEMORY_ERROR if memory error occurs.
 **/
NMSP_RESOURCE_COMMON_EXPORT NMSP_STATUS nmsp_resource_freeResource(nmsp_Resource* resource,
                                                                   unsigned long  disconnect_timeout);




#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_RESOURCE_COMMON */
