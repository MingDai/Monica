//
//  PlayerSink.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-21.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_AudioSink.h>

/**
 * Creates the player sink object.
 */
@protocol NMT_PlayerSinkDelegate;

@interface NMT_PlayerSink : NMT_AudioSink

@property (readonly, nonatomic, weak) id<NMT_PlayerSinkDelegate> delegate;

/**
 * Starts playing audio.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 * @param delegate Delegate to send progress notifications to.
 * @return YES if the playback session started successfully. NO otherwise.
 */
- (BOOL)startPlaying:(id<NMT_PlayerSinkDelegate>)delegate;

/**
 * Stops playing the audio.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 */
- (void)stopPlaying;

/**
 * Stops playing the audio immediately regardless of enqueued buffers.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 */
- (void)stopPlayingImmediately;

@end


/**
 * Listens for when the player stops.
 */
@protocol NMT_PlayerSinkDelegate <NSObject>

/**
 * The audio player started.
 * @param player
 */
- (void)onPlayerStarted:(NMT_PlayerSink*)player;

/**
 * The audio player stopped.
 * @param player
 */
- (void)onPlayerStopped:(NMT_PlayerSink*)player;

@end