/*
*  NMT_IToken.h
*
*           Nuance Mobile Toolkit - nmt_recognition
*
*   \section Legal_Notice Legal Notice
*
*   Copyright 2013, Nuance Communications Inc. All rights reserved.
*
*   Nuance Communications, Inc. provides this document without representation
*   or warranty of any kind. The information in this document is subject to
*   change without notice and does not represent a commitment by Nuance
*   Communications, Inc. The software and/or databases described in this
*   document are furnished under a license agreement and may be used or
*   copied only in accordance with the terms of such license agreement.
*   Without limiting the rights under copyright reserved herein, and except
*   as permitted by such license agreement, no part of this document may be
*   reproduced or transmitted in any form or by any means, including, without
*   limitation, electronic, mechanical, photocopying, recording, or otherwise,
*   or transferred to information storage and retrieval systems, without the
*   prior written permission of Nuance Communications, Inc.
*
*   Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are
*   trademarks or registered trademarks of Nuance Communications, Inc. or its
*   affiliates in the United States and/or other countries. All other
*   trademarks referenced herein are the property of their respective owners.
*/

#import <Foundation/Foundation.h>


/**
 * Represents a <code>Token</code> object, which is contained by
 * a <code>Sentence</code> or an <code>Alternative</code>. A <code>Token</code> carries
 * the content as a string and the confidence score as a value of type <code>double</code>.
 *
 * Call the {@link #getString()} method to get the string representation of the <code>Token</code>.
 *
 */
@protocol NMT_IToken <NSObject>

/**
 * Retrieves the confidence score of the current
 * <code>Token</code>.
 *
 * <p>The confidence range and format are configurable on Nuance Speech Server.
 *
 * @return the confidence score
 */
@property (readonly, nonatomic) double confidence;

/**
 * Retrieves the start time in milliseconds of the current
 * <code>Token</code>.
 *
 * @return the start time
 */
@property (readonly, nonatomic) int64_t startTime;

/**
 * Retrieves the end time in milliseconds of the current
 * <code>Token</code>.
 *
 * @return the end time
 */
@property (readonly, nonatomic) int64_t endTime;

/**
 * Checks if the <code>Token</code> has a <code>\*no-space-before</code> directive.
 *
 * @return true if there is a <code>\*no-space-before</code> directive for this <code>Token</code>
 *         false if there is no <code>\*no-space-before</code> directive for this <code>Token</code>
 */
@property (readonly, nonatomic) BOOL hasNoSpaceBeforeDirective;

/**
 * Checks if the <code>Token</code> has a <code>\*no-space-after</code> directive.
 *
 * @return true if there is a <code>\*no-space-after</code> directive for this <code>Token</code>
 *         false if there is no <code>\*no-space-after</code> directive for this <code>Token</code>
 */
@property (readonly, nonatomic) BOOL hasNoSpaceAfterDirective;


/**
 * Retrieves a list of homophones for the <code>Token</code>.
 *
 * @return the list of strings representing the homophones
 */
@property (readonly, retain) NSArray * homophones;

/**
 * Retrieves a list of alternatives for the current token based on the specified token type see <code>getWordAlternativeTypes</code>
 *
 * @return the list of word alternatives for the type.
 */
-(NSArray *)  getWordAlternatives:(NSString *) altType;

/**
 * Retrieves a list of alternatives types for the current token.
 *
 * @return the list of word alternatives for the type.
 */
-(NSArray *)  getWordAlternativesTypes;


@end
