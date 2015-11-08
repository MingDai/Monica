#ifndef NMSP_DEFINES_INCLUDED
#define NMSP_DEFINES_INCLUDED
/*-----------------------------------------------------------------
   Note -- this header file is annotated with markup for Doxygen,
   a documentation tool for C and C++. If you are just reading
   the header file, you should ignore such markup as \c, \section
   \param, and so on.
  -----------------------------------------------------------------*/

/** \file nmsp_defines.h
    
                NMSP Common Defines
   
   \section Legal_Notice Legal Notice
 
   Copyright 2006-2011, Nuance Communications Inc. All rights reserved.
 
   Nuance Communications, Inc. provides this document without representation
   or warranty of any kind. The information in this document is subject to
   change without notice and does not represent a commitment by Nuance
   Communications, Inc. The software and/or databases described in this
   document are furnished under a license agreement and may be used or
   copied only in accordance with the terms of such license agreement.
   Without limiting the rights under copyright reserved herein, and except
   as permitted by such license agreement, no part of this document may be
   reproduced or transmitted in any form or by any means, including, without
   limitation, electronic, mechanical, photocopying, recording, or otherwise,
   or transferred to information storage and retrieval systems, without the
   prior written permission of Nuance Communications, Inc.
 
   Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are
   trademarks or registered trademarks of Nuance Communications, Inc. or its
   affiliates in the United States and/or other countries. All other
   trademarks referenced herein are the property of their respective owners.
   
 
    \section def-sec1 Overview

    Defines constants for configuration parameters and for codec types.

*/
#ifdef _WIN32
    #pragma comment(lib, "user32.lib")
    #pragma comment(lib, "advapi32.lib")
    #pragma comment(lib, "ws2_32.lib")
    #pragma comment(lib, "secur32.lib")
    #pragma comment(lib, "rpcrt4.lib")
    #pragma comment(lib, "crypt32.lib")
    #pragma comment(lib, "winmm.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif


    /**
    \def NMSP_DEFINES_CONNECTION_TIMEOUT_PARAM
         Defines the ConnectionTimeout parameter, which specifies the maximum time, in seconds, from
         the creation of the Command until the connection to the dictation server is established and a
         COP CONNECTION is received. Can be used as a key for the properties in the property list.
         Must be an integer value greater than 0. Default = 30.

    \def NMSP_DEFINES_CONNECTION_TIMEOUT_DEFAULT
          Defines the default value of the ConnectionTimeout parameter.

    \def NMSP_DEFINES_IDLE_SESSION_TIMEOUT_PARAM
         Defines the IdleSessionTimeout parameter, which specifies the maximum time, in seconds,
         that a session can remain idle. A session is considered to be idle when no messages are
         sent to or received by the NMSP Gateway from the mobile device.
         Can be used as a key for the properties in the property list. Must be an integer value
         greater than 0. Default = 45.

    \def NMSP_DEFINES_IDLE_SESSION_TIMEOUT_DEFAULT
         Defines the default value of the IdleSessionTimeout parameter.

    \def NMSP_DEFINES_PING_INTERVAL_PARAM
         Defines the PingInterval parameter, which specifies the maximum time interval, in seconds, between
         pings from the NMSP Gateway. The ping is sent in the COP CONNECTED. Can be used as a key for the properties
         in the property list. Must be an integer value equal to or greater than 0. Default = 0.

    \def NMSP_DEFINES_PING_INTERVAL_DEFAULT
         Defines the default value of the PingInterval parameter.

    \def NMSP_DEFINES_MISSED_PINGS_BEFORE_DISCONNECT_PARAM
         Defines the MissedPingsBeforeDisconnect parameter, which specifies the maximum number of missed ping
         responses from the client before the NMSP Gateway disconnects. The ping is sent in the COP CONNECTED. Can
         be used as a key for the properties in the property list. Must be an integer value greater than 0. Default = 3.

    \def NMSP_DEFINES_MISSED_PINGS_BEFORE_DISCONNECT_DEFAULT
         Defines the default value of the MissedPingsBeforeDisconnect parameter.

    \def NMSP_DEFINES_ENDPOINTER
         Define that allows enabling the end pointer which automatically detects the start of speech and
         end of speech when recording.

    \def NMSP_DEFINES_USE_ENERGY_LEVEL
         Defines the energy level parameter, which specifies if a notification must be sent using the
         NMSP_AUDIO_RECORD_BUFFER_RECORDED event when a change in the audio energy level occurs.

    \def NMSP_DEFINES_AUDIO_INPUTSOURCE
         Allows users to specify the input audio source.

    \def NMSP_DEFINES_AUDIO_SAMPLERATE
         Allows users to specify the input audio sample rate.

    \def NMSP_DEFINES_SSL_SOCKET
         Enables the SSL socket connection.

    \def NMSP_DEFINES_SSL_CERT_SUMMARY
         Presets the SSL certificate summary, which will be compared with the one replied by the server for verification.
         This parameter is important to specify in order to prevent man-in-the-middle (MITM)
         attack styles where the middle man has a valid certificate but different than the expected target.
         The value of the string is a partial or fully-qualified domain name (FQDN) and may include a star (asterisk) for wildcard
         certificates - exactly as specified in the CN field of the server X.509. (example: *.nuancemobility.net)

    \def NMSP_DEFINES_SSL_CERT_DATA
         Presets the SSL certificate data, which will be compared with the data replied by the server for verification.
         If this value is specified:
         After standard certificate validity checks are complete, certificates in the chain of trust are byte-compared in sequence against this certificate
         From the target server host (the tip of the chain of trust) back to the root CA, until the first match is found.
         Any match means that the connection is allowed.  If none match, the connection is disallowed.

         Therefore, this parameter can be used to either provide a strong target host check, or to "pin" the chain of trust to a specific root
         or intermediate CA.  If the encoded certificate is a CA rather than the target server CN, it is important to also specify the sslSummary.
         Otherwise, the sslSummary is redundant and not strictly necessary.
       
         Since the encoded certificates contain validity dates and other items, certificate rotation
         needs should be considered in the client design when using this parameter.
        
    \def NMSP_DEFINES_SSL_SELFSIGNED_CERT
         Lets the server use its self-signed certificate for development purposes.

    \def NMSP_DEFINES_SSL_CERT_STORE_FILE
         This is only useful on platforms where OpenSSL does not correctly setup the default CA path for certificates.
         On Ubuntu this file is usually located at /etc/ssl/certs/ca-certificates.crt. Use this parameter to set where
         it can be found. This parameter has no effect on platforms where this information is not relevant.

    \def NMSP_DEFINES_SSL_SET_MTCALLBACK
         Ask to set or not to set void (*func)(int mode, int type, const char *file, int line) by CRYPTO_set_locking_callback 
         and void (*threadid_func)(CRYPTO_THREADID *) by CRYPTO_THREADID_set_callback internally for SSL multiple threading. 
         By default it is set to "TRUE" or "True", however the users could still override the callbacks set by NMSP by
         using OpenSSL's set functions. If we ask not to set, it is users' responsibility to set them outside of 
         Nuance product context.

    \def NMSP_DEFINES_ENABLE_USER_ID_ENCRYPTION
         Enable the user ID encryption, once this parameter is enabled, the real user id will stay in the application.
         The server will only receive the encrypted user id via one-way hash. So that the server will not be aware of
         the read user id.

    \def NMSP_DEFINES_CALLLOG_DISABLE
         Allows users to disable call logging by setting this parameter to "TRUE" or "True", it is enabled by default.

    \def NMSP_DEFINES_CALLLOG_ROOT_ID
         Allows users to pass an existing UUID as the root parent id. This ID has to be created by the NMSP SDK as a remote
         reference ID. A typical use case is to relate the call logs generated by one NMSP SDK application A and call logs
         generated by another NMPS SDK application B. The application B could be launched by the application A and it should
         use a remote reference ID created by application A as its root parent ID.
         
    \def NMSP_DEFINES_CALLLOG_RETENTION_DAYS
         Specifies the suggested number of days for preserving the call log data in the cloud. The effective data retention
         period is subject to a number of conditions on the server side and may be automatically adjusted to a higher or
         lower value than the specified one.
         
         The value of -1 indicates no specific value for the data retention and the server default value will be used. Other
         negative values or 0 is not allowed. The default value is -1.

    \def NMSP_DEFINES_CALLLOG_CHUNK_SIZE
         Allows users to control the call log generation call back rate based on the chunk size. The call log data callback
         will be called with a call log data buffer once the internal logs accumulated acceding the chunk size. The chunk
         size is 1M by default. The minimum chunk size is 20K (1000x20), passing a parameter smaller than 20K will cause
         the manager creation failed. The default chunk size is 100K (1000x100) and the maximum chunk size is 150K (1000x150)
         \see nmsp_manager_calllog_outputCB

    \def NMSP_DEFINES_CALLLOG_APP_TRANSACTION_REF_EVENT
         This is the event name the application needs to use to create the root node of the transaction information log tree.
         Before starting each transaction, the application needs to call logAppEvent function with this name, commit that
         SessionEventBuilder right away. And then get the ID for that committed call log event. Once the application is ready
         to start a transaction (create a NMAS command for a recognition, etc) The application needs to pass the following key
         value pair {NMSP_DEFINES_CALLLOG_APP_TRANSACTION_REF_EVENT, ID} as one element in the optional key parameter.
         Refer to the following function: nmsp_nmas_command_create.

    \def NMSP_DEFINES_VERSION
         The NMSP SDK version will be updated only when a new feature set is 
         released by product management. The build should be updated each time 
         the main R&D branch is certified by QA and integrated into the release 
         branch. In addition to the NMSP SDK version and build information defined here,
         the API function nmsp_getVersion() also returns version information.

    \def NMSP_DEFINES_START_OF_SPEECH_TIMEOUT
         Allows the user to control the start of speech timeout value. If the user starts a recognition but does not speak for
         a duration longer than this value, the recognition will stop. This value must be specified in milliseconds.
    
    \def NMSP_DEFINES_OPUS_COMPLEXITY
         Allows the user to set the complexity level to the OPUS encoder. If the user does not specify this parameter, SDK
         will use 10 as the default complexity value for OPUS encoding. This should be passed into the
         \ref nmsp_audio_recorder_create function.
    
    \def NMSP_DEFINES_OPUS_VBR_ENABLED
         Allows the user to enable the VBR (variable bit rate) feature to the OPUS encoder. If the user does not specify this
         parameter, SDK will use CBR (constant bit rate) by default. This should be passed into the
         \ref nmsp_audio_recorder_create function.
    
    \def NMSP_DEFINES_OPUS_BITRATE
         Allows the user to set the bit rate value to the OPUS encoder. If the user does not specify this parameter, SDK will
         use 28kbps by default. This should be passed into the \ref nmsp_audio_recorder_create function.

    \def NMSP_DEFINES_OPUS_PACKET_LENGTH
         Allows the user to set the packet length value to the OPUS encoder. If the user does not specify this parameter, SDK
         will use 20ms by default. This should be passed into the \ref nmsp_audio_recorder_create function.
*/

