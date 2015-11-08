//
//  NMT_SessionEvent.h
//  Nuance Mobile Toolkit
//
//  Created by Hao Zhou on 2013-10-09.
//  Copyright (c) 2013 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NMT_ISessionEventBuilder;

@protocol NMT_ISessionEvent <NSObject>

    /**
     * \brief Create a session event builder as child of an existing session event
     * One session event can create multiple child session event builders to submit the call logs to.
     * It is up to the application to decide how to use the call log session event. One can create
     * one session event and put all the information into it or create several session events and
     * put different information into each of them.
     *
     * Note: One should commit the SessionEventBulider as soon as all the information has
     *       been logged. Otherwise the information may not be able to be committed if the
     *       associated call log session closed due to the uninitialization of the VoCon
     *       engine.
     *
     * The returned SessionEventBuilder object will be owned by the application, and need
     * to be deleted once the application has done using it.
     *
     * \param[in] eventName  name of session event which will be created by the session
     *                       event builder. Must not be NULL or empty string.
     *
     * \return a pointer to a SessionEventBuilder. NULL will be returned if we are running
     *         out of memory or the current SessionEvent's call log session has been closed.
     */
-(id<NMT_ISessionEventBuilder>) createChildEventBuilder:(NSString *)eventName;
    
    /**
     * Retrieve the session event Id. This id is the concatenation of the root parent id and
     * the sequence id of the event.
     *
     * To use this method properly, \ref SessionEventBuilder::commit() must be called and wait
     * until the event is committed via the \ref SessionEventCallback. Otherwise the sequence
     * Id may not have been generated and null will be returned.
     *
     * \return session event id. Null will be returned if the SessionEvent has not been committed yet.
     */
@property (readonly) NSString * sessionEventId;


    /**
     * Retrieve the remote reference id and the associated event name corresponding to the specified
     * index.
     *
     * To use this method properly, \ref SessionEventBuilder::commit() must be called and wait
     * until the event is committed.
     *
     * The NSDictionary contains the reference ID name as key (NSString), and the reference
     * ID itself as value (NSString)
     *
     * \return NSDictionary containing reference Ids, or nil if error or none available
     */
@property (readonly) NSDictionary * referenceIds;

@end
