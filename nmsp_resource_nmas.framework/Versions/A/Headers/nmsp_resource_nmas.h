#ifndef NMSP_RESOURCE_NMAS
#define NMSP_RESOURCE_NMAS
/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/

/** \file nmsp_resource_nmas.h
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


#include <nmsp_oem/nmsp_platform.h>

#ifdef __cplusplus
extern "C" {
#endif


/*
 *  Include headers for external data types required by this interface.
 */
#include <nmsp_oem/nmsp_general.h>
#include <nmsp_oem/nmsp_defines.h>
#include <nmsp_resource_common/nmsp_resource_common.h>
#include <nmsp_resource_nmas/nmsp_resource_nmas_defines.h>

/**
 * \typedef nmsp_NmasResource
 *
 * \brief An opaque data structure.
 *
 * Represents the NMAS resource, which stores application
 * logic on the server side and manages communication with client applications.
 * Applications written with the NMAS Resource module
 * are a series of transactions: requests (containing commands and data)
 * and responses between the application running on a device
 * and NMAS. Transactions are represented by the nmsp_nmas_Command object.
 *
 * \see nmsp_nmas_Command
 */
typedef struct nmsp_NmasResource_ nmsp_NmasResource;

/**
 * \enum NMSP_NMAS_RESOURCE_EVENT
 *
 * \brief Defines the possible events delivered by nmsp_NmasResource.
 *
 * \see nmsp_nmas_resource_eventCB
 */
typedef enum {
    NMSP_NMAS_RESOURCE_COMMAND_CREATED         = 0x01,     /*!< Indicates command successfully created */
    NMSP_NMAS_RESOURCE_COMMAND_CREATION_FAILED = 0x02      /*!< Indicates command creation failed */
} NMSP_NMAS_RESOURCE_EVENT;

typedef enum {
    NMSP_NMAS_RESOURCE_EVENT_REASON_SUCCESS      = 0x00,     /*!< Indicates command successfully created */
    NMSP_NMAS_RESOURCE_EVENT_REASON_CONNECTION   = 0x01,     /*!< Indicates command creating failure due to connection error */
    NMSP_NMAS_RESOURCE_EVENT_REASON_SECURITY     = 0x02,     /*!< Indicates command creating failure due to SSL error */
    NMSP_NMAS_RESOURCE_EVENT_REASON_TIMEOUT      = 0x03,     /*!< Indicates command creating failure due to connection timeout */
    NMSP_NMAS_RESOURCE_EVENT_REASON_PARAMETER    = 0x04,     /*!< Indicates command creating failure due to invalid parameter */
    NMSP_NMAS_RESOURCE_EVENT_REASON_UNKNOWN      = 0x05,     /*!< Indicates command creation failed for unknown reason */
} NMSP_NMAS_RESOURCE_EVENT_REASON_CODE;

/**
 * \brief Callback function. Called to notify the application of NMAS resource events.
 *
 * \param event             The event this callback is signaling.   
 *                          Will not be NULL.
 *
 * \param session_id        session_id is associated with event. There are two meanings:
 *                            1) if the event is NMSP_NMAS_RESOURCE_COMMAND_CREATED, this is the session id.
 *                               Session id is UUID of the session between client and the NMSP 
 *                               Gateway server. The type of session id is const char string.
 *                            2) if the event is NMSP_NMAS_RESOURCE_COMMAND_CREATION_FAILED
 *                               session_id is NULL and event_dataLen is zero.
 *
 * \param session_dataLen   session_dataLen is data length of session_id.
 *
 *
 * \param user_data         Void pointer to user_data. Application data passed by the user
 *                          application when nmsp_nmas_resource_create is called. It allows
 *                          the user to access the application from the callback function.
 *                          Might be NULL if user originally passed NULL.
 * 
 * \return                  void
 *
 * \see NMSP_NMAS_RESOURCE_EVENT
 * \nmsp_nmas_resource_create
 */
