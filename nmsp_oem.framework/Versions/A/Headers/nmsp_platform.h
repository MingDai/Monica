/*---------------------------------------------------------------------------*
 * Copyright 2006-2011, Nuance Communications Inc. All rights reserved.      *
 *                                                                           *
 * Nuance Communications, Inc. provides this document without representation *
 * or warranty of any kind. The information in this document is subject to   *
 * change without notice and does not represent a commitment by Nuance       *
 * Communications, Inc. The software and/or databases described in this      *
 * document are furnished under a license agreement and may be used or       *
 * copied only in accordance with the terms of such license agreement.       *
 * Without limiting the rights under copyright reserved herein, and except   *
 * as permitted by such license agreement, no part of this document may be   *
 * reproduced or transmitted in any form or by any means, including, without *
 * limitation, electronic, mechanical, photocopying, recording, or otherwise,*
 * or transferred to information storage and retrieval systems, without the  *
 * prior written permission of Nuance Communications, Inc.                   *
 *                                                                           *
 * Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are      *
 * trademarks or registered trademarks of Nuance Communications, Inc. or its *
 * affiliates in the United States and/or other countries. All other         *
 * trademarks referenced herein are the property of their respective owners. *
 *---------------------------------------------------------------------------*/
#ifndef NMSP_PLATFORM_INCLUDED
#define NMSP_PLATFORM_INCLUDED


#if defined(_BREW_STATIC)
    #define NMSP_IMPORT_EXPORT_CONVENTION
    #define VST_IMPORT_EXPORT_CONVENTION

	#define NMSP_CORE_EXPORT 
    #define NMSP_RESOURCE_COMMON_EXPORT
    #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
    #define NMSP_RESOURCE_DICTATION_EXPORT
	#define NMSP_RESOURCE_NMAS_EXPORT 
	#define NMSP_RESOURCE_RECOGNITION_EXPORT 
	#define NMSP_RESOURCE_TTS_EXPORT 
	#define NMSP_AUDIOPLAYBACK_EXPORT 
	#define NMSP_AUDIORECORD_EXPORT 
    #define NMSP_DICTATIONRESULT_EXPORT

