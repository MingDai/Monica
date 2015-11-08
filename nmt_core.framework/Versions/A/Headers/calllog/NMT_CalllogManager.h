//
//  NMT_CalllogManager.h
//  Nuance Mobile Toolkit
//
//  Created by Hao Zhou on 2013-10-08.
//  Copyright (c) 2013 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_core/calllog/NMT_ISessionEventBuilder.h>
#import <nmt_core/calllog/NMT_ICalllogSender.h>

/**
 * The Listener to monitor the call log submissions.
 **/
@protocol NMT_CalllogDataDelegate <NSObject>

/**
 * \brief Callback function. Called by the NMT SDK when there are some more call log data to offer to the application.
 *
 * When the buffer is NULL and the size is 0, it indicates that this is the end of the call log data output. And there
 * is no more data will be delivered to the application via the nmsp_manager_calllog_outputCB call back.
 *
 * \param buffer  The buffer contains the call log data generated inside SDK, could be NULL if there is no
 *                more data to be read, this happens after shutting down the manager.
 * \param size    The size of the \p buffer in bytes
 **/
-(void) onCalllogDataGenerated:(id<NMT_ICalllogData>) data;

@end

@protocol NMT_ICalllog;

@interface NMT_CalllogManager : NSObject

/**
 * attach a ICalllog implementation to call log manager and the call log starts
 *
 * Note: Internal use only
 *
 * \param pCalllogImpl  implementation of ICalllog.
 *
 * \return 0 if successfully attached, -1 otherwise
 */
+(int)attachCalllogImpl:(id<NMT_ICalllog>) pCalllogImpl;

/**
 * destroy the ICalllogSender object.
 */
/**
 * register Call log listener so that user may receive call log output data.
 *
 * \param listener  listener to be registered.
 *
 * @return
 */
+(void) registerCalllogDataDelegate: (id<NMT_CalllogDataDelegate>)delegate;


/**
 * \brief Log an application event by creating a SessionEventBuilder. This session event
 * is a child of the current NMSP SDK root session event. The application can call this method
 * multiple times to retrieve session event builders at different time.
 *
 * For example, logging user behaviors for different recognition transactions.
 *
 * The application can also use the returned SessionEventBuilder to log associated sub
 * log events.
 *
 * Returns a pointer to application session event builder.
 *
 * \param sAppEventName   Application event name.
 *                       Must not be NULL or empty.
 *
 * \return               Pointer to application session event builder. Returns NULL if
 *                       error occurs (check log) or call log feature is disabled or no
 *                       call log implementation is attached.
 *
 * \see NMSP_DEFINES_CALLLOG_DISABLE
 */
+(id<NMT_ISessionEventBuilder>) logAppEvent:(NSString *)sAppEventName;

/**
 * \brief Processes any pending call logs to the callback callLogDataGenerated
 * This should be used whenever the client wants the logs to be flushed before the chunk
 * size limit has been reached
 *
 * \see NMSP_DEFINES_CALLLOG_CHUNK_SIZE
 */
+(void) flushCallLogData;

/**
 * create the ICalllogSender object that can be used by application to send
 * log (see {@link ICalllogSender}).
 *
 * \param  pListener Listener to monitor the call log submissions
 *
 * \return The ICalllogSender object.
 */
+(id<NMT_ICalllogSender>) createCalllogSender:(id<NMT_CalllogSenderDelegate>) delegate;


/**
 * get current state of call log session.
 *
 * @return current state of call log session.
 */
+(BOOL) isCalllogActive;

/**
 * \brief Retrieves the root parent Id of the current Calllog session, the root parent
 * Id is Unique per call log implementation such as cloud services.
 *
 * \return               The root parent Id of the current call log session
 *                       NULL if the call log feature is disabled or no call log implementation
 *                       is attached
 *
 * \see NMSP_DEFINES_CALLLOG_DISABLE
 */
+(NSString *) calllogRootParentId;

@end
