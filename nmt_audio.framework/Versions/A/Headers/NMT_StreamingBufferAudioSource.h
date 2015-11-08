//
//  NMT_StreamingBufferAudioSource.h
//  nmt
//
//  Created by Alexandre Loiseau on 2014-09-05.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_SingleSinkSource.h>

@protocol NMT_StreamingBufferSourceDelegate;

@interface NMT_StreamingBufferAudioSource : NMT_SingleSinkSource

/**
 * Puts the Audio Source in ready state to start streaming.
 * @param delegate Delegate that sends notifications through the process.
 * @return True if the async request succeeds, False otherwise. Errors encountered within the
 *         process will be reported via the provided delegate (onAudioSourceError).
 */
- (BOOL)start:(id<NMT_StreamingBufferSourceDelegate>)delegate;

/**
 * Indicates that the Audio Source is done streaming.
 * @return True if the async request succeeds, False otherwise. Errors encountered within the
 *         process will be reported via the provided delegate (onAudioSourceError).
 */
- (BOOL)stop;

/**
 * Push audio buffer for streaming through the audio chain.
 * @param audioData Buffer containing audio data that matches the AudioType specified at construction.
 * \return YES if the async request succeeds, NO otherwise. Basic validation is done to ensure that buffer size
 *         is a multiple of the expected audio frame size. Errors encountered within the message execution will be
 *         reported via the provided delegate (onAudioSourceError).
 */
- (BOOL)pushAudio:(NSData*)audioData;

/**
 * Push audio chunk for streaming through the audio chain.
 * \param audioChunk Audio Chunk object that will be passed as-is through the audio chain.
 *        Note that its AudioType must match the one specified at construction.
 * \return YES if the async request succeeds, NO otherwise. Basic validation is done to ensure that buffer size
 *         is a multiple of the expected audio frame size. Errors encountered within the message execution will be
 *         reported via the provided delegate (onAudioSourceError).
 */
- (BOOL)pushAudioChunk:(NMT_AudioChunk*)audioChunk;


@end

@protocol NMT_StreamingBufferSourceDelegate <NSObject>

/**
 * The recorder has started recording.
 * @param audioSource
 */
- (void)onAudioSourceStarted:(NMT_AudioSource*)audioSource;

/**
 * The recorder has stopped recording.
 * @param audioSource
 */
- (void)onAudioSourceStopped:(NMT_AudioSource*)audioSource;

/**
 * The recorder has encountered an error.
 * @param audioSource
 * @param code Implementation specific error code.
 * @param message Error message.
 */
- (void)onAudioSourceError:(NMT_AudioSource*)audioSource code:(NSInteger)code message:(NSString*)message;

@end