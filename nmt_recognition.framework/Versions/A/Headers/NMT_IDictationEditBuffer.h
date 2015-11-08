/*
*  NMT_IDictationEditBuffer.h
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

#import <nmt_recognition/NMT_IAlterChoices.h>

/**
 * The result of a dictation, as received from the recognition server, contains
 * the most likely result along with alternative but less likely results. The
 * <code>DicationEditBuffer</code> facilitates retrieving the main result and the
 * alternative results of a dictation. In addition, it supports several manual
 * edits on the result.
 * Once created, the <code>DictationEditBuffer</code> represents the most likely
 * result by default.
 * @see DictationResultManager#createDictationEditBuffer(byte[], long)
 * @see DictationResultManager#createDictationEditBuffer(DictationResult, long)
 */
@protocol NMT_IDictationEditBuffer <NSObject>

/**
 * Retrieve length of edit buffer
 *
 * This method returns the current total number of characters this
 * <code>DictationEditBuffer</code> contains.
 *
 * @return length of edit buffer
 */
@property (readonly, nonatomic) unsigned long length;

/**
 * Retrieve the list of <code>EditorItem</code> objects
 *
 * The <code>DictationEditBuffer</code> aggregates a list of <code>EditorItems</code>.
 * This method allows the user to obtain the list of <code>EditorItems</code> that
 * represent this <code>DictationEditBuffer</code>.
 *
 * @return Array of <code>EditorItem</code>
 */
@property (readonly, retain) NSArray * items;

/**
 * Retrieve a list of all possible alternatives for text range of [start, end).
 *
 * By default the <code>DicationEditBuffer</code> represents the most likely
 * recognition result. To obtain alternative recognition results for part or
 * all of the current result, this method can be used.
 * This method will return all the possible alternatives within the specified range.
 * The returned results will be ordered from most likely to least likely, and the
 * currently used alternative will be included in the list.
 *
 * @param start The start position of text range
 * @param end The position one past the last character of the text range
 * @return <code>AlterChoices</code> object that aggregates the alternatives
 */
-(id<NMT_IAlterChoices>) getChoicesWithStartTime:(long)startTime endTime:(long)endTime;

/**
 * Insert a char
 *
 * This method modifies the current <code>DictationEditBuffer</code> by adding
 * a character at the indicated position
 *
 * @param pos position to insert char
 * @param c char to be inserted
 */
-(BOOL) insert:(long)nPos withChar:(char)c;

/**
 * Insert a string
 *
 * This method modifies the current <code>DictationEditBuffer</code> by
 * inserting a string at the indicated position
 *
 * @param pos position to insert string
 * @param text string to be inserted
 */
-(BOOL) insert:(long)nPos withString:(NSString *)sText;

/**
 * Delete a char
 *
 * This method removes a char at the indicated position.
 *
 * @param pos position of char to be deleted
 */
-(BOOL) deleteChar:(long) nPos;

/**
 * Delete text in range [start, end)
 *
 * This method removes the text contained in the indicated range.
 * The start position is included in the range, the end position is excluded
 * from the range. I.e., the character at end will not be deleted.
 *
 * @param start The start position of text to be deleted
 * @param end The position one past the last character to be deleted
 */
-(BOOL) deleteText:(long)nStart end:(long)nEnd;

/**
 * Replace editor text in range [start, end) with a string
 *
 * This method replaces the text contained in the indicated range with the
 * specified string.
 * The start position is included in the range, the end position is excluded
 * from the range. I.e., the character at end will not be deleted.
 *
 * @param start The start position of text to be replaced
 * @param end The position one past the last character to be replaced
 * @param text new text string to replace editor text.
 */
-(BOOL) replace:(long)nStart end:(long)nEnd text:(NSString *)sText;

/**
 * Update whole editor buffer with new text
 *
 * This method will update the entire <code>DictationEditBuffer</code> with
 * the specified string. This method will compare the original text to the
 * updated text, and detect and apply the changes.
 *
 * @param text new text string to update editor buffer
 */
-(BOOL) update:(NSString *)sText;

/**
 * Returns the string representation of the current editor text
 *
 * This method returns the current <code>DictationEditBuffer</code> as a string.
 *
 * @return string representation of the current editor text
 */
//-(NSString *)getString() = 0;

/**
 * Merge with a new dictation result buffer from dictation recognition server
 * and replace text within the range of [start, end)
 * @param buffer the binary data received from dictation recognition server
 * to be merged
 * @param start The start position of text to be replaced
 * @param end The position one past the last character to be replaced
 */
-(BOOL) merge:(NSData *)buffer start:(long)nStart end:(long)nEnd;

/**
 * Append a new dictation result buffer at the end of current buffer
 * @param buffer the binary data received from dictation recognition server
 * to be merged
 */
-(BOOL) append:(NSData *)buffer;

@end
