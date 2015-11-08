#ifndef NMSP_CORE_UTIL
#define NMSP_CORE_UTIL

/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/

/** \file nmsp_core_util.h
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

#include <stdio.h>
#include <string.h>
  
NMSP_CORE_EXPORT char* escapeXML(const char* source);

NMSP_CORE_EXPORT unsigned long escapeXMLlen(const char* source);

/**
 * \brief Gets version number string.
 *
 * This function returns the NMSP SDK version. E.g., "3.6.01"
 *
 * \return     Character pointer string containing version number.
 *
 **/
NMSP_CORE_EXPORT const char* nmsp_getVersion(void);

/**
* \brief Gets a unique id.
*
* This function returns a unique ID identifying the device the NMSP SDK
* is running on.
*
* \return     Character pointer string containing unique id or NULL if not available.
*
*
**/
NMSP_CORE_EXPORT const char* nmsp_getUniqueID(void);


/**
* \brief Gets the device model name.
*
* This function returns the model of the device the NMSP SDK
* is running on.
*
* \return     Character pointer string containing device name or NULL if not available.
*
*
**/
NMSP_CORE_EXPORT const char* nmsp_getDeviceModel(void);

/**
* \brief Gets the device sub model name.
*
* This function returns the sub model of the device the NMSP SDK
* is running on, such as "3GS, galaxy , Q5".
*
* \return     Character pointer string containing device name or NULL if not available.
*
*
**/
NMSP_CORE_EXPORT const char* nmsp_getDeviceSubModel(void);

/**
* \brief Gets the operator name.
*
* This function returns the operator name of the device the NMSP SDK is
* running on.
*
* \return     Character pointer string containing operator name or NULL if not available.
*
**/

NMSP_CORE_EXPORT const char* nmsp_getOperatorName(void);


/**
* \brief Gets the phone number.
*
* This function returns the phone number of the device the NMSP SDK is
* running on.
*
* \return     Character pointer string containing phone number or NULL if not available.
*
*
**/

NMSP_CORE_EXPORT const char* nmsp_getPhoneNumber(void);

/**
* \brief Gets the OS tyep
* 
* This function returns the OS version on which the NMSP SDK is running.
* E.g., "iOS" or "Android"
*
* \return     Character pointer string containing OS version or NULL if not available.
*
*
**/
NMSP_CORE_EXPORT const char* nmsp_getOSType(void);

/**
* \brief Gets the OS version
* 
* This function returns the OS version on which the NMSP SDK is running.
* E.g., "3.1.3" or "4.0"
*
* \return     Character pointer string containing OS version or NULL if not available.
*
*
**/
NMSP_CORE_EXPORT const char* nmsp_getOSVersion(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*NMSP_CORE_UTIL*/
