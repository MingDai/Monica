/*
*  NMT_IAlternative.h
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
 * A representation of an alternative recognition. Returned by
 *  {@link DictationResult#alternatives}
 */
@protocol NMT_IAlternative <NSObject>

/**
 * Returns the string representation of the alternative.
 *
 * @return the word or the words separated by spaces
 */
//virtual const char* getString() = 0;

/**
 * Returns the number of tokens contained in this Alternative.
 *
 * @return  number of tokens
 */
//virtual unsigned int getSize() const = 0;

/**
 * Returns the token at the specified index.
 *
 * @return array of tokens
 */
@property (readonly, retain) NSArray * tokens;

@end
