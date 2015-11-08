#ifndef NMSP_CORE_CALLLOG_SENDER_H
#define NMSP_CORE_CALLLOG_SENDER_H
/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/

/** \file nmsp_core_calllog_sender.h
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
#include <nmsp_oem/nmsp_vector.h>
#include <nmsp_core/nmsp_core_defines.h>
#include <nmsp_core/nmsp_core_calllog_sessionevent.h>
    
/**
 * \typedef nmsp_CalllogSender
 **/
typedef struct nmsp_CalllogSender_ nmsp_CalllogSender;

/**
 * \enum NMSP_MANAGER_EVENT
 *
 * \brief Defines the possible events of the nmsp_CalllogSender
 * 
 * These events are used to indicate to the nmsp_calllogSender_eventCB callback 
 * that a particular calllog sender event has occurred.
 *
 * \see nmsp_calllogSender_eventCB
 **/
typedef enum 
{
    NMSP_CALLLOG_SENDER_SUCCEEDED            = 0x01,    /*!< Indicates that call log data has been sent to gateway successfully */
    NMSP_CALLLOG_SENDER_FAILED               = 0x02,    /*!< Indicates that call log data failed to be sent to gateway */
	NMSP_CALLLOG_SENDER_DESTROYED            = 0x03,    /*!< Indicates that sender has been successfully destroyed */
} NMSP_CALLLOG_SENDER_EVENT;

/**
 * \enum NMSP_CALLLOG_SENDER_ERRORCODE
 *
 * \brief Defines the possible error code of call log transmission failures.
 *
 * \see nmsp_calllogSender_eventCB
 **/
typedef enum
{
    NMSP_CALLLOG_SENDER_NO_ERROR                = 0x00,    /*!< Indicates there is no error and the call log data is sent successfully */
    NMSP_CALLLOG_SENDER_ERROR_OUT_OF_MEMORY     = 0x01,    /*!< Indicates out of memory */
    NMSP_CALLLOG_SENDER_ERROR_NETWORK           = 0x02,    /*!< Indicates there is a network error */
    NMSP_CALLLOG_SENDER_ERROR_INVALID_DATA      = 0x03,    /*!< Indicates the call log data to be sent is invalid */
    NMSP_CALLLOG_SENDER_ERROR_CONNECTION_FAILED = 0x04     /*!< Indicates the connection failed */
} NMSP_CALLLOG_SENDER_ERRORCODE;

/**
 * typedef nmsp_CalllogSender_EventData
 *
 * \see nmsp_calllogSender_eventCB
 **/
typedef struct
{
    NMSP_CALLLOG_SENDER_ERRORCODE  status_code; /*!< the status code of sending the call log data */
    const char*                    buffer;      /*!< the binary call log data passed in to the nmsp_calllogSender_send function */
} nmsp_CalllogSender_EventData;

/**
 * \brief Callback function. Called to notify the application of calllog sender events.
 *
 * An implementation of this callback function needs to be passed to the  nmsp_calllogSender_send
 * function. 
 *
 * \param event               event occurring in the process of sending the call log data to the Gateway.
 *                            Possible events are defined in NMSP_CALLLOG_SENDER_EVENT.
 *
 * \param event_data          event_data is associated with NMSP_CALLLOG_SENDER_EVENT event, containing the
 *                            call log data information and status_code of the call log transmission. The
 *                            application can use this information to manage the call log data: resend in
 *                            case of failure or clean up the data in case of success.
 *                            Cannot be NULL.
 *
 * \param user_data           Pointer to the application data needed to re-create the context of a function
 *                            call. Originally passed in nmsp_calllogSender_create.
 *                            Might be NULL, if application originally passed NULL.
 *
 * \see NMSP_CALLLOG_SENDER_EVENT
 * \see nmsp_CalllogSender_EventData
 * \see nmsp_calllogSender_send
 **/
typedef void (*nmsp_calllogSender_eventCB) (NMSP_CALLLOG_SENDER_EVENT event, nmsp_CalllogSender_EventData* event_data, void* user_data);

/**
 * \brief Create the CallogSender, there is only one call log sender allowed at a time.
 *
 * \param eventCB        The call back function to monitor the status of the call log transmission and
 *                       the status of the calllog sender object itself. (\see NMSP_CALLLOG_SENDER_DESTROYED)
 *                       Must not be NULL.
 *
 * \param user_data      A pointer to the application data needed to re-create the context of a function
 *                       call. It might be NULL.
 *
 * \return               A pointer to the nmsp_CalllogSender object.
 **/
NMSP_CORE_EXPORT nmsp_CalllogSender* nmsp_calllogSender_create(nmsp_calllogSender_eventCB eventCB, void* user_data);

/**
 * \brief deletes the given nmsp_CalllogSender object.
 *
 * \param calllogSender     A pointer to the nmsp_CallogSender object
 *                          Must not be NULL.
 *
 * \return      NMSP_OK    if the calllogSender is destroyed successfully.
 *              NMSP_ERROR if an error occurs.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllogSender_destroy(nmsp_CalllogSender* calllogSender);

/**
 * \brief Does the final synchronous cleanup of the nmsp_calllogSender.
 *
 * This function is responsible for doing the final cleanup of the nmsp_calllogSender that is
 * required to be done from the application thread, most notably stopping/destroying the
 * message system. This is a synchronous, though not heavy call.
 * \warning The application must wait for the NMSP_CALLLOG_SENDER_DESTROYED event before making this call.
 *
 * \param calllogSender     An nmsp_calllogSender.
 *                          Must not be NULL.
 *
 * \return      NMSP_CORE_OK     cleanup done successfully. Cannot fail.
*/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllogSender_cleanup(nmsp_CalllogSender* calllogSender);

/**
 * Send the binary call log data to the server. This is used to send the binary call log data
 * obtained from the nmsp_manager_eventCB with the event NMSP_MANAGER_DESTROYED after manager
 * is shut down or from the calllog sender's callback function nmsp_calllogSender_eventCB
 * with the event NMSP_CALLLOG_SENDER_FAILED.
 *
 * \param calllogSender     A Pointer to the nmsp_calllogSender object, Must not be NULL.
 *
 * \param buffer            A pointer to the buffer to send. The buffer has its size embedded inside
 *                          with a size_t|payload format. Must not be NULL.
 *
 * \return NMSP_OK    if the sender can successfully start the sending process
 *         NMSP_ERROR if the sender encounters any error and can not start the sending process 
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_calllogSender_send(nmsp_CalllogSender* calllogSender, const char* buffer);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_CORE_CALLLOG_H */