typedef void (*nmsp_nmas_resource_eventCB)(NMSP_NMAS_RESOURCE_EVENT         event,
										   const char*				        session_id,
										   int						        session_dataLen,
                                           NMSP_NMAS_RESOURCE_EVENT_REASON_CODE    reason_code,
                                           void*                            user_data);

/**
 * \brief Creates an nmsp_NmasResource structure.
 * 
 * Returns an opaque pointer to a newly allocated Nmas Resource. If the allocation
 * fails, NULL will be returned.
 * To delete the nmsp_NmasResource, the nmsp_nmas_resource_destroy()
 * function must be used.
 *
 * \param manager                   Pointer to an nmsp_Manager object.
 *                                  Must not be NULL.
 *
 * \param nmas_resource_eventCB     nmsp_nmas_resource_eventCB function, which is called
 *                                  to deliver the NMAS resource events.
 *                                  Must not be NULL.
 *
 * \param resource_eventCB          nmsp_resource_eventCB function, which is called
 *                                  to deliver the NMSP resource events.
 *                                  Must not be NULL.
 *
 * \param parameters                Pointer to an array of nmsp_Parameters for this NMAS
 *                                  resource object (for future use).
 *                                  May be NULL.
 *                                  <br>Allowed parameter types:
 *                                  <br>::NMSP_PARAM_TYPE_SDK
 *                                  <br>::NMSP_PARAM_TYPE_NMSP
 *                                  <br>Sending any other parameter type causes an error.
 *
 * \param application               Unique application name.
 *                                  May be NULL.
 *
 * \param user_data                 Void pointer to user data. Used to access the user application
 *                                  in the callback function.
 *                                  May be NULL.
 *
 * \return                          Pointer to an nmsp_NmasResource. 
 *                                  If an error occurs, NULL is returned.
 *
 * \see nmsp_nmas_resource_eventCB (discuss)
 * \see nmsp_resource_eventCB
 **/

NMSP_RESOURCE_NMAS_EXPORT nmsp_NmasResource*
nmsp_nmas_resource_create(nmsp_Manager*                    manager,
                          const nmsp_nmas_resource_eventCB nmas_resource_eventCB,
                          const nmsp_resource_eventCB      resource_eventCB,
                          const nmsp_Vector*               parameters,
                          const char*                      application,
                          void*                            user_data);


/**
 * \brief Destroys an nmsp_NmasResource structure.
 *
 * Deletes a previously allocated nmsp_NmasResource and frees the corresponding memory space.
 *
 * \param nmas_resource             Pointer to the NMAS resource object.
 *                                  This function will return NMSP_ERROR if 
 *                                  this parameter is NULL.
 *                                  Must not be NULL.
 *
 * \return      NMSP_OK    if the NMAS resource is destroyed successfully.
 *              NMSP_ERROR if an error occurs.
 **/
NMSP_RESOURCE_NMAS_EXPORT NMSP_STATUS nmsp_nmas_resource_destroy(nmsp_NmasResource* nmas_resource);

/**
 * \brief Gets the associated nmsp_Resource from the given nmsp_NmasResource object.
 *
 * \param nmas_resource             Pointer to the NMAS resource object.
 *                                  This function will return NULL if 
 *                                  this parameter is NULL.
 *                                  Must not be NULL.                                  
 *
 * \return      Pointer to the nmsp_Resource if it is successfully retrieved.
 *              NULL if an error occurs.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_Resource* nmsp_nmas_resource_get_nmsp_resource(const nmsp_NmasResource* nmas_resource);

/**
 * \enum NMSP_NMAS_STATUS
 *
 * \brief Defines the possible status of an nmsp_nmas_Command.
 *
 * Is the return value for many functions related to nmsp_nmas_Command.
 *
 **/
