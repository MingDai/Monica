//
//  NMT_AudioPipeFactory.h
//  nmt
//
//  Created by Hao Zhou on 2014-02-05.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NMT_AudioPipe.h"
#import "NMT_AudioEnergyDelegate.h"
#import "NMT_AudioEnergyConfig.h"
#import "NMT_SpeechDetectionDelegate.h"
#import "NMT_SpeexConfig.h"
#import "NMT_OpusConfig.h"

NS_ROOT_CLASS
@interface NMT_AudioPipeFactory

/**
 * Creates a Buffering Pipe that buffers incoming audio until it is read.
 * Use the destroyRecorderSource function to release all underlying resources and the instance.
 *
 * \return Buffering Pipe instance.
 */
+ (NMT_AudioPipe*)createBufferingPipe;

+ (NMT_AudioPipe*)createAudioEnergyCalculatorPipe:(const NMT_AudioEnergyConfig *) config
                                         delegate:(id<NMT_AudioEnergyDelegate>) delegate;

+ (NMT_AudioPipe*)createDuplicatorPipe;

+ (NMT_AudioPipe*)createEndPointerPipe:(id<NMT_SpeechDetectionDelegate>) delegate;

+ (NMT_AudioPipe*)createResamplerPipe:(const NMT_AudioType *)audioType;

//+(NMT_AudioPipe*) createSimplePipe;

+ (NMT_AudioPipe*)createSpeexEncoderPipe;

/**
 * Initialize the Speex encoder with specific value of end of
 * speech parameters.
 */
+ (NMT_AudioPipe*)createSpeexEncoderPipe:(const NMT_SpeexConfig *) config;


+ (NMT_AudioPipe*)createSpeexDecoderPipe;

+ (NMT_AudioPipe*)createOpusEncoderPipe;

+ (NMT_AudioPipe*)createOpusEncoderPipe:(int) bitRate
                             complexity:(int) complexity
                                    vbr:(bool) vbr;

+ (NMT_AudioPipe*)createOpusDecoderPipe;

//NMT_API PrecisionClearBufferingPipe* createPrecisionClearBufferingPipe(int iMaxDurationMs = 10000);

//+(NMT_AudioPipe*) createWakeupPhraseAudioFilterPipe;

@end
