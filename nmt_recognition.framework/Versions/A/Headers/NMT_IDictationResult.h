/*
*  NMT_IDictationResult.h
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
 * The unified representation of the dictation results. Presents the unified
 * representation to the mobile device user and manages changes to the dictation
 * results based on the user's interaction with them.
 * <br/><br/>
 * After a successful dictation, the dictation server returns bytes that represent
 * the dictation results. However, there are multiple formats for the dictation
 * results. The DictationResult interface is a generic
 * representation of all the different formats supported.
 * <br /><br />
 * The <code>DictationResultFactory</code> parses the bytes
 * and constructs a <code>DictationResult</code> object. This object
 * contains the top result (the result with the highest confidence score)
 * and alternative choices for each word or phrase.
 * <br /><br />
 * Typically, an application displays the top sentences on
 * the screen and lets the user select a <code>Sentence</code>. After a
 * <code>Sentence</code> is selected, the user can manipulate the result. The
 * user can move the cursor, select words, and insert or delete characters.
 * The application must be able to capture the following actions:
 * <br />
 * <ul>
 * <li>
 * When the user moves the cursor, the application determines the cursor
 * position.</li><br><br>
 * <li>The application gets alternative choices for the corresponding word
 * (or phrase if the device supports selection of multiple characters
 * in a text field) by invoking the method {@link DictationResult#getAlternatives(long, long)}.
 * The application can display the alternatives in a drop-down list
 * and let the user select.
 * </li><br><br>
 * </ul>
 * After the methods that modify the contents of <code>DictationResult</code>
 * are invoked, the method {@link Sentence#getString()} should always be called.
 * {@link Sentence#getString()} shows a string representation of the currently selected
 * sentence.
 * <br /><br />
 * The main purpose of updating the <code>DictationResult</code> is to
 * continue to generate suitable word alternatives even when the user modifies
 * the dictation result.
 * <br/>
 * <br />
 * <strong>Example</strong>
 * <br />
 * <em>DictationResult</em>
 * <br />
 * <br />
 * The diagram below shows an example of a <code>DictationResult</code> object and
 * some standard operations that a user can perform on this object.
 * <br /><br />
 * <ul>
 * <li>
 * You can get the top choice result phrase string in two ways:<br/><br/>
 * <ul>
 * <li>By  calling the {@link #getString()} method
 * </li><br><br>
 * <li>Or by first calling {@link #sentenceAt(int)} for index
 * 0, which is the top choice, and then calling {@link Sentence#getString()};
 * </li></ul>
 * </ol>
 *
 */
@protocol NMT_IDictationResult <NSObject>
/**
 * Returns the number of sentence contained in the DictationResult.
 *
 * @return number of sentences
 */
@property (readonly, retain) NSArray * sentences;

/**
 * Returns the string representation of the sentence with the
 * highest confidence score from the dictation result list of
 * sentences.
 *
 * @return string representation of the sentence with the
 * highest confidence score
 */
//-(NSString *) getString;

/**
 * Returns a map of specific information attached to a key that
 * the dictation engine returns along with the data.
 *
 * @return map containing information for specific keys
 */

@property (readonly, retain) NSDictionary * extraInformation;

/**
 * Returns a list of all the alternatives for the tokens inside
 * the region delimited by time range (startTime, endTime).
 * A token is an entry (usually a word) in the dictionary
 * of the dictation recognition engine.
 *
 * User is responsible to release the IAlternatives memory
 *
 * @param startTime begin time of tokens
 * @param endTime end time of tokens
 * @return the aggregate <code>Alternatives</code> of <code>Alternative</code>
 */
-(NSArray *) getAlternatives:(long)startTime  endTime:(long)endTime;

/**
 * Merge a new dictation result into current dictation result.
 *
 * @param newDictationResult dictation result  to be merged.
 * @param startTime  start time of the dictation result where the new result
 *  to be inserted
 * @param endTime      end time of the dictation result where the new result
 *  to be inserted
 */
-(BOOL) merge:(id<NMT_IDictationResult>) pNewDictationResult startTime:(long)nStartTime endTime:(long)nEndTime;

/**
 * insert a new dictation result at the end of current dictation result.
 * @param newDictationResult the dictation result to be appended.
 */
-(BOOL) append:(id<NMT_IDictationResult>) pNewDictationResult;

/**
 * Get the JSON representation of the object.
 * @return A new JSON object representing the object.
 */
//virtual core::IJsonText* toJson() = 0;

@end
