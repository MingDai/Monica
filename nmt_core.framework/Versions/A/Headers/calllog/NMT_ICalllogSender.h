//
//  NMT_CalllogSender.h
//  Nuance Mobile Toolkit
//
//  Created by Hao Zhou on 2013-10-09.
//  Copyright (c) 2013 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Call Log Sender Error Code
 **/
typedef enum
{
    NMT_CALLLOG_SENDER_NO_ERROR             = 0x00, /*!< Indicates there is no error and the call log data is sent successfully */
    NMT_CALLLOG_SENDER_ERROR_OUT_OF_MEMORY  = 0x01, /*!< Indicates out of memory */
    NMT_CALLLOG_SENDER_ERROR_NETWORK        = 0x02, /*!< Indicates there is a network error */
    NMT_CALLLOG_SENDER_INVALID_DATA         = 0x03, /*!< Indicates the call log data to be sent is invalid */
    NMT_CALLLOG_SENDER_CONNECTION_FAILED    = 0x04  /*!< Indicates the connection failed */
} NMT_CALLLOG_SENDER_ERROR;

@protocol NMT_ICalllogData <NSObject>

@end

/**
 * The Listener to monitor the call log submissions.
 **/
@protocol NMT_CalllogSenderDelegate <NSObject>

    /**
     * The call log data associated with the current listener has been
     * sent to the server successfully. The application can drop the
     * associated binary data.
     *
     * \param data  the pointer to the call log data being submit to the
     *              server successfully, must not be NULL.
     **/
-(void) onCalllogSendSucceed:(id<NMT_ICalllogData>)data;
    
    /**
     * The call log data associated with the current listener failed to
     * be sent to the server.The remaining binary data has been returned
     * and the application. Application should manage to send them again
     * via the function
     *
     * \param errorCode  Error code.
     * \param data       The remaining call log binary data which failed to
     *                   be sent to the server, must not be NULL.
     **/
-(void) onCalllogSendFailed:(NMT_CALLLOG_SENDER_ERROR)errorCode data:(id<NMT_ICalllogData>)data;

@end


/**
 * CalllogSender manages sending the serialized call logs to the server via its own Channel.
 * The binary call logs data can be obtained from the
 * \ref IRecognizerListener::onCalllogDataGenerated(const char*, size_t)
 *
 * There is a listener \ref ICalllogSenderListener manages the event notifications for the
 * call log transmission over the network to the server. Once the submission is done, no matter success
 * or failure, the SenderListener will be called with the status code. The application can manage which
 * data buffer has been sent.
 *
 * There is only one call log sender object can be created at a time, multiple call log senders
 * running at the same time is not supported.
 *
 * \see IRecognizerListener::onCalllogDataGenerated(const char*, size_t)
 */
@protocol NMT_ICalllogSender <NSObject>

/**
 * Send the binary call log data to the server.
 *
 * This is used to send the binary call log data obtained from the
 * function \ref IRecognizerListener::onCalllogDataGenerated(const char*, size_t).
 * The data has to be exactly the same as when it is returned by the SDK and can not be modified.
 *
 * \param data    The binary call log data to be sent. NMT will NOT copy this data; therefore application
 *                must keep data safely.
 *
 *
 * \see IRecognizerListener::onCalllogDataGenerated(const char*, size_t)
 */
-(BOOL) send:(id<NMT_ICalllogData>)data;

@end
