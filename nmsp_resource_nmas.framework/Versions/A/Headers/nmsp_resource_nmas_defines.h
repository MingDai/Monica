#ifndef NMSP_RESOURCE_NMAS_DEFINES
#define NMSP_RESOURCE_NMAS_DEFINES
/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/

/** \file nmsp_resource_nmas_defines.h
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
 *   This file provides global definitions that are to be used by the application
 *   and by the NMAS resource itself. for example, NMAS class types and command types.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <nmsp_core/nmsp_core_pdx.h>

/**
 * \enum NMSP_NMAS_COMMAND_TYPE
 *
 * \brief Defines the possible NMAS command types, which are used to
 *        identify the nmsp_nmas_Message objects.
 *
 * \see nmsp_nmas_Message
 **/
typedef enum {
//  GET_SCRIPT_UPDATE          = 0x0101,
    QUERY_BEGIN                = 0x0202,        /*!< Indicates a query begin message */
    QUERY_PARAMETER            = 0x0203,        /*!< Indicates a query parameter message */
    QUERY_END                  = 0x0204,        /*!< Indicates a query end message */
    ENROLLMENT_SEGMENT         = 0x0400,        /*!< Indicates an enrollment message */
    ENROLLMENT_AUDIO           = 0x0402,        /*!< Indicates an enrollment audio message */
//  EnrollementComplete        = 0x0401,
//  DiagnosticLogUpdate        = 0x0500,
    QUERY_RESULT               = 0x7201,        /*!< Indicates a query result message */
    QUERY_ERROR                = 0x7202,        /*!< Indicates a query error message */
//  QueryDisambiguate          = 0x7203,
//  QueryNarrow                = 0x7204,
    QUERY_RETRY                = 0x7205         /*!< Indicates a query retry message */
//  EnrollementText            = 0x7400,
//  SCRIPT_UPDATE_AVAILABLE    = 0x7300,
//  UPDATE_BLOCK               = 0x7301,
//  NO_SCRIPT_UPDATE_AVAILABLE = 0x7302
} NMSP_NMAS_COMMAND_TYPE;


/**
 * \struct nmsp_nmas_Message
 *
 * \brief This structure represents an NMAS message.
 * 
 * This structure contains both the command type and an nmsp_core_Dictionary
 * object. This structure contains the result of a command creation and is  
 * delivered to te application via a callback.
 *
 * /see nmsp_nmas_command_eventCB
 **/
typedef struct {
    NMSP_NMAS_COMMAND_TYPE cmd;
    nmsp_core_Dictionary*  dictionary;
} nmsp_nmas_Message;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_RESOURCE_NMAS_DEFINES */
