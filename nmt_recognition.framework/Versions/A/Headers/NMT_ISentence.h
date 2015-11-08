/*
*  NMT_ISentence.h
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
 * Represents one sentence among the many possible
 * sentences contained in <code>DictationResult</code>.
 * <br>
 * <br>
 * To get the string representation of the sentence, call
 * {@link #getString()}.
 * <br>
 * For a more detailed description, please see {@link DictationResult}
 *
 * @see DictationResult
 */
@protocol NMT_ISentence <NSObject>

/**
 * Returns the number of tokens contained in that sentence.
 *
 * @return  number of tokens
 */
@property (readonly, retain) NSArray * tokens;

/**
 * Returns the confidence score of the current sentence.
 * <p>The confidence range and format are configurable on the Nuance Speech Server.
 * The confidence score is not always supported, and the scope may vary according to
 * different server-side configurations. To get the range of the confidence
 * score, please check the dictation server configuration.
 *
 * @return confidence score of the current sentence; returns zero
 *     if the given sentence does not have a confidence
 *        score or if an error occurs
 *
 */
@property (readonly, nonatomic) double confidence;

/**
 * Retrieves the start time in milliseconds of the current
 * <code>Sentence</code>.
 *
 * @return the start time
 */
@property (readonly, nonatomic) long startTime;

/**
 * Retrieves the end time in milliseconds of the current
 * <code>Sentence</code>.
 *
 * @return the end time
 */
@property (readonly, nonatomic) long endTime;

/**
 * Generates the string representation of the sentence.
 *
 * @return the sentence as a string
 */
//-(NSString *) getString;

@end
