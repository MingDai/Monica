//
//  NMT_TransactionConfig.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-22.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_cloudservices/NMT_ITransactionResult.h>
#import <nmt_cloudservices/NMT_ITransactionError.h>
#import <nmt_audio/NMT_AudioType.h>

/**
 * Listens for the start and finish of the transaction.
 */
@protocol NMT_ITransaction;

@protocol NMT_ITransactionDelegate <NSObject>
/**
 * The transaction has started.
 *
 * @param transaction The transaction.
 */
-(void) onTransactionStarted:(id<NMT_ITransaction>)transaction;

/**
 * A result was received from the server. The complete parameter lets
 * the listener know if more results are coming from the server.
 *
 * @param transaction The transaction.
 * @param result The result.
 * @param complete True if there are no more results expected.
 */
-(void) onTransactionResult:(id<NMT_ITransaction>)transaction result:(id<NMT_ITransactionResult>)result complete:(BOOL)complete;

/**
 * An error was received from the server and the transaction is
 * complete. This method is also called if an internal error occurs while creating the
 * transaction.
 *
 * @param transaction The transaction.
 * @param error The error.
 */
-(void) onTransactionError:(id<NMT_ITransaction>)transaction error:(id<NMT_ITransactionError>) error;

@end

/**
 * The CloudConfig object sets parameter values for objects used in cloud-based processing.
 */
@interface NMT_TransactionConfig : NSObject

/**
 * Like {@link #Transaction(String, com.nuance.dragon.toolkit.data.Data.Dictionary, Listener, int, boolean)},
 * with the transaction starting enabled.
 */
/**
* Determines whether to start execution right away, or to delay execution
* until ITransaction::enable is called. A disabled transaction will block
* the transaction queue until it is enabled or canceled. Default is true.
*/

-(id) initWithCommand:(NSString *)commandName commandSettings:(NSDictionary *)commandSettings delegate:(id<NMT_ITransactionDelegate>)delegate  timeout:(int)timeout isStartEnable:(BOOL)isStartEnable;

@property (readonly, retain) NSString * commandName;
@property (readonly, retain) NSDictionary * commandSettings;
@property (readonly, nonatomic) int timeout;
@property (readonly, nonatomic) BOOL isStartEnable;
@property (readonly, weak) id<NMT_ITransactionDelegate> delegate;
@end