#define NMSP_DEFINES_CONNECTION_TIMEOUT_PARAM                "ConnectionTimeout"
#define NMSP_DEFINES_CONNECTION_TIMEOUT_DEFAULT              30
#define NMSP_DEFINES_IDLE_SESSION_TIMEOUT_PARAM              "IdleSessionTimeout"
#define NMSP_DEFINES_IDLE_SESSION_TIMEOUT_DEFAULT            45
#define NMSP_DEFINES_SOCKET_WRITE_TIMEOUT_PARAM              "SocketWriteTimeout"
#define NMSP_DEFINES_SOCKET_WRITE_TIMEOUT_DEFAULT            5
#define NMSP_DEFINES_PING_INTERVAL_PARAM                     "Ping_IntervalSecs"
#define NMSP_DEFINES_PING_INTERVAL_DEFAULT                   0
#define NMSP_DEFINES_MISSED_PINGS_BEFORE_DISCONNECT_PARAM    "Ping_MissedResponsesBeforeDisconnect"
#define NMSP_DEFINES_MISSED_PINGS_BEFORE_DISCONNECT_DEFAULT  3
#define NMSP_DEFINES_ENDPOINTER                              "ep.StopOnEndOfSpeech"
#define NMSP_DEFINES_USE_ENERGY_LEVEL                        "Energy_Level"
#define NMSP_DEFINES_AUDIO_INPUTSOURCE                       "Audio_Source"
#define NMSP_DEFINES_AUDIO_SAMPLERATE                        "Audio_HWSampleRate"
#define NMSP_DEFINES_SSL_SOCKET                              "SSL_Socket_Enable"
#define NMSP_DEFINES_SSL_CERT_SUMMARY                        "SSL_Cert_Summary"
#define NMSP_DEFINES_SSL_CERT_DATA                           "SSL_Cert_Data"
#define NMSP_DEFINES_SSL_SELFSIGNED_CERT                     "SSL_SelfSigned_Cert"
#define NMSP_DEFINES_SSL_CERT_STORE_FILE                     "SSL_CertStoreFile"
#define NMSP_DEFINES_SSL_SET_MTCALLBACK                      "SSL_Set_MTCallback"
#define NMSP_DEFINES_ENABLE_USER_ID_ENCRYPTION               "Enable_UserId_Encryption"
#define NMSP_DEFINES_CALLLOG_DISABLE                         "Calllog_Disable"
#define NMSP_DEFINES_CALLLOG_ROOT_ID                         "Calllog_Root_Id"
#define NMSP_DEFINES_CALLLOG_RETENTION_DAYS                  "Calllog_Retention_Days"
#define NMSP_DEFINES_CALLLOG_CHUNK_SIZE                      "Calllog_Chunk_Size"
#define NMSP_DEFINES_CALLLOG_APP_TRANSACTION_REF_EVENT       "APP_TRANSACTION_REF"
#define NMSP_DEFINES_VERSION                                 "NMSP 5.3 client SDK - build 021"
#define NMSP_DEFINES_START_OF_SPEECH_TIMEOUT                 "Start_Of_Speech_Timeout"
#define NMSP_DEFINES_OPUS_COMPLEXITY                         "Opus_Complexity"
#define NMSP_DEFINES_OPUS_VBR_ENABLED                        "Opus_Enable_VBR"
#define NMSP_DEFINES_OPUS_BITRATE                            "Opus_Bitrate"
#define NMSP_DEFINES_OPUS_PACKET_LENGTH                      "Opus_Packet_Length"

