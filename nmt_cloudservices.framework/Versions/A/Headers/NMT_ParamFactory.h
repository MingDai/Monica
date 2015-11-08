//
//  NMT_ParamFactory.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-22.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_cloudservices/NMT_IParam.h>
#import <nmt_audio/NMT_AudioSource.h>

NS_ROOT_CLASS
@interface NMT_ParamFactory

/**
 * @param key    The name of the AudioParam specified by the Command on Nuance Mobile
 *               Application Server. This value cannot be nulsl or empty.
 * @param audioSource The audio source associated with the audio parameter.
 *                    It provides the input audio data; cloud services
 *                    will pick the audio and stream it to the speech
 *                    server for recognition. Possible audio sources are
 *                    recorder, Speex encoder, or file source. This value cannot be null.
 */
+(id<NMT_IParam>) createAudioParamWithKey:(NSString *)key audio:(NMT_AudioSource*)audioSource;

/**
 * Creates an instance of TTS Parameter for an NMAS command.
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * @param key The key for this parameter.
 * @param dict The dictionary containing the data for this parameter (e.g.,
 * the text to TTS).
 * @param audioType The type of audio.
 */
+(id<NMT_IParam>) createTtsParamWithKey:(NSString *)key dict:(NSDictionary *)dict audioType:(const NMT_AudioType *)audioType;

/**
 * Creates an instance of String Parameter for an NMAS command.
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * @param key   The name of the String parameter.
 * @param value The value of the String parameter.
 */

+(id<NMT_IDataParam>) createStringParamWithKey:(NSString *)key value:(NSString *)value;

/**
 * Creates an instance of Bytes Parameter for an NMAS command.
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * @param key  The name of this Bytes parameter. (Cannot be null or empty.)
 * @param data The associated binary data, the data will be deep copied. (Cannot be null.)
 */
+(id<NMT_IParam>) createsBytesParamWithKey:(NSString *)key data:(NSData *)data;

/**
 * Creates a parameter to send PDX Dictionary data to the Nuance Mobile
 * Application Server network command. The PDX Dictionary contains one or
 * more key-value pairs.
 *
 * @param key   The name of the Dictionary Parameter expected by the command.
 * @param dict  The dictionary contains one or more key-value pairs.
 */
+(id<NMT_IDataParam>) createDictionaryParamWithKey:(NSString *)key dict:(NSDictionary *)dict;

/**
 * Creates an instance of Sequence Parameter for an NMAS command.
 * This parameter represents a sequence of PDX data entries that can be streamed
 * to the server as they are added to the transaction. Each chunk will be streamed
 * out under the same param.
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * @param key The name of the Sequence Parameter.
 * @param seq The actual sequence data object.
 */
+(id<NMT_IParam>) createSequenceParamWithKey:(NSString *)key seq:(NSArray *)seq;


/**
 * Creates an instance of Sequence Start Parameter for an NMAS command.
 * It indicates the start of a series of data chunks that are going to be sent.
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * @param key  name of the Sequence Start Parameter specified by the
 *             Command on Nuance Mobile Application Server.
 * @param dict a Data.Dictionary containing all the dictionary contents.
 */

+(id<NMT_IParam>) createSequenceStartParamWithKey:(NSString *)key dict:(NSDictionary *)dict;

/**
 * Creates an instance of Sequence Chunk Parameter for an NMAS command.
 * This is used to send large amounts of data in dictionary format (like a contact list
 * in smaller pieces (chunks).
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * @param key  The name of the Sequence Chunk Parameter specified by the
 *             Command on Nuance Mobile Application Server.
 * @param dict Dictionary that contains all the dictionary contents.
 */
+(id<NMT_IParam>) createSequenceChunkParamWithKey:(NSString *)key dict:(NSDictionary *)dict;

/**
 * Creates an instance of Sequence End Parameter for an NMAS command.
 * It indicates the end of a series of data chunks that were sent.
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * @param key  The name of the Sequence End Parameter specified by the
 *             Command on Nuance Mobile Application Server.
 * @param dict Dictionary containing all the dictionary contents.
 */
+(id<NMT_IParam>) createSequenceEndParamWithKey:(NSString *)key dict:(NSDictionary *)dict;

/**
 * Creates an instance of Choice Parameter for an NMAS command.
 * Parameter that holds the name and value of a possible choice according
 * to the results returned by a command on the NMAS.
 * Once the instance is no longer needed, it must be released via IParam::release.
 *
 * \param sKey Parameter key, cannot be NULL or empty.
 * \param sValue Value that represents the choice specified by the client (cannot be NULL).
 * \return Instance of Choice Param, or NULL on failure.
 */
+(id<NMT_IParam>) createChoiceParamWithKey:(NSString *)key value:(NSString *)value;

@end
