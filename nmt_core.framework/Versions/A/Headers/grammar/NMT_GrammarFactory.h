/*
*  NMT_GrammarFactory.h
*
*           Nuance Mobile Toolkit - Core
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

#import "NMT_IWord.h"
#import "NMT_IWordList.h"

NS_ROOT_CLASS
@interface NMT_GrammarFactory

/**
 * Creates a custom word.
 * Must be destroyed with destroyWord when no longer used.
 * @param sSurfaceForm The written form of the word.
 * @param sSpokenForm May be null. This is the 'spoken' form of the word,
 * @return IWord instance.
 */
+(id<NMT_IWord>) createWord:(NSString *) sSurfaceForm spokenForm:(NSString *)sSpokenForm;

/**
 * Creates a custom word.
 * Must be destroyed with destroyWord when no longer used.
 * @param iUserId Serial UID to identify the word.
 * @param sSurfaceForm The written form of the word.
 * @param sSpokenForm May be null. This is the 'spoken' form of the word,
 * used for pronunciation.
 * @return IWord instance.
 */
+(id<NMT_IWord>) createWord:(int)iUserId surfaceForm:(NSString *)sSurfaceForm spokenForm:(NSString *)sSpokenForm;


/**
 * Creates a simple word list.
 * @param isFullList Determines whether the list is complete or an update to an existing one.
 *        If the latter, it is mandatory to specify the checksum of the previously uploaded one using [NMT_IWordList getAcceptedChecksum()]
 * @param iChecksum Checksum of the uploaded list prior to this update. Ignored parameter if isFullList true.
 */
+(id<NMT_IWordList>)createSimpleWordList:(BOOL)isFullList checksum:(int)checksum;


@end
