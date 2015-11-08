//
//  AudioPipe.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-27.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_AudioSource.h>
#import <nmt_audio/NMT_AudioSink.h>

@interface NMT_AudioPipe : NMT_AudioSource

/**
 * Connect the audio source from which this module will obtain audio.
 * @param source The audio source this pipe connects to.
 */
- (BOOL)connectAudioSource:(NMT_AudioSource*)source;

/**
 * Disconnect the audio source that was previously connected via
 * {@link #connectAudioSource}. It is safe to call this module even if there is no
 * connected source.
 * @return The disconnected source, or null if there was no source to
 * disconnect.
 */
- (NMT_AudioSource*)disconnectAudioSource;

/**
 * Determine whether a source with the given audio type can be connected to
 * this pipe. The default AudioPipe implementation always returns true.
 * @param type The audio type
 * @return true if the audio type is supported.
 */
- (BOOL)isAudioSourceTypeSupported:(NMT_AudioType*)audioType;

/**
 * Internal method for obtaining the audio source that has been connected
 * via {@link #connectAudioSource}.
 * @return The connected audio source, or nil if none is connected.
 */
- (NMT_AudioSource*)connectedSource;

/**
 * Internal method for determining whether the connected audio source (or
 * the to-be connected audio source) is active.
 * @return YES if a source is connected and active.
 */
- (BOOL)isSourceActive;

/**
 * Internal method for getting the available chunks for the connected audio
 * source.
 * @return The number of chunks available from the connected source. Always
 * >= 0.
 */
- (NSInteger)getChunksAvailableFromSource;

/**
 * Internal method for getting an audio chunk from the connected audio source.
 * @return The next chunk from the connected source, or null if there are
 * no available chunks.
 */
- (NMT_AudioChunk*)getAudioChunkFromSource;

/**
 * Internal method for getting the audio type of the connected audio source.
 * @return The audio type of the connected source.
 */
- (NMT_AudioType*)getAudioTypeFromSource;

/**
 * The connected source has called {@link AudioSink#chunksAvailable} on the
 * internal sink.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 * @param audioSource The source that called {@link AudioSink#chunksAvailable}.
 * @param audioSink The internal sink, which should be used when calling
 * methods on the source.
 */
- (void)chunksAvailableFromSource:(NMT_AudioSource*)audioSource toSink:(NMT_AudioSink*)audioSink;

/**
 * The connected source has called {@link AudioSink#framesDropped} on the
 * internal sink.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 * @param audioSource The source that called {@link AudioSink#framesDropped}.
 * @param audioSink The internal sink, which should be used when calling
 * methods on the source.
 */
- (void)framesDroppedFromSource:(NMT_AudioSource*)audioSource toSink:(NMT_AudioSink*)audioSink;

/**
 * The connected source has called {@link AudioSink#sourceClosed} on the
 * internal sink.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 * @param audioSource The source that called {@link AudioSink#sourceClosed}.
 * @param audioSink The internal sink, which should be used when calling
 * methods on the source.
 */
- (void)sourceClosedFromSource:(NMT_AudioSource*)audioSource toSink:(NMT_AudioSink*)audioSink;

@end