typedef enum {
    NMSP_NMAS_OK,                               /*!< Indicates that no error has occurred */
    NMSP_NMAS_ERROR,                            /*!< Indicates that a generic error has occurred*/
    NMSP_NMAS_NETWORK_ERROR,                    /*!< Indicates that a network error has occurred */
    NMSP_NMAS_OUT_OF_MEMORY_ERROR,              /*!< Indicates that a memory error has occurred */
    NMSP_NMAS_CMD_ALREADY_FINISHED_ERROR,       /*!< Indicates that a command is already complete */
    NMSP_NMAS_CMD_EXPIRED_ERROR                 /*!< Indicates that a command had expired */
} NMSP_NMAS_STATUS;

/**
 * \typedef nmsp_nmas_Command
 *
 * \brief An opaque data structure.
 *
 * Represents a server-side module that contains predefined application
 * logic. The nmsp_nmas_Command object interacts with NMAS by sending nmsp_nmas_Parameter
 * objects. The results are delivered via the registered nmsp_nmas_command_eventCB
 * function.
 *
 * \see nmsp_nmas_Parameter
 **/
typedef struct nmsp_nmas_Command_ nmsp_nmas_Command;

/**
 * \typedef nmsp_nmas_Parameter
 *
 * \brief An opaque data structure.
 *
 * Represents a specific parameter that is acceptable by the server-side command module
 * hosted by NMAS. The nmsp_nmas_Parameter has various types such as: audio, binary string,
 * ASCII string, integer, data, text, dictionary, and sequence. Every predefined command
 * module has a set of acceptable parameters.
 **/
typedef struct nmsp_nmas_Parameter_ nmsp_nmas_Parameter;

/**
 * \enum NMSP_NMAS_COMMAND_EVENT
 *
 * \brief Defines the possible nmsp_nmas_Command events.
 *
 * \see nmsp_nmas_command_eventCB
 **/
typedef enum {
    NMSP_NMAS_COMMAND_TIMEDOUT_WAITING_FOR_RESULTS = 0x01,      /*!< Indicates that command timed out */
    NMSP_NMAS_COMMAND_FAILED                       = 0x02,      /*!< Indicates that command failed */
    NMSP_NMAS_COMMAND_REMOTE_DISCONNECTION         = 0x03,      /*!< Indicates that the connection was remotely disconnected */
    NMSP_NMAS_COMMAND_ENDED                        = 0x04,      /*!< Indicates that the command ended */
    NMSP_NMAS_COMMAND_IDLE_FOR_TOO_LONG            = 0x05,      /*!< Indicates that command failed because application was idle for too long */
    NMSP_NMAS_COMMAND_LOST_CONNECTION              = 0x06,      /*!< Indicates that the connection with the server was lost */
    NMSP_NMAS_COMMAND_PDX_RESPONSE                 = 0x07,      /*!< Indicates that a response was received from the server */
    NMSP_NMAS_COMMAND_DESTROYED                    = 0x08       /*!< Indicates that the command was destroyed */
} NMSP_NMAS_COMMAND_EVENT;

/**
 * \brief Callback function used to deliver the nmsp_nmas_Command
 *        event to the application, including the responses from NMAS (for example,
 *        QueryResult, QueryRetry, and QueryError).
 *
 * This callback function has to be specified by
 * the application when it creates an nmsp_nmas_Command.
 *
 * \param event             Type of the event as enumerated in NMSP_NMAS_COMMAND_EVENT.
 *                          Will not be NULL.
 *
 * \param message           Request ID, which can be used to match
 *                          the requests submitted to the resource object.
 *                          Valid only for NMSP_NMAS_COMMAND_PDX_RESPONSE.
 *                          Might be NULL if event being reported does not
 *                          require transmitting a message.
 *
 * \param user_data         Application data passed by the user application when
 *                          it creates the nmsp_nmas_Command. Used to access the
 *                          application in the callback function.
 *                          Might be NULL if user originally passed NULL.
 *
 * \see NMSP_NMAS_COMMAND_EVENT
 **/
typedef void (*nmsp_nmas_command_eventCB)(NMSP_NMAS_COMMAND_EVENT event,
                                          nmsp_nmas_Message*      message,
                                          void*                   user_data);

