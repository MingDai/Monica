//
//  NMT_AudioSourceFactory.h
//  nmt
//
//  Created by Hao Zhou on 2014-02-05.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_audio/NMT_RecorderSource.h>
#import <nmt_audio/NMT_StreamingBufferAudioSource.h>

NS_ROOT_CLASS
@interface NMT_AudioSourceFactory

/**
 * Creates an Audio Source that uses a sequence of audio buffers pushed by the user.
 * The source can be reused, its state will be reset upon every 'start' call.
 *
 * \param audioType Audio Type that must match the data found in pBuffer.
 *
 * \return Audio Source instance.
 */
+ (NMT_StreamingBufferAudioSource*)createStreamingBufferAudioSource:(NMT_AudioType*)audioType;

/**
 * Creates a Recorder Source that uses the microphone to grab audio.
 * Use the destroyRecorderSource function to release all underlying resources and the instance.
 *
 * \param audioType Audio Type that will be used to initialize the recording device when startRecording is called.
 *		  If the Audio Type is not supported by the Microphone Recorder Source, failure will occur.
 * \return Recorder Source instance.
 */
+ (NMT_RecorderSource*)createMicrophoneRecorderSource:(NMT_AudioType *)audioType;

/**
 * Creates a Recorder Source that uses the specified file path to grab audio.
 * Upon record start (startRecording), audio samples will be read as fast as possible and buffered for consumption.
 * Use the destroyRecorderSource function to release all underlying resources and the instance.
 *
 * \param audioType Audio Type that will be used to read audio samples when startRecording is called.
 *		  The provided audioType must match the content of the headerless RAW file.
 * \param filePath Null-terminated string that contains the headerless RAW source file path to read audio from.
 * \param littleEndian Specifies the endianness of the audio samples in file. YES for little-endian, NO for big-endian.
 * \return Recorder Source instance.
 */
+ (NMT_RecorderSource*)createBurstFileRecorderSource:(NMT_AudioType *)audioType
                                               filename:(NSString *) filePath
                                           littleEndian:(BOOL)littleEndian;

/**
 * Creates a Recorder Source that uses the specified file path to grab audio.
 * Upon record start (startRecording), audio samples will be read in a periodic manner to create a constant
 * stream of audio data, such as a microphone. The read intervals are based on the provided rAudioType.
 * Use the destroyRecorderSource function to release all underlying resources and the instance.
 *
 * \param audioType Audio Type that will be used to read audio samples when startRecording is called.
 *		  The provided audioType must match the content of the headerless RAW file.
 *
 * \param filePath Null-terminated string that contains the headerless RAW source file path to read audio from.
 * \param littleEndian Specifies the endianness of the audio samples in file. YES for little-endian, NO for big-endian.
 * \return Recorder Source instance.
 */
+ (NMT_RecorderSource*)createStreamingFileRecorderSource:(NMT_AudioType *)audioType
                                                   filename:(NSString *) filename
                                               littleEndian:(BOOL)littleEndian;


@end
