//
//  TransactionResultDelegate.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-09.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_core/JSONCompliant.h>

@protocol NMT_ITransactionResult <NMT_JSONCompliant>

/**
 * Gets the session ID that this result came from.
 * @return The session ID. (Cannot be null.)
 */
-(NSString *) sessionId;

/**
 * Gets the result type, taken from the 'result_type' key of the result
 * dictionary.
 * @return The result type. (Cannot be null.)
 */
-(NSString *) resultType;

/**
 * Gets the contents of this result.
 * @return The contents. (Cannot be null.)
 */
-(NSDictionary *) contents;


/**
 * Indicates whether the final result was returned, or if more results are expected.
 * @return If all results have been received, returns true.
 */
-(BOOL) isFinal;

@end
