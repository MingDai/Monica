//
//  TtsSpec.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-25.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_AudioType.h>
#import <nmt_core/JSONCompliant.h>


/**
 * Defines a TTS request for {@link NMT_CloudVocalizer}.
 */
@interface NMT_TtsSpec : NSObject<NMT_JSONCompliant>

/**
 * @param command The name of the TTS command, e.g. "NVC_TTS_COMMAND". Cannot be nil.
 * @param settings The custom command settings, if any. Can be nil.
 * @param ttsParamName The name of the TTS parameter. Cannot be nil.
 * @param ttsParamData The data to send in the TTS parameter. Cannot be nil.
 * @param audioType The type of the audio. Cannot be nil.
 */
-(id) initWithCommand:(NSString *)command settings:(NSDictionary *)settings ttsParamName:(NSString *)ttsParamName
ttsParamData:(NSDictionary *)ttsParamData audioType:(const NMT_AudioType *)audioType;

/**
 * readonly property The command name.
 */
@property (readonly, retain) NSString * command;

/**
 * readonly property The command settings.
 */
@property (readonly, retain) NSDictionary * settings;

/**
 * readonly property The TTS param name.
 */
@property (readonly, retain) NSString * ttsParamName;

/**
 * readonly property The TTS param data.
 */
@property (readonly, retain) NSDictionary * ttsParamData;

/**
 * readonly property The audio type.
 */
@property (readonly, retain) const NMT_AudioType * audioType;

@end
