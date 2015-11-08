/*
*  NMT_DictationResultManager.h
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

#import <nmt_recognition/NMT_IDictationResult.h>
#import <nmt_recognition/NMT_IDictationEditBuffer.h>
#import <nmt_recognition/NMT_IInterpretationResult.h>

/**
 * Hides the results type from the users and creates the unified representation of a dictation
 * result. The unified representation is presented to the mobile device through the interface
 * {@link IDictationResult}.
 * <br>
 * <br>
 * Supports Dragon Naturally Speaking  (V.1 and V.2) binary results and XML results.
 *
 * @see IDictationResult
 */
NS_ROOT_CLASS
@interface NMT_DictationResultManager

/**
 * The factory methods that identify the results format and return
 * the unified <code>DictationResult</code> data structure.
 *
 * @param buffer the binary data received from dictation recognition server
 * @return the unified data structure <code>DictationResult</code>
 * TODO(LXU) @throws IllegalArgumentException thrown if the parsers are unable to parse the data
 */
+(id<NMT_IDictationResult>)createDictationResult:(NSData *) buffer;

/**
 * Create dictation edit buffer from DictationResult object
 * @param result the DictationResult object containing the results received from the dictation recognition server
 * @param maxSize maximum buffer size.
 * @return  the unified data structure <code>DictationEditBuffer</code>
 */
+(id<NMT_IDictationEditBuffer>) createDictationEditBuffer:(id<NMT_IDictationResult>) pResult maxSize:(unsigned long)nMaxSize;

/**
 * Create dictation edit buffer from binary data
 * @param buffer the binary data received from dictation recognition server
 * @param maxSize maximum buffer size.
 * @return  the unified data structure <code>DictationEditBuffer</code>
 * TODO(LXU) @throws IllegalArgumentException
 */
+(id<NMT_IDictationEditBuffer>) createDictationEditBufferWithBuffer:(NSData *)buffer maxSize:(unsigned long) nMaxSize;

/**
 * Create an interpretation result from a byte buffer in nlsml format
 *
 * @param buffer the binary data received from dictation recognition server
 * @return the unified data structure <code>InterpretationResult</code>
 * TODO(LXU) @throws IllegalArgumentException
 */
+(id<NMT_IInterpretationResult>) createInterpretationResult: (NSData *) buffer;

@end