/**
 * \brief Creates an nmsp_nmas_Command structure.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Command structure.
 * To delete the nmsp_nmas_Command, the function nmsp_nmas_command_destroy() 
 * must be called.
.*
 * Sends a QueryBegin PDX message. Only one command is allowed
 * at a time. Creating a new command will cancel the previous one.
 * Note that the first command would still need to be deleted 
 * using nmsp_nmas_command_destroy().
 *
 *  \param nmas_resource            Pointer to the nmsp_NmasResource object.
 *                                  Must not be NULL.
 *
 *  \param command_eventCB          Pointer to an nmsp_nmas_command_eventCB function.
 *                                  Must not be NULL.
 *
 *  \param command_name             NMAS command name (UTF8).
 *                                  Must not be NULL. Must not be empty.
 *
 *  \param application_version      Application version (UTF8). 
 *                                  Must not be NULL. Must not be empty.
 *
 *  \param application_language     Application language (UTF8).
 *                                  Must not be NULL. Must not be empty.
 *
 *  \param carrier                  Carrier name (UTF8).
 *                                  Must not be NULL. Must not be empty.
 *
 *  \param phone_model              Phone model (UTF8).
 *                                  Must not be NULL. Must not be empty.
 *
 *  \param command_timeout          Command timeout value, in milliseconds.
 *                                  If no result is returned before command_timeout, the command will end.
 *                                  Must be strictly greater than zero.
 *
 *  \param optional_keys            Dictionary of key/values. Values cannot be of type: SEQUENCE or DICTIONARY.
 *                                  May be NULL.
 *
 *  \param user_data                Pointer to user data for the user to access the
 *                                  application data from the nmsp_nmas_command_eventCB
 *                                  function.
 *                                  May be NULL.
 *
 *  \return     Pointer to an nmsp_nmas_Command. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Command*
nmsp_nmas_command_create(nmsp_NmasResource*              nmas_resource,
                         const nmsp_nmas_command_eventCB command_eventCB,
                         const char*                     command_name,
                         const char*                     application_version,
                         const char*                     application_language,
                         const char*                     carrier,
                         const char*                     phone_model,
                         const long                      command_timeout,
                         const nmsp_core_Dictionary*     optional_keys,
                         void*                           user_data);

/**
 * \brief Deletes an nmsp_nmas_Command structure.
 *
 * Deallocates a previously allocated command.
 *
 * \warning You must wait for an NMSP_NMAS_COMMAND_EVENT before deleting nmsp_nmas_Command if nmsp_nmas_command_end() was called.
 * \warning You must call this function before you call nmsp_nmas_Resource_destroy().
 *
 * \param nmas_command          Pointer to an nmsp_nmas_Command.
 *                              Must not be NULL.
 *
 * \param nmas_resource         Pointer to an nmsp_NmasResource.
 *                              Must not be NULL.
 *
 * \return      NMSP_NMAS_OK if the nmsp_nmas_Command has been destroyed successfully.
 *              NMSP_NMAS_ERROR if an error occurs.
 **/
NMSP_RESOURCE_NMAS_EXPORT NMSP_NMAS_STATUS nmsp_nmas_command_destroy(nmsp_nmas_Command* nmas_command,
                                                                         nmsp_NmasResource* nmas_resource);

