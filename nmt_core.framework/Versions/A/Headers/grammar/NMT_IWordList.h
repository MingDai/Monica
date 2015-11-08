/*
*  WordList.h
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

#import <nmt_core/grammar/NMT_WordAction.h>
/**
 * Iterates through word actions.
 * <p>
 * Note: it is possible that while iterating through the list, the underlying
 * collection of words will have changed. This iterator reflects the state
 * of the word collection at the time {@link NMT_WordList#getFullIterator}
 * or {@link NMT_WordList#getModifiedIterator} was called. Likewise,
 * calling {@link #acceptChanges} will accept the actions specified by this
 * iterator, which may be different than the current state of the underlying
 * collection.
 */
@protocol NMT_IWordIterator <NSObject>

/**
 * @return if iterator has next member
 */
-(BOOL)hasNext;

/**
 * Get next member
 * @return next word action object.
 */
-(NMT_WordAction *) next;

/**
 * Accepts the list of words that was traversed using the {@link #next}
 * method. After accepting, if the entire list was traversed, the list
 * of words returned by subsequent calls to
 * {@link NMT_WordList#getModifiedIterator} will only include the remaining
 * words in the list (if the whole list was not traversed) as well as
 * changes to this list.
 * <p>
 * After accepting or discarding, this iterator must not be
 * accepted or discarded again.
 */
-(void) acceptChanges;

/**
 * Discards the list represented by this iterator. It is not 
 * required to call this method. That is, you can disregard the list
 * and never call {@link #acceptChanges}, but calling this method may
 * allow memory to be freed sooner.
 * <p>
 * After accepting or discarding, this iterator must not be
 * accepted or discarded again.
 */
-(void) discardChanges;

/**
 * @return The approximate number of word actions in the iterator.
 * If < 0, the number of word actions is unknown.
 */
-(int) count;

/**
 * Gets the checksum for the full list represented by this iterator.
 * Even though the iterator might only contain modifications, the checksum
 * reflects what the checksum of an equivalent full iterator.
 * @return The checksum
 */
-(int) checksum;

@end

@protocol NMT_IWordList <NSObject>

/**
 * Adds the Word Action at the end of the list.
 * @param pWordAction WordAction instance. Cannot be NULL.
 * @return True on success; False otherwise.
 */
-(BOOL) pushBack:(NMT_WordAction *) pWordAction;

/**
 * Returns the size of the list, in number of words.
 */
-(int) size;

/**
 * Gets the full list of word actions. Since this is the full list, all word
 * actions will be additions.
 * <p>
 * This method may block while the word list initializes.
 * @return Iterator to traverse all the word actions.
 */
-(id<NMT_IWordIterator>) getFullIterator;


/**
 * Gets the list of modifications since the last iterator that was accepted
 * via {@link NMT_WordIterator#acceptChanges}.
 * <p>
 * This method may block while the word list initializes.
 * @return Iterator to traverse the modified word actions.
 */
-(id<NMT_IWordIterator>) getModifiedIterator;

/**
 * Returns true if the underlying word list has changed so drastically, that
 * the modifications could not be acquired. In this case, {@link #getModifiedIterator}
 * will not be sufficient, so {@link #getFullIterator} must be used.
 * <p>
 * This method may block while the word list initializes.
 * @return true if a full update is required.
 */
-(BOOL) fullUpdateRequired;

/**
 * This method may block while the word list initializes.
 * @return The checksum of the last accepted iterator.
 */
-(int) getAcceptedChecksum;

@end
