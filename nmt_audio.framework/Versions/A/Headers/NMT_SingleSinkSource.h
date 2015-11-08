//
//  NMT_SingleSinkSource.h
//  nmt
//
//  Created by Alexandre Loiseau on 2014-09-15.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import "NMT_AudioSource.h"

@interface NMT_SingleSinkSource : NMT_AudioSource

/**
 * Gets the next audio chunk
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 * @return The audio chunk
 */
- (NMT_AudioChunk*)getAudioChunk;

/**
 * Override to do something after a sink is connected.
 * @param sink The sink that was connected
 */
- (void)onSinkConnected:(NMT_AudioSink*)audioSink;

/**
 * Override to do something after a sink is disconnected.
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