/**
 * \brief Creates an audio nmsp_nmas_Parameter structure.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be called.
.*
 * \warning The audio nmsp_nmas_Parameter must not be deleted while its nmsp_general_AudioSink is still receiving audio.
 * e.g.: Make sure you called nmsp_audio_recorder_stop() before deleting the nmsp_general_AudioSink passed to the nmsp_audio_Recorder.
.*
 * \param name              Audio parameter name (UTF8).
 *                          Must not be NULL.   
 *
 * \param nmas_resource     Pointer to an nmsp_NmasResource.
 *                          Must not be NULL.
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 *
 * \see nmsp_nmas_parameter_delete
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter* nmsp_nmas_audio_param_create(const char* name,
                                                                                nmsp_NmasResource* nmas_resource);

/**
 * \brief Retrieves the associated audioSink object from an NMAS audio parameter.
 *
 * This function returns a pointer to the audioSink object that is associated with
 * the Audio Parameter provided as an input to this function.
 *
 * \param audio_param       NMAS audio parameter.
 *                          Must not be NULL.
 *
 * \return      Pointer to an nmsp_general_AudioSink. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_general_AudioSink*
nmsp_nmas_audio_param_getAudioSink(const nmsp_nmas_Parameter* audio_param);

/**
 * \brief Creates a text nmsp_nmas_Parameter structure.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * text parameter.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be used.
.*
 * \param name              Text parameter name (UTF8).
 *                          Must not be NULL
 *
 * \param text              Parameter text (UTF8).
 *                          Must not be NULL.
 *
 * \param text_length       Length of text parameter, in bytes.
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter* nmsp_nmas_text_param_create(const char*          name,
                                                                           const char*          text,
                                                                           const unsigned long  text_length);

/**
 * \brief Creates a choice nmsp_nmas_Parameter structure.
 * 
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * choice parameter.
 * To delete the nmsp_nmas_Parameter, use the function nmsp_nmas_parameter_delete().
.*
 * \param name              Choice parameter name (UTF8).
 *                          Must not be NULL.
 *
 * \param choicename        Parameter choicename (UTF8).
 *                          Must not be NULL.
 *
 * \param choicename_length Length of choicename parameter, in bytes.
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter* nmsp_nmas_choice_param_create(const char*          name,
                                                                             const char*          choicename,
                                                                             const unsigned long  choicename_length);

/**
 * \brief Creates a data nmsp_nmas_Parameter.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * data parameter.
 * To delete the nmsp_nmas_Parameter, use the function nmsp_nmas_parameter_delete().
.*
 * \param name              Data parameter name (UTF8).
 *                          Must not be NULL
 *
 * \param data              Parameter data (UTF8).
 *                          Must not be NULL
 *
 * \param data_length       Length of data parameter, in bytes.
 *
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter* nmsp_nmas_data_param_create(const char*          name,
                                                                           const char*          data,
                                                                           const unsigned long  data_length);

/**
 * \brief Creates a dictionary nmsp_nmas_Parameter.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * dictionary parameter.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be called.
.*
 * \param name              Dictionary parameter name (UTF8).
 *                          Must not be NULL
 *
 * \param dictionary        nmsp_core_Dictionary pointer.
 *                          Must not be NULL
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter*
nmsp_nmas_dict_param_create(const char*                 name,
                            const nmsp_core_Dictionary* dictionary);

/**
 * \brief Creates a sequence start nmsp_nmas_Parameter.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * sequence start parameter.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be called.
.*
 * \param name              Sequence parameter name (UTF8).
 *                          Must not be NULL
 *
 * \param dictionary        nmsp_core_Dictionary pointer.
 *                          Must not be NULL
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter*
nmsp_nmas_seq_start_param_create(const char*                 name,
                                 const nmsp_core_Dictionary* dictionary);

/**
 * \brief Creates a sequence chunk nmsp_nmas_Parameter.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * sequence chunk parameter.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be called.
.*
 * \param name             Parameter name (UTF8).
 *                         Must not be NULL
 *
 * \param dictionary       nmsp_core_Dictionary pointer.
 *                         Must not be NULL
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter*
nmsp_nmas_seq_chunk_param_create(const char*                 name,
                                 const nmsp_core_Dictionary* dictionary);

/**
 * \brief Creates a sequence end nmsp_nmas_Parameter.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * sequence end parameter.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be called.
.*
 * \param name              Parameter name (UTF8).
 *                          Must not be NULL
 *
 * \param dictionary        nmsp_core_Dictionary pointer.
 *                          Must not be NULL
 *
 * \return      Pointer to an nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter*
nmsp_nmas_seq_end_param_create(const char*                 name,
                               const nmsp_core_Dictionary* dictionary);

/**
 * \brief Creates a TTS (text-to-speech) nmsp_nmas_Parameter.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * sequence TTS parameter.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be called.
.*
 * \warning The nmsp_general_AudioSink must not be deleted while it is still receiving audio
 * i.e. until an NMSP_NMAS_COMMAND_EVENT is received.
.*
 * \param name              Parameter name (UTF8).
 *                          Must not be NULL
 *
 * \param dictionary        nmsp_core_Dictionary pointer.
 *                          Must not be NULL
 *
 * \param audio_sink        Pointer to an nmsp_general_AudioSink object to
 *                          which the synthesized buffers are sent. (Could be
 *                          an audio player that has the NMSPAudioSink functionality.)
 *                          Must not be NULL
 *
 * \param nmas_resource     Pointer to an nmsp_NmasResource.
 *                          Must not be NULL
 *
 *  \return     Pointer to a TTS nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter*
nmsp_nmas_tts_param_create(const char*                   name,
                           const nmsp_core_Dictionary*   dictionary,
                           const nmsp_general_AudioSink* audio_sink,
                           nmsp_NmasResource*            nmas_resource);


/**
 * \brief Creates a TTS (text-to-speech) text nmsp_nmas_Parameter.
 *
 * Returns a pointer to a newly allocated nmsp_nmas_Parameter structure that describes a 
 * sequence TTS Text parameter.
 * To delete the nmsp_nmas_Parameter, the function nmsp_nmas_parameter_delete() must be called.
.*
 * \warning The nmsp_general_AudioSink must not be deleted while it is still receiving audio
 * i.e. until an NMSP_NMAS_COMMAND_EVENT is received.
.*
 * \param tts_text          the text-to-speech text.
 *                          Must not be NULL.
 *
 * \param tts_text_length   the length of the text assigned to parameter tts_text.
 *                          Must not be NULL.
 *
 * \param audio_sink        Pointer to an nmsp_general_AudioSink object to
 *                          which the synthesized buffers are sent. (Could be
 *                          an audio player that has the NMSPAudioSink functionality.)
 *                          Must not be NULL.
 *
 *  \return     Pointer to a TTS nmsp_nmas_Parameter. If an error occurs, NULL is returned.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Parameter*
nmsp_nmas_tts_text_param_create(const char*                   tts_text,
                                const unsigned long           tts_text_length,
                                const nmsp_general_AudioSink* audio_sink);

/**
 * \brief Deletes an nmsp_nmas_Parameter.
 *
 * Deletes a previously allocated nmsp_nmas_Parameter, and frees the corresponding memory space.
 *
 * \note An nmsp_nmas_Parameter can be safely deleted as soon it is passed to the function
 * nmsp_nmas_command_send_parameter() except for audio and tts parameters.
 *
 * \param parameter         Pointer to an nmsp_nmas_Parameter object.
 *                          Must not be NULL.
 **/
