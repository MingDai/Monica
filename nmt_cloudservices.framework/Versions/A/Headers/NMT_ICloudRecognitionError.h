//
//  NMT_ICloudRecognitionError.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-09.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_core/JSONCompliant.h>
#import <nmt_cloudservices/NMT_ITransactionError.h>

typedef enum {
    NMT_ERROR_TRANSACTION = 0,
    NMT_ERROR_INVALIDPARAMETER = 1
} NMT_CloudRecognitionErrorType;

/**
 * A cloud recognition error object.
 */
@protocol NMT_ICloudRecognitionError <NMT_JSONCompliant>

/**
 * @return The type of the error, from {@link Errors}.
 */
-(int) type;

/**
 * Creates a CloudRecognitionError with a TransactionError object.
 * (For internal use only.)
 * @param transactionError
 */
-(id<NMT_ITransactionError>) transactionError;

@end
