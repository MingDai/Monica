/*
*  NMT_IWord.h
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

@protocol NMT_IWord <NSObject>

/**
 * Returns a copy of the current instance.
 * The returned instance must also be destroyed with destroyWord when no longer in use.
 */
-(id<NMT_IWord>) copy;

/**
 * Determines whether the provided pWord instance equals the current one.
 */
-(BOOL) equals:(id<NMT_IWord>)word;

/**
 * Get the surface form of the word. That is, the way the word appears in
 * written form.
 */
-(NSString *) surfaceForm;

/**
 * Get the spoken form of the word.  Note that most languages do not require
 * a spoken form. In that case it can be null.
 */
-(NSString *) spokenForm;

/**
 * Get the user ID.
 * @return The user ID
 */
-(int) userId;

@end
