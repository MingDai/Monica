/*
*  NMT_IAlterChoices.h
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

#import <nmt_recognition/NMT_IAlterChoice.h>

/**
 * The aggregate of each <code>AlterChoice</code> that is returned when
 * {@link DictationEditBuffer#getChoices(long, long)} is called.
 * It can also be used to replace the selected text in the edit buffer with one
 * of the choices returned.
 * @see DictationEditBuffer#getChoices(long, long)
 */
@protocol NMT_IAlterChoices <NSObject>

/**
 * Gets the total number of alternatives available.
 *
 * An <code>AlterChoices</code> object holds many alternatives to
 * choose from.
 * This method returns the total number of alternatives that are
 * available.
 *
 * @return the number of alternatives
 */
@property (readonly, nonatomic) unsigned int size;

/**
 * Gets the alternative at a certain position.
 *
 * An <code>AlterChoices</code> object holds many alternatives to choose
 * from. This method returns the alternative at a specified index.
 *
 * @param index Index of the requested AlterChoice
 * @return The alternative at position, or null if position is invalid.
 */
-(id<NMT_IAlterChoice>) getChoiceAt:(int) index;

/**
 * Selects the alternative to be used
 *
 * This method updates the <code>DictationEditBuffer</code> to which this
 * <code>AlterChoices</code> belongs with the choice at index. It replaces
 * the alternative currently used in <code>DictationEditBuffer</code> with
 * the one at index.
 * TODO(LXU)
 * If provided index is invalid, an IndexOutOfBound exception is thrown.
 *
 * For this method to successfully complete, the <code>DictationEditBuffer</code>
 * this <code>AlterChoices</code> object belongs should not have been modified
 * before calling choose.
 * TODO(LXU)
 * If a modification to <code>DicationEditBuffer</code>
 * has made this <code>AlterChoices</code> object out-of-date with respect to
 * <code>DicationEditBuffer</code> an IllegalStateException will be thrown.
 *
 * @param index Index of the chosen AlterChoice
 */
-(BOOL) choose:(int)index;

/**
 * Returns all alternative choices as an array of strings.
 *
 * This method provides a convenient way of obtaining a list of alternatives
 * as strings; where, the first string in the array represents the first
 * alternative, the second represents the second alternative, etc...
 * Typically, this method facilitates obtaining and displaying the alternatives
 * so that an end user can make a selection of the alternative that should be
 * used.
 *
 * @return alternative choices in an array of strings
 */
-(NSArray *) getStringArray;

@end
