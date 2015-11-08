//
//  CloudConfig.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-22.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_AudioType.h>


/**
 * The CloudConfig object sets parameter values for objects used in cloud-based processing.
 */
@interface NMT_CloudConfig : NSObject

/**
 * Create a {@link NMT_CloudConfig} object with the given parameters.
 *
 * @param appName         Application name.
 * @param host            NMSP Gateway IP address or host name.
 * @param port            NMSP Gateway port.
 * @param appId           The application ID provided by Nuance Communications, Inc.
 * @param appKey          The application private key provided by Nuance Communications, Inc.
 * @param recorderCodec   Recorder codec (input codec for recognition).
 * @param playerCodec     Player codec (output codec for TTS).
 * @param configs         Array of configurations for cloud services, all elements must be derived from NMTConfig protocol.
 */
-(id) initWithAppName:(NSString *)appName host:(NSString *)host port:(int)port appId:(NSString *)appId appKey:(NSData *)appKey recorderCodec:(const NMT_AudioType *)recorderCodec playerCodec:(const NMT_AudioType *)playerCodec configs:(NSArray *)configs;

@property (readonly, retain) NSString * appName;
@property (readonly, nonatomic) NSString* host;
@property (readonly, nonatomic) int port;
@property (readonly, retain) NSString * appId;
@property (readonly, retain) NSData * appKey;
@property (readonly, retain) const NMT_AudioType * recorderCodec;
@property (readonly, retain) const NMT_AudioType * playerCodec;
@property (readonly, retain) NSArray * configs;
@end

