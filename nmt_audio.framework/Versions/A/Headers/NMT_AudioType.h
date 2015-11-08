//
//  AudioType.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-22.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_core/JSONCompliant.h>

/**
 * Valid speech status values for an audio chunk.
 */
typedef NS_ENUM(NSInteger, NMT_SpeechStatus)
{
    /**
     * Indicates that the speech status is unknown.
     */
    NMT_SPEECH_STATUS_UNKNOWN,
    
    /**
     * Indicates that this chunk does not contain speech data.
     */
    NMT_SPEECH_STATUS_NOT_SPEECH,
    
    /**
     * Indicates that this chunk contains speech data.
     */
    NMT_SPEECH_STATUS_SPEECH
};

/**
 * Encoding types
 */
typedef NS_ENUM(NSInteger, NMT_AudioEncoding)
{
    NMT_CODEC_PCM_16,
    NMT_CODEC_SPEEX,
    NMT_CODEC_OPUS,
    NMT_CODEC_UNKNOWN
};

/**
 * Sampling rates
 */
typedef NS_ENUM(NSInteger, NMT_AudioFrequency)
{
    NMT_FREQ_8KHZ  = 8000,
    NMT_FREQ_11KHZ = 11025,
    NMT_FREQ_16KHZ = 16000,
    NMT_FREQ_22KHZ = 22050
};


@interface NMT_AudioType : NSObject<NMT_JSONCompliant>

/** The audio encoding. */
@property (readonly, nonatomic) NMT_AudioEncoding encoding;

/** The sampling rate, expressed in samples per second. See {@link Frequency}. */
@property (readonly, nonatomic) NSUInteger sampleRate;

@property (readonly, nonatomic) NSUInteger channelCount;

@property (readonly, nonatomic) NSUInteger bytesPerSample;

@property (readonly, nonatomic) NSUInteger bytesPerFrame;

-(id)initWithEncoding:(NMT_AudioEncoding)encoding sampleRate:(NSUInteger)sampleRate channelCount:(NSUInteger)channelCount;

-(NSUInteger)getFrameCount:(NSUInteger)durationMs;

-(NSUInteger)getDurationByLength:(NSUInteger)length;

-(BOOL)equals:(NMT_AudioType *)audioType;

@end

/** {@link Encoding#PCM_16} and {@link Frequency#FREQ_22KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_PCM_22k;
/** {@link Encoding#PCM_16} and {@link Frequency#FREQ_16KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_PCM_16k;
/** {@link Encoding#PCM_16} and {@link Frequency#FREQ_11KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_PCM_11k;
/** {@link Encoding#PCM_16} and {@link Frequency#FREQ_8KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_PCM_8k;
/** {@link Encoding#SPEEX} and {@link Frequency#FREQ_16KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_SPEEX_WB;
/** {@link Encoding#SPEEX} and {@link Frequency#FREQ_8KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_SPEEX_NB;
/** {@link Encoding#SPEEX} and {@link Frequency#FREQ_16KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_OPUS_WB;
/** {@link Encoding#SPEEX} and {@link Frequency#FREQ_8KHZ} */
extern NMT_AudioType* NMT_AUDIO_TYPE_OPUS_NB;
/** Unknown audio type. */
extern NMT_AudioType* NMT_AUDIO_TYPE_UNKNOWN;