#elif defined(_BREW)
    #if defined(_AEE_SIMULATOR)
        #undef NMSP_IMPORT_EXPORT_CONVENTION
        #undef VST_IMPORT_EXPORT_CONVENTION
        #undef NMSP_RESOURCE_COMMON_EXPORT
        #undef NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
        #undef NMSP_RESOURCE_DICTATION_EXPORT
        #if defined (NMSP_MEM_LEAK)
			#define NMSP_IMPORT_EXPORT_CONVENTION
			#define VST_IMPORT_EXPORT_CONVENTION

			#define NMSP_CORE_EXPORT 
			#define NMSP_RESOURCE_COMMON_EXPORT
			#define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
			#define NMSP_RESOURCE_DICTATION_EXPORT
			#define NMSP_RESOURCE_NMAS_EXPORT 
			#define NMSP_RESOURCE_RECOGNITION_EXPORT 
			#define NMSP_RESOURCE_TTS_EXPORT 
			#define NMSP_AUDIOPLAYBACK_EXPORT 
			#define NMSP_AUDIORECORD_EXPORT 
			#define NMSP_DICTATIONRESULT_EXPORT
		#else
			#ifdef NMSP_OEM_EXPORTS
			  #define NMSP_IMPORT_EXPORT_CONVENTION __declspec(dllexport)
			  #define VST_IMPORT_EXPORT_CONVENTION __declspec(dllexport)
			#else
			  #define NMSP_IMPORT_EXPORT_CONVENTION __declspec(dllimport)
			  #define VST_IMPORT_EXPORT_CONVENTION __declspec(dllimport)
			#endif

			#ifdef NMSP_CORE_EXPORTS
				#define NMSP_CORE_EXPORT __declspec(dllexport)
			#else 
				#define NMSP_CORE_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_RESOURCE_COMMON_EXPORTS
				#define NMSP_RESOURCE_COMMON_EXPORT __declspec(dllexport)
			#else
				#define NMSP_RESOURCE_COMMON_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_RESOURCE_COMMON_REC_EXPORTS
				#define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT __declspec(dllexport)
			#else
				#define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_RESOURCE_DICTATION_EXPORTS
				#define NMSP_RESOURCE_DICTATION_EXPORT __declspec(dllexport)
			#else
				#define NMSP_RESOURCE_DICTATION_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_RESOURCE_NMAS_EXPORTS
				#define NMSP_RESOURCE_NMAS_EXPORT __declspec(dllexport)
			#else
				#define NMSP_RESOURCE_NMAS_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_RESOURCE_RECOGNITION_EXPORTS
				#define NMSP_RESOURCE_RECOGNITION_EXPORT __declspec(dllexport)
			#else
				#define NMSP_RESOURCE_RECOGNITION_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_RESOURCE_TTS_EXPORTS
				#define NMSP_RESOURCE_TTS_EXPORT __declspec(dllexport)
			#else
				#define NMSP_RESOURCE_TTS_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_AUDIOPLAYBACK_EXPORTS
				#define NMSP_AUDIOPLAYBACK_EXPORT __declspec(dllexport)
			#else
				#define NMSP_AUDIOPLAYBACK_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_AUDIORECORD_EXPORTS
				#define NMSP_AUDIORECORD_EXPORT __declspec(dllexport)
			#else
				#define NMSP_AUDIORECORD_EXPORT __declspec(dllimport)
			#endif

			#ifdef NMSP_DICTATION_EXPORTS
				#define NMSP_DICTATIONRESULT_EXPORT __declspec(dllexport)
			#else
				#define NMSP_DICTATIONRESULT_EXPORT __declspec(dllimport)
			#endif

        #endif
    #else
		#define NMSP_IMPORT_EXPORT_CONVENTION
		#define VST_IMPORT_EXPORT_CONVENTION

		#define NMSP_CORE_EXPORT 
		#define NMSP_RESOURCE_COMMON_EXPORT
		#define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
		#define NMSP_RESOURCE_DICTATION_EXPORT
		#define NMSP_RESOURCE_NMAS_EXPORT 
		#define NMSP_RESOURCE_RECOGNITION_EXPORT 
		#define NMSP_RESOURCE_TTS_EXPORT 
		#define NMSP_AUDIOPLAYBACK_EXPORT 
		#define NMSP_AUDIORECORD_EXPORT 
		#define NMSP_DICTATIONRESULT_EXPORT
    #endif
#elif defined(__APPLE_CC__) || defined(__ANDROID__)
    #define NMSP_IMPORT_EXPORT_CONVENTION
    #define VST_IMPORT_EXPORT_CONVENTION

	#define NMSP_CORE_EXPORT 
    #define NMSP_RESOURCE_COMMON_EXPORT
    #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
    #define NMSP_RESOURCE_DICTATION_EXPORT
	#define NMSP_RESOURCE_NMAS_EXPORT 
	#define NMSP_RESOURCE_RECOGNITION_EXPORT 
	#define NMSP_RESOURCE_TTS_EXPORT 
	#define NMSP_AUDIOPLAYBACK_EXPORT 
	#define NMSP_AUDIORECORD_EXPORT 
    #define NMSP_DICTATIONRESULT_EXPORT

    #define NMSP_CPL_ENABLED

#elif defined(QT_CORE_LIB)

    #define NMSP_IMPORT_EXPORT_CONVENTION
    #define VST_IMPORT_EXPORT_CONVENTION

	#define NMSP_CORE_EXPORT 
    #define NMSP_RESOURCE_COMMON_EXPORT
    #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
    #define NMSP_RESOURCE_DICTATION_EXPORT
	#define NMSP_RESOURCE_NMAS_EXPORT 
	#define NMSP_RESOURCE_RECOGNITION_EXPORT 
	#define NMSP_RESOURCE_TTS_EXPORT 
	#define NMSP_AUDIOPLAYBACK_EXPORT 
	#define NMSP_AUDIORECORD_EXPORT 
    #define NMSP_DICTATIONRESULT_EXPORT

    #define NMSP_CPL_ENABLED