NMSP_RESOURCE_NMAS_EXPORT void nmsp_nmas_parameter_delete(nmsp_nmas_Parameter* parameter);

/**
 * \brief Sends an nmsp_nmas_Parameter by sending a QueryParameter PDX message.
 *
 * This function sends an nmsp_nmas_Parameter as part of the command being handled.
 * The parameter sent is expected to be compatible with the command used.
 *
 * \param command           Pointer to the nmsp_nmas_Command.
 *                          Must not be NULL.
 *
 * \param parameter         Pointer to the nmsp_nmas_Parameter to be sent.
 *                          Must not be NULL.
 *
 * \return      NMSP_NMAS_OK if the parameter is sent successfully.
 *              NMSP_NMAS_ERROR if an error occurs.
 *              NMSP_NMAS_OUT_OF_MEMORY_ERROR if memory allocation fails.
 **/
NMSP_RESOURCE_NMAS_EXPORT NMSP_NMAS_STATUS
nmsp_nmas_command_send_parameter(nmsp_nmas_Command*         command,
                                 const nmsp_nmas_Parameter* parameter);

/**
 * \brief Sends an enrollment audio file to NMAS.
 *
 * The enrollment service generates
 * a user profile containing audio files that train the dictation service in
 * the subscriber's speech patterns.
 *
 * \param command           Pointer to the nmsp_nmas_Command.
 *                          Must not be NULL.
 *
 * \param audio             Audio to be sent.
 *                          Must not be NULL.
 *
 * \param length            Length of the audio binary data, in bytes.
 *                          Must be strictly greater than zero
 *
 * \return      NMSP_NMAS_OK if the parameter is sent successfully.
 *              NMSP_NMAS_ERROR if an error occurs.
 *              NMSP_NMAS_OUT_OF_MEMORY_ERROR if memory allocation fails.
 **/
