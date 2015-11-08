//
//  NMT_SingleSinkPipe.h
//  nmt
//
//  Created by Alexandre Loiseau on 2014-09-15.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <nmt_audio/NMT_AudioPipe.h>

@interface NMT_SingleSinkPipe : NMT_AudioPipe

/**
 * Gets the next audio chunk
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 * @return The audio chunk, or nil if there are none
 */
- (NMT_AudioChunk*)getAudioChunk;

/**
 * Get all audio chunks. Calls {@link #getAudioChunk} by default, override
 * for more efficiency.
 * @param chunks Vector where the new chunks will be added to
 */
- (void)getAllAudioChunks:(NSMutableArray*)array;

/**
 * Override to do something when a sink is connected.
 * @param sink The sink that was connected
 */
- (void)onSinkConnected:(NMT_AudioSink*)audioSink;

/**
 * Override to do something when a sink is disconnected.
 * @param sink The sink that was disconnected
 */
- (void)onSinkDisconnected:(NMT_AudioSink*)audioSink;

/**
 * Notify the connected sink (if any) that chunks are available.
 */
- (void)notifyChunksAvailable;

/**
 * Notify the connected sink (if any) that frames were dropped.
 */
- (void)notifyFramesDropped;

/**
 * Notify the connected sink (if any) that the source has closed.
 */
- (void)notifySourceClosed;

@end