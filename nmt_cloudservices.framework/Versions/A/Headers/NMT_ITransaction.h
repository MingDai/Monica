//
//  Transaction.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-23.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_cloudservices/NMT_IParam.h>


@protocol NMT_ITransaction <NSObject>


/**
 * Adds a parameter to this transaction.
 *
 * @param param
 */
-(void) addParam:(id<NMT_IParam>)param;

/**
 * Enables this transaction to be started. This has no effect if the
 * transaction was created enabled.
 */
//-(void) enable;

/**
 * Ends the transaction. After this method is called, no parameters can be added.
 * The transaction is not necessarily complete at this point since
 * parameters may be queued to be sent, or you may be waiting on results, this
 * just means the client is finished constructing it.
 */
-(void) finish;


/**
 * Cancels the transaction. This message will be propagated all the way to
 * the server and the transaction will be removed from the Speech Core
 * queue.
 */
-(void) cancel;

/**
* Indicates whether a transaction has finished, finish() has been called, and no further
* parameters can be added.
*
* @return true  This transaction has finished.
*/
-(BOOL) isFinished;

/**
 * Indicates whether a transaction is active, is not waiting in queue, and is either
 * currently running or waiting for a result.
 *
 * @return true  This transaction is active.
 */
-(BOOL) isActive;


/**
 * Indicates whether a transaction has completed. When true, the transaction is over, all results 
 * have been received, 
 * and no further callbacks will be executed. The transaction
 * can be discarded.
 *
 * @return  If this transaction has completed, returns true.
 */
-(BOOL) isComplete;


/**
 * Set the cadence at which multiple results can be received.
 *
 * This feature is relevant when multiple results are streamed back from
 * the server. Setting the cadence guarantees that the time between
 * successive streamed results will be greater than the specified
 * cadence.
 * The final result is always sent back as soon as it is available.
 * Depending on the command being executed, the server may flag some
 * results as being exempt from cadence regulation. These will be delivered
 * as soon as available.
 * When the cadence is set to 0, updates are sent back through the Listener
 * as soon as they are available. The default cadence is 0.
 *
 * @param cadenceMs  The minimum time in milliseconds between successive result updates.
 */
-(void) setCadence:(unsigned int)cadenceMs;

@property (readonly, retain) NSArray * params;

@end




