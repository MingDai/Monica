/*
*  WordAction.h
*
*           Nuance Mobile Toolkit - Vocon
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
*
*/


#import <Foundation/Foundation.h>

#import <nmt_core/grammar/NMT_IWord.h>

/**
 * Specifies action of a word, such as add/remove etc.
 */
@interface NMT_WordAction : NSObject

/**
 * Creates an {@link NMT_WordAction} object with give parameters
 * @param word The word
 * @param added When this value is true, the word was added; when false, the word was removed.
 */
-(id) initWithWord:(id<NMT_IWord>)word added:(BOOL)added;

/**
 * Get the word.
 * @return The word in this action.
 */
@property  (readonly, retain) id<NMT_IWord> word;

/**
 * Returns true if the word should be added, or false if the word should be
 * removed.
 * @return true if the word should be added, false if it should be removed.
 */
@property  (readonly, nonatomic) BOOL isAdded;

@end