#elif defined(SYMBIAN_S60_MR)

    //#define NMSP_IMPORT_EXPORT_CONVENTION IMPORT_C
    //#define VST_IMPORT_EXPORT_CONVENTION IMPORT_C

    #define NMSP_IMPORT_EXPORT_CONVENTION
    #define VST_IMPORT_EXPORT_CONVENTION

	#define NMSP_CORE_EXPORT
    #define NMSP_RESOURCE_COMMON_EXPORT
    #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
    #define NMSP_RESOURCE_DICTATION_EXPORT
	#define NMSP_RESOURCE_NMAS_EXPORT
	#define NMSP_RESOURCE_RECOGNITION_EXPORT
	#define NMSP_RESOURCE_TTS_EXPORT
	#define NMSP_AUDIOPLAYBACK_EXPORT
	#define NMSP_AUDIORECORD_EXPORT
    #define NMSP_DICTATIONRESULT_EXPORT

// BB10
#elif defined(__QNX__)
    #define NMSP_IMPORT_EXPORT_CONVENTION
    #define VST_IMPORT_EXPORT_CONVENTION

	#define NMSP_CORE_EXPORT
    #define NMSP_RESOURCE_COMMON_EXPORT
    #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
    #define NMSP_RESOURCE_DICTATION_EXPORT
	#define NMSP_RESOURCE_NMAS_EXPORT
	#define NMSP_RESOURCE_RECOGNITION_EXPORT
	#define NMSP_RESOURCE_TTS_EXPORT
	#define NMSP_AUDIOPLAYBACK_EXPORT
	#define NMSP_AUDIORECORD_EXPORT
    #define NMSP_DICTATIONRESULT_EXPORT

	#define NMSP_CPL_ENABLED

#elif defined(QNX_650)

    //#define NMSP_IMPORT_EXPORT_CONVENTION IMPORT_C
    //#define VST_IMPORT_EXPORT_CONVENTION IMPORT_C

    #define NMSP_IMPORT_EXPORT_CONVENTION
    #define VST_IMPORT_EXPORT_CONVENTION

	#define NMSP_CORE_EXPORT
    #define NMSP_RESOURCE_COMMON_EXPORT
    #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
    #define NMSP_RESOURCE_DICTATION_EXPORT
	#define NMSP_RESOURCE_NMAS_EXPORT
	#define NMSP_RESOURCE_RECOGNITION_EXPORT
	#define NMSP_RESOURCE_TTS_EXPORT
	#define NMSP_AUDIOPLAYBACK_EXPORT
	#define NMSP_AUDIORECORD_EXPORT
    #define NMSP_DICTATIONRESULT_EXPORT

#elif defined(NMSP_OEM_LINUX)
    #define NMSP_IMPORT_EXPORT_CONVENTION
    #define VST_IMPORT_EXPORT_CONVENTION

	#define NMSP_CORE_EXPORT
    #define NMSP_RESOURCE_COMMON_EXPORT
    #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
    #define NMSP_RESOURCE_DICTATION_EXPORT
	#define NMSP_RESOURCE_NMAS_EXPORT
	#define NMSP_RESOURCE_RECOGNITION_EXPORT
	#define NMSP_RESOURCE_TTS_EXPORT
	#define NMSP_AUDIOPLAYBACK_EXPORT
	#define NMSP_AUDIORECORD_EXPORT
    #define NMSP_DICTATIONRESULT_EXPORT

#elif defined(WPRT_STATIC)
#define NMSP_IMPORT_EXPORT_CONVENTION
#define VST_IMPORT_EXPORT_CONVENTION

#define NMSP_CORE_EXPORT
#define NMSP_RESOURCE_COMMON_EXPORT
#define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
#define NMSP_RESOURCE_DICTATION_EXPORT
#define NMSP_RESOURCE_NMAS_EXPORT
#define NMSP_RESOURCE_RECOGNITION_EXPORT
#define NMSP_RESOURCE_TTS_EXPORT
#define NMSP_AUDIOPLAYBACK_EXPORT
#define NMSP_AUDIORECORD_EXPORT
#define NMSP_DICTATIONRESULT_EXPORT

