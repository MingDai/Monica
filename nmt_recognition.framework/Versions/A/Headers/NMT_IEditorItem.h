/*
*  NMT_IEditorItem.h
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

typedef enum
{
    /**
     * The type TOKEN indicates that this EditorItem represents a result
     * as received from the server. Typically a TOKEN EditorItem can have
     * alternatives
     */
    NMT_TOKEN = 0,
    /**
     * The type WORD indicates that this EditorItem is inserted text or
     * a TOKEN that has been manually edited. A WORD EditorItem does not
     * have alternatives.
     */
    NMT_WORD,
    /**
     * The type WHITE_SPACE indicates that this EditorItem is a white space.
     * A WHITE_SPACE EditorItem does not have alternatives.
     */
    NMT_WHITE_SPACE
} NMT_EditorItemType;

@protocol NMT_IToken;

/**
 * The <code>EditorItem</code> is the basic component for representing text
 * within a <code>DictionEditBuffer</code> class and the <code>AlterChoice</code> class.
 * @see DictationEditBuffer
 * @see AlterChoice
 */
@protocol NMT_IEditorItem <NSObject>

/**
 * Returns the <code>Type</code> of this <code>EditorItem</code>
 *
 * @return Type of <code>EditorItem</code>
 */
@property (readonly, nonatomic) NMT_EditorItemType type;

/**
 * Retrieve length of <code>EditorItem</code> in number of characters
 *
 * @return length of edit buffer
 */
@property (readonly, nonatomic) int length;

/**
 * Return a <code>NMT_IToken</code> object if <code>NMT_IEditorItem</code> has type <code>NMT_TOKEN</code>.
 * Otherwise return nil.
 *
 */
@property (nonatomic) id<NMT_IToken> token;
/**
 * Returns the string representation of the current <code>EditorItem</code>
 *
 * @return string representation of the current <code>EditorItem</code>
 */
//virtual const char* getString() const = 0;


@end
