/*
*  NMT_IInterpretation.h
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
#import <nmt_recognition/NMT_IToken.h>

/**
 * The type of the piece: either a simple token, or a dictation result.
 */
typedef enum
{
    NMT_TOKEN = 0,
    NMT_DICTATION_RESULT
} NMT_RawPieceType;

/**
 * A raw recognition piece. It represents a piece of text PRIOR to interpretation.
 */
@protocol NMT_IRawPiece <NSObject>


    /** The name of the piece. */
@property (readonly, retain) NSString * name;

    /** The type of the piece */
@property (readonly, nonatomic) NMT_RawPieceType type;

    /** The token of this piece. Will be null if the type is not {@link PieceType#NMT_ITOKEN} */
@property (readonly, retain) id<NMT_IToken> token;

    /** The dictation result of this piece. Will be null if the type is not {@link DICTATION_RESULT#DICTATION_RESULT} */
//-(id<NMT_IDictationResult>) getDictationResult;

    /** The confidence score. */
@property (readonly, nonatomic) double confidence;

@end

/**
 * An interpreted recognition slot. It represents a named chunk of the recognition--
 * for example, name could be "song_title" and text could be "Twinkle Twinkle Little Star".
 */
@protocol NMT_ISlot <NSObject>

/** The name of the slot, as defined in the interpretation grammar. Never null. */
@property (readonly, retain) NSString * name;

/** The contents of the slot. Never null. */
@property (readonly, retain) NSString * text;

/** The dictation result. May be null if this slot does not represent a full dictation. */
//-(id<NMT_IDictationResult>) getDictationResult;

/** The confidence score. */
@property (readonly, nonatomic) double confidence;

@end



@protocol NMT_IInterpretation <NSObject>

/**
 * @return The raw recognition pieces.
 */
@property (readonly, retain) NSArray * recognitionPieces;

/**
 * @return The interpreted slots.
 */
@property (readonly, retain) NSArray * slots;

/**
 * Get the interpreted slot with the given name.
 * @param name The slot name to look for
 * @return The interpreted slot, or null if it couldn't be found.
 */
-(id<NMT_ISlot>) getSlot:(NSString *)sName;

/**
 * Get the type of the recognition. Maps to SLOT_TYPE of the NVC_ASR_CMD. E.g. "call" or "play".
 * @return The recognition type, never null.
 */
@property (readonly, retain) NSString * type;

/**
 * @return The overall confidence score of the interpretation. TODO: what does it mean?
 */
@property (readonly, nonatomic) double confidence;

/**
 * Generates the string representation of the interpretation.
 *
 * @return the interpretation as a string
 */
//-(NSString *) getString;

@end
