/*
*  NMT_IInterpretedRecognition.h
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
/**
 * A recognition 'phrase', which represents a chunk of text from a recognition.
 * The phrase may have an associated key, and start/end timing information.
 */
@protocol NMT_IPhrase <NSObject>
    /**
     * Get the key for this phrase.
     * @return The key (may be null).
     */
@property (readonly, retain) NSString * key;
    
    /**
     * Determine whether this phrase contains recognized text. Some phrases
     * might represent text that was detected by the engine, but not
     * recognized.
     * @return true if the phrase contains recognized text.
     */
@property (readonly, nonatomic) BOOL isRecognized;
    
    /**
     * Get the custom pronunciation of the recognized text, if it is
     * different than the recognized text itself.
     * @return List of words.
     */
@property (readonly, retain) NSArray * words;
    
    /**
     * Get the start time of this word, in ms.
     * <p>If timings are unsupported, both {@link #getStartTime} and
     * {@link #getEndTime} will return {@link #TIMING_NOT_SUPPORTED}.
     * @return The start time, or {@link #TIMING_NOT_SUPPORTED}
     */
@property (readonly, nonatomic) int64_t startTime;
    
    /**
     * Get the end time of this word, in ms.
     * <p>If timings are unsupported, both {@link #getStartTime} and
     * {@link #getEndTime} will return {@link #TIMING_NOT_SUPPORTED}.
     * @return The end time, or {@link #TIMING_NOT_SUPPORTED}
     */
@property (readonly, nonatomic) int64_t endTime;
    
    /**
     * Get the extra data for this phrase.
     * @return May return null.
     */
@property (readonly, retain) NSDictionary * extra;
    
    /**
     * Get the dictation result that comes with this phrase.
     * @return May return null if this phrase does not have a dictation
     * result.
     */
//-(id<NMT_IDictationResult>) dictationResult;

//-(NSString *) getString;

    /**
     * Get the JSON representation of the object.
     * @return A new JSON object representing the object.
     */
//    virtual core::IJsonText* toJson() = 0;

@end

/**
 * A recognition choice. A recognition may consist of multiple alternative
 * choices.
 */
@protocol NMT_IInterpretedRecognition;

@protocol NMT_IChoice <NSObject>
/**
 * Get the type of the recognition (e.g. "call_cmd")
 * @return The type.
 */
@property (readonly, retain) NSString * recognitionType;

/**
 * Determine whether all phrases in the choice are fully recognized.
 * @see Phrase#isRecognized
 * @return true if all phrases in the choice are fully recognized
 */
@property (readonly, nonatomic) BOOL isAllRecognized;

/**
 * Determine whether this choice and another choice match.
 * @param otherChoice The other choice
 * @return true if this choice and the other choice have the same
 * recognition type and exactly the same phrase keys.
 */
-(BOOL) matches:(id<NMT_IChoice>) otherChoice;

/**
 * Return a new choice, with unrecognized phrases resolved using another
 * interpreted recognition.
 * @param otherRecog The other recognition. This method will search
 * through all its choices until it finds one with a recognized phrase
 * matching the key of the unrecognized phrase in this choice.
 * @param allowUnrecognized True if the returned choice may have
 * remaining unrecognized phrases. False if not--null will be returned
 * if any unrecognized phrases would remain.
 * @return The new choice with as many unrecognized phrases resolved as
 * possible, or null if some phrases couldn't be resolved.
 */
-(id<NMT_IChoice>) resolveUnrecognizedPhrases:(id<NMT_IInterpretedRecognition>)pOtherRecog allUnrecognized:(BOOL)allowUnrecognized;

/**
 * Get the score for this choice. TODO: what does a score mean?
 * @return The score.
 */
@property (readonly, nonatomic) int score;

/**
 * Get the phrases, in order of their timings, from this choice.
 * @return The phrases.
 */
@property (readonly, retain) NSArray * phrases;

/**
 * Get the phrase with the given key.
 * @param key
 * @return The phrase, or null if no phrase exists with the key.
 */
-(id<NMT_IPhrase>) getPhrase:(NSString *)sKey;

/**
 * Get the extra data for this choice.
 * @return May return null. Could be used for NLU results.
 */
@property(readonly, retain) NSDictionary * extra;

/**
 * Get the full text transcription of this choice. May not be formatted
 * correctly for display, e.g. there may be unexpected spaces.
 */
//-(NSString *) getString;

/**
 * Get the JSON representation of the object.
 * @return A new JSON object representing the object.
 */
//virtual core::IJsonText* toJson() = 0;

@end

/**
 * A generic interpreted recognition interfaces. This can be used to represent a
 * number of different types of recognition results (e.g. Elvis, Cloud, VoCon).
 */
@protocol NMT_IInterpretedRecognition <NSObject>

/**
 * Get the prompt that accompanies the result.
 * @return May return null
 */
@property (readonly, retain) NSString * prompt;

/**
 * Equivalent to calling {@link Choice#getScore} of the 0th choice.
 * @return The score of the best choice.
 */
@property (readonly, nonatomic) int score;

/**
 * Returns the confidence that the gate command is correct.
 * 100 indicates highest confidence, 0 indicates lowest confidence.
 * -1 indicates that the gate confidence is not available.
 * (Gate confidence is only available for Elvis premium models)
 * @return The confidence
 */
@property (readonly, nonatomic) int confidence;

/**
 * Equivalent to calling {@link Choice#getPhrases}.
 * @return The phrases.
 */
@property (readonly, retain) NSArray * phrases;

/**
 * Equivalent to calling {@link Choice#getPhrase}.
 * @param key
 * @return The phrase, or null if no phrase exists with the key.
 */
-(id<NMT_IPhrase>) getPhrase:(NSString *)key;

/**
 * Add a choice.
 * @param transcription
 * @param recognitionType e.g. "call_cmd"
 * @param score
 * @param phrases
 * @param extra May be null.
 */
-(void) addChoice:(NSString *)sTranscription type:(NSString *)sRecognitionType score:(int)iScore phrases:(NSArray *)iPhraseArray extra:(NSDictionary *)pExtra;

/**
 * Add a choice.
 * @param transcription
 * @param recognitionType e.g. "call_cmd"
 * @param score
 * @param phrases
 * @param extra May be null.
 */
-(void) addChoice:(id<NMT_IChoice>)choice;

/**
 * Get the choice array.
 * @return The number of choices.
 */
@property (readonly, retain) NSArray * choices;

/**
 * Get the JSON representation of the object.
 * @return A new JSON object representing the object.
 */
//virtual core::IJsonText* toJson() = 0;


@end