#else
    #undef NMSP_IMPORT_EXPORT_CONVENTION
    #undef VST_IMPORT_EXPORT_CONVENTION
    #if defined (NMSP_MEM_LEAK)
		#define NMSP_IMPORT_EXPORT_CONVENTION
		#define VST_IMPORT_EXPORT_CONVENTION

		#define NMSP_CORE_EXPORT 
		#define NMSP_RESOURCE_COMMON_EXPORT
		#define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT
		#define NMSP_RESOURCE_DICTATION_EXPORT
		#define NMSP_RESOURCE_NMAS_EXPORT 
		#define NMSP_RESOURCE_RECOGNITION_EXPORT 
		#define NMSP_RESOURCE_TTS_EXPORT 
		#define NMSP_AUDIOPLAYBACK_EXPORT 
		#define NMSP_AUDIORECORD_EXPORT 
		#define NMSP_DICTATIONRESULT_EXPORT
    #else

	#ifdef NMSP_OEM_EXPORTS
      #define NMSP_IMPORT_EXPORT_CONVENTION __declspec(dllexport)
      #define VST_IMPORT_EXPORT_CONVENTION __declspec(dllexport)
    #else
      #define NMSP_IMPORT_EXPORT_CONVENTION __declspec(dllimport)
      #define VST_IMPORT_EXPORT_CONVENTION __declspec(dllimport)
    #endif

	#ifdef NMSP_CORE_EXPORTS
		#define NMSP_CORE_EXPORT __declspec(dllexport)
	#else 
		#define NMSP_CORE_EXPORT __declspec(dllimport)
	#endif

    #ifdef NMSP_RESOURCE_COMMON_EXPORTS
        #define NMSP_RESOURCE_COMMON_EXPORT __declspec(dllexport)
    #else
        #define NMSP_RESOURCE_COMMON_EXPORT __declspec(dllimport)
    #endif

    #ifdef NMSP_RESOURCE_COMMON_REC_EXPORTS
        #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT __declspec(dllexport)
    #else
        #define NMSP_RESOURCE_COMMON_RECOGNITION_EXPORT __declspec(dllimport)
    #endif

    #ifdef NMSP_RESOURCE_DICTATION_EXPORTS
        #define NMSP_RESOURCE_DICTATION_EXPORT __declspec(dllexport)
    #else
        #define NMSP_RESOURCE_DICTATION_EXPORT __declspec(dllimport)
    #endif

	#ifdef NMSP_RESOURCE_NMAS_EXPORTS
        #define NMSP_RESOURCE_NMAS_EXPORT __declspec(dllexport)
    #else
        #define NMSP_RESOURCE_NMAS_EXPORT __declspec(dllimport)
	#endif

	#ifdef NMSP_RESOURCE_RECOGNITION_EXPORTS
        #define NMSP_RESOURCE_RECOGNITION_EXPORT __declspec(dllexport)
    #else
        #define NMSP_RESOURCE_RECOGNITION_EXPORT __declspec(dllimport)
	#endif

	#ifdef NMSP_RESOURCE_TTS_EXPORTS
        #define NMSP_RESOURCE_TTS_EXPORT __declspec(dllexport)
    #else
        #define NMSP_RESOURCE_TTS_EXPORT __declspec(dllimport)
	#endif

	#ifdef NMSP_AUDIOPLAYBACK_EXPORTS
        #define NMSP_AUDIOPLAYBACK_EXPORT __declspec(dllexport)
    #else
        #define NMSP_AUDIOPLAYBACK_EXPORT __declspec(dllimport)
	#endif

	#ifdef NMSP_AUDIORECORD_EXPORTS
        #define NMSP_AUDIORECORD_EXPORT __declspec(dllexport)
    #else
        #define NMSP_AUDIORECORD_EXPORT __declspec(dllimport)
	#endif

	#ifdef NMSP_DICTATION_EXPORTS
        #define NMSP_DICTATIONRESULT_EXPORT __declspec(dllexport)
    #else
        #define NMSP_DICTATIONRESULT_EXPORT __declspec(dllimport)
	#endif

    #endif


//  #ifndef NMSP_CPL_ENABLED
//  #define NMSP_CPL_ENABLED
//  #endif


#endif

#endif /* NMSP_PLATFORM_INCLUDED */
