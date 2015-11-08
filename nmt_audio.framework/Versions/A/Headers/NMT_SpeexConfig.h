//
//  NMT_SpeexConfig.h
//  nmt
//
//  Created by Hao Zhou on 2014-02-05.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Initialize the Speex encoder with specific value of end of
 * speech parameters.
 * @param stopOnEndOfSpeech Enable or disable end of speech in
 * encoding process.
 * @param vadLongUtterance  Parameter used in end of speech detection.
 * @param vadHistoryLength  Parameter used in end of speech detection.
 * @param vadBeginLength    Parameter used in end of speech detection.
 * @param vadBeginThreshold Parameter used in end of speech detection.
 * @param vadBeginDelay     Parameter used in end of speech detection.
 * @param vadEndLength      Parameter used in end of speech detection.
 * @param vadEndThreshold   Parameter used in end of speech detection.
 * @param vadInterSpeechLength Parameter used in end of speech
 * detection.
 */
@interface NMT_SpeexConfig : NSObject

@property (nonatomic) BOOL  stopOnEndOfSpeech;
@property (nonatomic) int   vadLongUtterance;
@property (nonatomic) int   vadHistoryLength;
@property (nonatomic) int   vadBeginLength;
@property (nonatomic) int   vadBeginThreshold;
@property (nonatomic) int   vadBeginDelay;
@property (nonatomic) int   vadEndLength;
@property (nonatomic) int   vadEndThreshold;
@property (nonatomic) int   vadInterSpeechLength;

@end
