#ifndef NMSP_CORE_DEFINES_H
#define NMSP_CORE_DEFINES_H

/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/

/** \file nmsp_core_defines.h
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

#include <nmsp_oem/nmsp_platform.h>

/**
 * \enum NMSP_CORE_STATUS
 *
 * \brief Defines the possible status of nmsp_core operations.
 *
 */
typedef enum {
    NMSP_CORE_OK                            = 0x00,               /*!< Indicates success */
    NMSP_CORE_ERROR                         = 0x01,               /*!< Indicates a generic error */
    NMSP_CORE_OUTOFMEMORY_ERROR             = 0x02,               /*!< Indicates an out-of-memory error */
    NMSP_CORE_SESSIONEVENT_COMMITTED_ERROR  = 0x03                /*!< Indicates error of trying add attribute after session event committed */
} NMSP_CORE_STATUS;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_CORE_DEFINES_H */
