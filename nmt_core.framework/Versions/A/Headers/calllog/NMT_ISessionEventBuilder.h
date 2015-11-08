//
//  NMT_SessionEventBuilder.h
//  Nuance Mobile Toolkit
//
//  Created by Hao Zhou on 2013-10-09.
//  Copyright (c) 2013 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_core/calllog/NMT_ISessionEvent.h>

typedef enum
{
    NMT_SESSION_EVENT_COMMITTED,
    NMT_SESSION_EVENT_COMMIT_FAILED
} NMT_SessionEventCommitError;


typedef enum
{
    /**< This is no error. */
    NMT_SESSION_EVENT_NO_ERROR,
    
    /**< Failed due to an internal VoCon Error. */
    NMT_SESSION_EVENT_NMSP_ERROR,
    
    /**< This event builder has already been committed and cannot be used. */
    NMT_SESSION_EVENT_ERROR_ALREADY_COMMITTED,
    
    /**< The call log argument is not legal. */
    NMT_SESSION_EVENT_ERROR_ILLEGAL_ARGUMENT,
    
    /**< The call log session has already been closed. */
    NMT_SESSION_EVENT_ERROR_CALL_LOG_SESSION_CLOSED
} NMT_SessionEventErrorCode;

/**
 * \brief SessionEvent commit listener.
 */


@protocol NMT_SessionEventCommitDelegate <NSObject>

    /**
     * \brief SessionEvent is committed successful.
     *
     * \ref SessionEventBuilder::commit(const ISessionEventListener * listener)
     */
-(void) onCommitted:(NMT_SessionEventCommitError)error sessionEvent:(id<NMT_ISessionEvent>) sessionEvent;

@end

/**
 * \brief Interface class for CallLog module
 *
 * A class to take the actual call log information in different types and commit them to
 * Nuance server via VoConManager. A session event object will be generated once the logs
 * are committed successfully. The generated session event object can be used to create
 * new local or remote session event builders.
 *
 * Various types of call logs are supported in this builder class: binary, boolean, integer
 * and string. One can also related this session event builder to another session event by
 * using \ref putEventReference(const char* key, SessionEvent* sessionEvent).
 *
 * This is the basic building block of the call log tree structure, a session event is a
 * node inside the call log tree. The root of the session events are maintained by the
 * VoConManager and each session event can grow its own branch by generating new session
 * event nodes.
 *
 * One can keep using one session event builder all the time or can create new session events
 * from time to time. It is up to the application to decide when and where to create new session
 * events. The meaning and relationship of the session events are all up to the application
 * developers.
 */

@protocol NMT_ISessionEventBuilder <NSObject>

    /**
     * Puts a binary value at the specified key.
     *
     * \param key[in]    The key where to store the value.
     * \param value[in]  The binary data buffer to add for the given key.
     * \param length[in] The length of binary data buffer.
     *
     * \return SESSION_EVENT_ERROR_ILLEGAL_ARGUMENT  If the value or key is either NULL
     *                                               or empty. Or the key is not of the
     *                                               same type as a previous addition.
     *
     *         SESSION_EVENT_ERROR_ALREADY_COMMITTED If this session event builder has
     *                                               already committed a session event.
     *
     *         SEESION_EVENT_ERROR_CALL_LOG_SESSION_CLOSED If the associated call log session
     *                                                     has already closed.
     */
-(NMT_SessionEventErrorCode) putBinaryValue: (NSString *)key value:(NSData *)value;
    
    /**
     * Puts a boolean value at the specified key.
     *
     * \param key[in]   The key where to store the value
     *
     * \param value[in] The boolean data value to add for the given key
     *
     * \return SESSION_EVENT_ERROR_ILLEGAL_ARGUMENT  If the value or key is either NULL
     *                                               or empty. Or the key is not of the
     *                                               same type as a previous addition.
     *
     *         SESSION_EVENT_ERROR_ALREADY_COMMITTED If this session event builder has
     *                                               already committed a session event.
     *
     *         SEESION_EVENT_ERROR_CALL_LOG_SESSION_CLOSED If the associated call log session
     *                                                     has already closed.
     */
-(NMT_SessionEventErrorCode) putBooleanValue:(NSString *)key value:(BOOL)value;
    
    /**
     * Puts a integer value at the specified key.
     *
     * \param key[in]   The key where to store the value
     *
     * \param value[in] The value to add to the vector for the given key
     *
     * \return SESSION_EVENT_ERROR_ILLEGAL_ARGUMENT  If the value or key is either NULL
     *                                               or empty. Or the key is not of the
     *                                               same type as a previous addition.
     *
     *         SESSION_EVENT_ERROR_ALREADY_COMMITTED If this session event builder has
     *                                               already committed a session event.
     *
     *         SEESION_EVENT_ERROR_CALL_LOG_SESSION_CLOSED If the associated call log session
     *                                                     has already closed.
     */
-(NMT_SessionEventErrorCode) putIntegerValue:(NSString *)key value:(NSInteger)value;
    
    /**
     * Puts a string value at the specified key.
     *
     * \param key[in]   The key where to store the value
     *
     * \param value[in] The value to add to the vector for the given key
     *
     * \return SESSION_EVENT_ERROR_ILLEGAL_ARGUMENT  If the value or key is either NULL
     *                                               or empty. Or the key is not of the
     *                                               same type as a previous addition.
     *
     *         SESSION_EVENT_ERROR_ALREADY_COMMITTED If this session event builder has
     *                                               already committed a session event.
     *
     *         SEESION_EVENT_ERROR_CALL_LOG_SESSION_CLOSED If the associated call log session
     *                                                     has already closed.
     */
-(NMT_SessionEventErrorCode) putStringValue:(NSString *)key value:(NSString *)value;

/**
 * \brief Create a remote session event as child of an existing session event
 *
 * The callback function will be called by the engine to notify the user of the generated remote session event id.
 * This id can be used to generate a new calllog tree which is then linked to the current calllog tree.
 * Note that the created remote session event can be closed only after the callback function was called.
 *
 * Normally, one only call this function to generate a remote call log session id and pass it
 * to another application. On server side this spawning relationship will be recorded via the call log
 * session ids.
 *
 * The returned SessionEvent object will be owned by the application, and needs to be deleted once
 * the application has done using it.
 *
 * \param[in] eventName  Name of session event.
 *
 * \return a pointer to a SessionEvent. NULL will be returned if we are running out of memory or the current
 *         SessionEvent's call log session has been closed.
 */
-(NMT_SessionEventErrorCode) createRemoteChildEvent:(NSString *)eventName;


    /**
     * To conclude the new session event, the logs will be submit to the call log session
     * and will be sent to the server when there is a connection. A SessionEvent object will be
     * generated as a note for the application to create a child SessionEventBuilder and keep logging
     * in the next level.
     *
     * The returned SessionEvent object will be owned by the application, and needs to be deleted once
     * the application has done using it.
     *
     * \param delegate[in] The SessionEventCallback function pointer to notify the status of the commit
     *                     Must not be NULL.
     *
     * \return A pointer to the SessionEvent object. NULL will be returned if we are running out of
     *         memory or the current call log session has been closed already.
     */
-(id<NMT_ISessionEvent>) commit:(id<NMT_SessionEventCommitDelegate>)delegate;

@end
