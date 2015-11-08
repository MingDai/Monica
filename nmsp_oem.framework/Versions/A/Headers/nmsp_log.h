#ifndef NMSP_LOG_INCLUDED
#define NMSP_LOG_INCLUDED
/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/
/** \file nmsp_log.h
 *
 *			NMSP Parameter-Related Definitions
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
 *  \Overview
 *
 *  Contains session-related parameters that an NMSP device application can
 *  retrieve and set in the NMSP Gateway configuration file, the Nuance Speech
 *  Server (NSS) configuration file, and in the SDK to modify the operation of
 *  the NMSP Gateway or the application while it is executing. See the
 *  SDK <em>Programmer's Guide</em> for more information.
 *
 *  Note that modifications apply on a NMSP session basis only.
 *
 */

#include <nmsp_oem/nmsp_platform.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
    * \brief Logging Level Definitions
    **/
    typedef enum {
        NMSP_LOG_LEVEL_NONE  = 0x0,
        NMSP_LOG_LEVEL_ERROR = 0x1,
        NMSP_LOG_LEVEL_WARN  = 0x2,
        NMSP_LOG_LEVEL_INFO  = 0x4,
        NMSP_LOG_LEVEL_DEBUG = 0x8,
        NMSP_LOG_LEVEL_TRACE = 0x10,
        NMSP_LOG_LEVEL_PROFILE = 0x20
    } NMSP_LOG_LEVEL;

    /**
     * structure that contains all the relevant log information transmitted to the client.
     */
    typedef struct 
    {
        void* pCallbackData;            /**< Application data user specified in the setNmtLogCallback function */
        NMSP_LOG_LEVEL eLoggingLevel;     /**< NMT log level */
        long long      iSystemTime;		  /**< Time, in nanoseconds, retrieved from the system clock (wall lock), based on epoch Jan 1 1970. */
        const char*    sMessage;          /**< UTF8 encoded C string containing the message, guaranteed to be non-null when instance received by \ref FNmtLogCallback */
        const char*    sFuncName;         /**< C string containing the undecorated function/method name of the log entry */
        const char*    sFilePath;         /**< C string containing the relative source file path of the log entry */
        unsigned int   nFileLineNo;       /**< Line number in the source file of the log entry */
    } nmsp_log_data;

    /**
    * \brief Logging callback function definition.
    *
    * This will be defined in the SDK user's application, this function will
    * be called every time the SDK tries to log an event. And it is absolutely
    * up to the application to decide what to do with the log. For example, the
    * application can choose to print out the log to the standard output or save
    * them into a file on the file system.
    *
    * Multiple threads can and will call this callback simultaneously.
    *
    * \param data Reference to a \ref NmtLogInfo instance containing all log entry information.
    *
    * \return void
    **/
    typedef void (*nmsp_logCallback)(nmsp_log_data data);

    /**
    * \brief set the logging callback function pointer
    *
    * If there is no logging callback being set, the logs will not be handled.
    *
    * \param callback      The nmsp_logCallback function defined by the
    *                      application (cannot be NULL)
    * \param context       The application data user specified, which will be
    *                      passed back in the callback function (may be NULL)
    * \return void
    */
    NMSP_IMPORT_EXPORT_CONVENTION void nmsp_log_setCallback(nmsp_logCallback callback, void* context);

    /**
    * \brief the global logging level for the entire application
    *
    * This function can be called multiple times during application's life time, the SDK will only log
    * the logs with the associated level flag turned on
    *
    * \param loggingLevel  The logging level flag
    * \return void
    */
    NMSP_IMPORT_EXPORT_CONVENTION void nmsp_log_setLogLevel(int loggingLevel);

    /**
    * \brief retrieve the current global logging level Flag
    *
    * \return the current global logging level Flag
    */
    NMSP_IMPORT_EXPORT_CONVENTION int nmsp_log_getLogLevel();

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_LOG_INCLUDED */
