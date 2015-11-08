//
//  TransactionErrorDelegate.h
//  nmt
//
//  Created by administrator on 2012-11-09.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_core/JSONCompliant.h>

/**
 * Possible error types.
 */
typedef enum
{
    TRANSACTION_ERROR_TYPE_CANCELED = 0,
    TRANSACTION_ERROR_TYPE_CONNECTION_ERROR = 1,
    TRANSACTION_ERROR_TYPE_RETRY_ERROR = 2,
    TRANSACTION_ERROR_TYPE_QUERY_ERROR = 3,
    TRANSACTION_ERROR_TYPE_OTHER_ERROR = 4,
    TRANSACTION_ERROR_TYPE_SECURITY = 5,
} NMT_TransactionErrorType;

/**
 * Possible error codes when the type is Types::CONNECTION_ERROR
 */
typedef enum
{
    TRANSACTION_ERROR_CODE_NETWORK_UNAVAILABLE,
    TRANSACTION_ERROR_CODE_COMMAND_IDLE_FOR_TOO_LONG,
    TRANSACTION_ERROR_CODE_REMOTE_DISCONNECTION,
    TRANSACTION_ERROR_CODE_TIMED_OUT_WAITING_FOR_RESULT,
    TRANSACTION_ERROR_CODE_COMMAND_ENDED_UNEXPECTEDLY,
    TRANSACTION_ERROR_CODE_NONE
} NMT_TransactionErrorCode;

/**
 * A transaction error.
 */

@protocol NMT_ITransactionError <NMT_JSONCompliant>

/**
 * Gets the session ID that this error came from.
 * @return The session ID, or null if the error occurred before a session
 * was established.
 */
-(NSString *) sessionId;

/**
 * Gets the type.
 * @return A type from {@link Types}
 */
-(NMT_TransactionErrorType) type;

/**
 * Gets the Message of the error.
 * @return May return null
 */
-(NSString *) errorMessage;


/**
 * Gets the parameter name associated with the error, if any.
 * @return May return null
 */
-(NSString *) parameterWithError;

/**
 * Gets the suggestion prompt, if any.
 * @return May return null
 */
-(NSString *) prompt;

/**
 * Gets the extra error code, if applicable (i.e. for NMSP QueryError and
 * connection errors).
 * See {@link ConnectionErrorCodes} for error codes specific to connection
 * errors.
 * @return The error code
 */
-(NMT_TransactionErrorCode) errorCode;

@end
