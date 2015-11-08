//
//  NMT_CloudServices.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-22.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_cloudservices/NMT_CloudConfig.h>
#import <nmt_cloudservices/NMT_ITransaction.h>


/**
 * Possible connection states.
 */
typedef enum
{
    /** Currently connected to the server. */
    NMT_CONNECTED,
    /** Not connected to the server. */
    NMT_DISCONNECTED
} NMT_ConnectionState;

/**
 * CloudServices delegate.
 */
@protocol NMT_ICloudServices;

@protocol NMT_ICloudServicesDelegate <NSObject>

/**
 * \brief The ICloudServices has been released.
 *
 * \param cloudServices
 */
-(void) onShutDown:(id<NMT_ICloudServices>) cloudServices;

@end

/**
 * Interface for optional Cloud Services configuration sections.
 * User can specify those additional configuration sections
 * as input parameter of {@link CloudServicesConfig}.
 */
@protocol NMT_ICloudServicesConfigSection <NSObject>

@end

/**
 * \brief Module that manages connection(s) to the NMSP Gateway and commands to the NMAS.
 *        This module manages a queue of asynchronous transactions (NMAS commands) that are
 *        executed one at a time. When executing a transaction, this module will send the contents of
 *        the transaction to Nuance's speech servers via the NMAS components of the NMSP SDK.
 */
@protocol NMT_ICloudServices <NSObject>

/**
 * Disconnects from the gateway. Does all cleanup. Cancels the active
 * transaction. Delegate called when cleanup is complete and we can
 * guarantee no further callbacks.
 */
-(void) shutdown;

/**
 * \brief Add a SpeechTransaction object to the transaction queue. Transaction will
 *        start executing immediately if there are no pending transactions before it.
 *
 * \param transaction
 * \param priority
 * \return True if transaction was added. False otherwise.
 */
-(BOOL) addTransaction:(id<NMT_ITransaction>)transaction  priority:(int)priority;

/**
 * \brief Get a the currently executing transaction
 *
 * \return The current transaction, or null if there is no transaction.
 */
-(id<NMT_ITransaction>) currentTransaction;


/**
 * Get the number of total transactions in the transaction queue, including
 * the transaction that is currently executing (if any).
 * @return The number of total transactions
 */
@property (readonly) int transactionCount;


/**
 * \brief Retrieve the current connection state.
 *
 * \return The current state.
 */
@property (readonly) NMT_ConnectionState connectionState;

/**
 * Gets the most recent session ID.
 *
 * @return The session ID, or null if no session has been established yet.
 */
@property (readonly, retain) NSString * sessionId;

/**
 * Gets the unique ID.
 *
 * @return The unique ID, or null in case of an error.
 */
@property (readonly, retain) NSString * uniqueId;

@end


