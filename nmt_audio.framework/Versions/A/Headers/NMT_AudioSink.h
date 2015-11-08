//
//  AudioSink.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-26.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_AudioSource.h>

/**
 * An audio sink object that accepts audio from an {@link NMT_AudioSource}.
 */
@interface NMT_AudioSink : NSObject

/**
 * Get the connected source.
 * @return The connected source, or nil if no source is connected.
 */
@property (readonly, nonatomic) NMT_AudioSource* connectedSource;

/**
 * Connects an AudioSource to this AudioSink. Set up all the necessary
 * information so that the source will generate audio and the sink will read
 * it automatically.
 *
 * @param source The audio source this sink connects to.
 */
- (BOOL)connectAudioSource:(NMT_AudioSource*)source;
    
/**
 * Disconnects the current AudioSource from this AudioSink. It is safe to
 * call this module even if there is no connected source.
 * @return The disconnected source, or null if there was no source to
 * disconnect.
 */
- (NMT_AudioSource*)disconnectAudioSource;

/**
 * Determines whether the specified audioType is compatible with this
 * Audio Sink. Default implementation returns YES.
 * @remarks Should be overridden by subclass when only specific audio formats are supported.
 * @param audioType Audio Type to test compatibility with.
 * @return YES if specified audioType is compatible with current Audio Sink.
 */
- (BOOL)isAudioSourceTypeSupported:(NMT_AudioType*)audioType;

/**
 * Called once the previously connected Audio Source is disconnected.
 * Default implementation does nothing.
 * @param audioSource The Audio Source that just got disconnected.
 */
- (void)audioSourceDisconnected:(NMT_AudioSource*)audioSource;

/**
 * Called by the AudioSource associated with this AudioSink when new data
 * has been added to the source. This tells this AudioSink that it can read
 * some audio from the source if the sink was waiting on new data.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 *
 * @param audioSource The AudioSource that is notifying this AudioSink of data
 */
- (void)chunksAvailable:(NMT_AudioSource*)audioSource;

/**
 * Called by the AudioSource associated with this AudioSink when data was
 * not read fast enough and the source's internal buffer overflowed. The
 * entire utterance is probably invalid and it is up to this sink to notify
 * the system appropriately.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 *
 * @param source The source that overflowed
 */
- (void)framesDropped:(NMT_AudioSource*)audioSource;

/**
 * Called by the AudioSource associated with this AudioSink when the source
 * will no longer generate any new audio chunks other than what is already
 * available inside it.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 *
 * @param source The source that just closed
 */
- (void)sourceClosed:(NMT_AudioSource*)audioSource;

@end
