/*
*  NMT_IAlterChoice.h
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

#import <nmt_recognition/NMT_IEditorItem.h>
/**
 * This class represents an alternative for a given text in the edit buffer.
 * It is an aggregate of the <code>EditorItem</code> objects that constitute
 * the alternative. It is returned by the <code>AlterChoices#getChoiceAt(int)</code>
 * method.
 * @see AlterChoices#getChoiceAt(int)
 */
@protocol NMT_IAlterChoice <NSObject>

/**
 * Returns the string representation of this <code>AlterChoice</code>.
 *
 * @return A string representation of this <code>AlterChoice</code>.
 */
//virtual const char* getString() = 0;

/**
 * Returns the number of <code>EditorItem</code> objects contained in
 * this <code>Alternative</code>.
 *
 * The <code>AlterChoice</code> object is constituted of one or more
 * <code>EditorItem</code> objects. This method returns the total number
 * of editor items that constitute this <code>AlterChoice</code>.
 *
 * @return  number of EditorItems
 */
@property (readonly, nonatomic) unsigned int size;

/**
 * Returns the <code>EditorItem</code> at the specified index.
 *
 * The <code>AlterChoice</code> object is constituted of one or
 * more <code>EditorItem</code> objects. This method returns the
 * <code>EditorItem</code> at the specified index.
 *
 * @param index Index of the requested <code>EditorItem</code>
 * @return <code>EditorItem</code> at the indicated index, or null if index is invalid
 */
-(id<NMT_IEditorItem>) editorItemAt:(int) index;

@end