NMSP_RESOURCE_NMAS_EXPORT NMSP_NMAS_STATUS
nmsp_nmas_command_send_enrollment_audio(nmsp_nmas_Command* command,
                                        const char*        audio,
                                        unsigned long      length);

/**
 * \brief Terminates the command by sending a QueryEnd PDX message.
 *
 * This command indicates to the server that all the necessary parameters
 * have been sent and that the command has now ended.
 *
 * \param command           Pointer to the nmsp_nmas_Command object.
 *                          Must not be NULL.
 *
 * \return      NMSP_NMAS_OK if the command ends successfully.
 *              NMSP_NMAS_ERROR if an error occurs.
 *              NMSP_NMAS_OUT_OF_MEMORY_ERROR if memory allocation fails.
 **/
NMSP_RESOURCE_NMAS_EXPORT NMSP_NMAS_STATUS nmsp_nmas_command_end(nmsp_nmas_Command* command);

/**
 * \brief Retrieves message data. Deprecated, use nmsp_core_get_dictionary
_xxxx_value(key, message->dictionary, length).
 *
 * For a specified key, this function retrieves the corresponding data from the message and
 * returns a pointer to it. This pointer should then be cast to the right data type, in 
 * order to properly access the data.
 *
 * \param key               Message data key.
 *                          Must not be NULL.
 *
 * \param message           Pointer to an nmsp_nmas_Message.
 *                          Must not be NULL.
 *
 * \param length            Pointer to a long integer, in which the length in bytes of 
 *                          the return data will be stored. Must be already pointing to a pre-existing long integer.
 *                          Must not be NULL.
 *
 * \return      Pointer to binary NMAS data.
 *              Depending on the type of the value, this pointer should be cast to one of:
 *              char*, int, nmsp_core_Sequence*, or nmsp_core_Dictionary*.
 *              If an error occurs, NULL is returned.
 *
 * \see nmsp_nmas_Message
 * \see nmsp_core_Dictionary
 * \see nmsp_nmas_KeyValue
 * \see nmsp_nmas_Data
 * \see NMSP_CORE_CLASS_TYPE
 **/
NMSP_RESOURCE_NMAS_EXPORT const void* nmsp_nmas_get_message_value(const char*              key,
                                                            const nmsp_nmas_Message* message,
                                                            unsigned long*           length);


/**
 * \brief Makes a copy of a nmsp_nmas_Message.
 *
 * This function returns a pointer to a newly allocated copy of an existing message.
 * The resulting message should be deleted with nmsp_nmas_message_delete().
 *
 * \param message                   Pointer to a nmsp_nmas_Message.
 *                                  Must not be NULL.
 **/
NMSP_RESOURCE_NMAS_EXPORT nmsp_nmas_Message* nmsp_nmas_message_copy(const nmsp_nmas_Message* message);

/**
 * \brief Deletes local copy of a nmsp_nmas_Message.
 *
 * This function deletes a previously allocated copy of an nmsp_nmas_Message.
 *
 * \param message                   Pointer to a nmsp_nmas_Message.
 **/
NMSP_RESOURCE_NMAS_EXPORT void nmsp_nmas_message_delete(nmsp_nmas_Message* message);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_RESOURCE_NMAS */