/** \typedef NMSP_DEFINES_CODEC

    Defines constants for codec types.
 **/
typedef enum {
    /* invalid codec or codec unavailable*/
    CODEC_NONE = -1,                    /*!< Used to indicate an invalid or unspecified codec */

    /* PCM 16k */
    CODEC_PCM_16_8K  = 0x0002,            /*!< Pulse code modulation with 16-bit quantization and  8KHz sampling rate */
    CODEC_PCM_16_11K = 0x0004,            /*!< Pulse code modulation with 16-bit quantization and 11KHz sampling rate */
    CODEC_PCM_16_16K = 0x0005,            /*!< Pulse code modulation with 16-bit quantization and 16KHz sampling rate */

    /* u-law */
    CODEC_ULAW       = 0x0008,            /*!< u-law(mu-law) codec */

    /* DSR */
    //CODEC_DSR_8K     = 0x0030,
    //CODEC_DSR_11K    = 0x0031,

    /* G.729 */
    //CODEC_G729_64    = 0x0041, /* 6.4 Kbps */
    //CODEC_G729_80    = 0x0042, /* 8.0 Kbps */
    //CODEC_G729_118   = 0x0043, /* 11.6 Kbps */

    /* AMR */
    CODEC_AMR_00     = 0x0050,            /*!< Adaptive Multi-Rate codec 00 */
    CODEC_AMR_01     = 0x0051,            /*!< Adaptive Multi-Rate codec 01 */
    CODEC_AMR_02     = 0x0052,            /*!< Adaptive Multi-Rate codec 02 */
    CODEC_AMR_03     = 0x0053,            /*!< Adaptive Multi-Rate codec 03 */
    CODEC_AMR_04     = 0x0054,            /*!< Adaptive Multi-Rate codec 04 */
    CODEC_AMR_05     = 0x0055,            /*!< Adaptive Multi-Rate codec 05 */
    CODEC_AMR_06     = 0x0056,            /*!< Adaptive Multi-Rate codec 06 */    
    CODEC_AMR_07     = 0x0057,            /*!< Adaptive Multi-Rate codec 07 */

    CODEC_MP3        = 0x0260,          /*!< MPEG-1 or MPEG-2 Audio Layer III (MP3) */

    CODEC_MS_GSM_FR  = 0x0290,          /*!< GSM Full Rate speech coding */
    CODEC_GSM_FR     = 0x0291,

    /* AMR Non bit-ordering */
    CODEC_AMR_NBO_R0 = 0x0080,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 00 */
    CODEC_AMR_NBO_R1 = 0x0081,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 01 */
    CODEC_AMR_NBO_R2 = 0x0082,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 02 */
    CODEC_AMR_NBO_R3 = 0x0083,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 03 */
    CODEC_AMR_NBO_R4 = 0x0084,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 04 */
    CODEC_AMR_NBO_R5 = 0x0085,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 05 */
    CODEC_AMR_NBO_R6 = 0x0086,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 06 */
    CODEC_AMR_NBO_R7 = 0x0087,            /*!< Non Bit-Ordering Adaptive Multi-Rate codec 07 */

    /* QCP */
    CODEC_QCELP_13   = 0x0062,            /*!< Qualcomm Code Excited Linear Prediction (QCELP) codec 13Kbits/s */
    CODEC_QCELP_VAR  = 0x0063,            /*!< Qualcomm Code Excited Linear Prediction (QCELP) codec variable rate */

    /* EVRC */
    CODEC_EVRC       = 0x0070,            /*!< Enhanced Variable Rate CODEC (EVRC) */

    /* iLBC */
    CODEC_ILBC       = 0x0090,            /*!< Internet Low Bit Rate Codec (iLBC) */

    /* Speex */
    CODEC_SPEEX_8K         = 0x0106,        /*!< Speex wideband (8 kHz) */
    CODEC_SPEEX_16K        = 0x0116,        /*!< Speex wideband (16 kHz) */
    CODEC_SPEEX_11K        = 0x0168,        /*!< Speex wideband (11 kHz) */

    /* Opus */
    CODEC_OPUS_8K  = 0x040A,    /*!< OPUS MONO (8kHz), CBR and complexity 10 by default, configurable via other parameters */
    CODEC_OPUS_16K = 0x0462     /*!< OPUS MONO (16kHz), CBR and complexity 10 by default, configurable via other parameters */
} NMSP_DEFINES_CODEC;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_DEFINES_INCLUDED */
