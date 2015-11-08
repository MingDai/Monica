//
//  AudioChunk.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-26.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NMT_AudioType.h"

/**
 * Represents a 'chunk' of audio, with binary audio data and a type that indicates
 * how the audio data is encoded.
 */
@interface NMT_AudioChunk : NSObject

- (instancetype)initWithType:(NMT_AudioType*)audioType data:(NSData*)data timestamp:(long long)timestamp;

@property (readonly, nonatomic) NSData * data;

/** The type of audio in this chunk. */
@property (readonly, nonatomic) NMT_AudioType * audioType;

/** The timestamp at the start of this audio. */
@property (readonly, nonatomic) long long timestamp;

/** Speech status, from {@link SpeechStatus}. */
@property (readwrite, nonatomic) NMT_SpeechStatus speechStatus;

@end