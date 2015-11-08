//
//  NMT_AudioSinkFactory.h
//  nmt
//
//  Created by Hao Zhou on 2014-02-05.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_PlayerSink.h>
#import <nmt_audio/NMT_AudioQueuePlayerSink.h>

NS_ROOT_CLASS
@interface NMT_AudioSinkFactory

/**
 * Creates a Player Sink that uses the default playback device to send audio.
 * Upon playback start (startPlaying), the default playback device will be initialized
 * with the settings provided by the rAudioType instance.
 * Use the destroyPlayerSink function to release all underlying resources and the instance.
 *
 * \param rAudioType Audio Type that will be used to initialize the playback device when startPlaying is called.
 *		  If the Audio Type is not supported by the Speaker Player Sink, failure will occur upon playback.
 *
 * \return Player Sink instance.
 */
+ (NMT_PlayerSink*)createSpeakerPlayerSink:(NMT_AudioType *)audioType;

/**
 * Creates a Player Sink that uses the specified file path to send audio.
 * Upon playback start (startPlaying), the audio samples will be written according to
 * the settings provided by the rAudioType instance. The file type is headerless RAW.
 * Use the destroyPlayerSink function to release all underlying resources and the instance.
 *
 * \param rAudioType Audio Type that will be used to save audio samples when startPlaying is called.
 *		  If the Audio Type is not supported by the File Player Sink, failure will occur upon playback.
 *
 * \param sFilePath Null-terminated string that contains the destination file path to write audio to.
 *
 * \return Player Sink instance.
 */
+ (NMT_PlayerSink*)createFilePlayerSink:(NMT_AudioType *)audioType filename:(NSString *)filename;

/**
 * Creates a player that uses an NMT worker thread.
 *
 * @param audioType The audio type to play. Cannot be null.
 */
+ (NMT_AudioQueuePlayerSink*)createAudioQueuePlayerSink:(NMT_AudioType *)audioType;

@end
