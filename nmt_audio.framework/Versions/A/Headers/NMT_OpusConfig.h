//
//  NMT_OpusConfig.h
//  nmt
//
//  Created by Eric Chartier 2014
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Initialize the Opus encoder with specific values
 */
@interface NMT_OpusConfig : NSObject

@property (nonatomic) BOOL      stopOnEndOfSpeech;
@property (nonatomic) NSInteger vadLongUtterance;
@property (nonatomic) NSInteger vadHistoryLength;
@property (nonatomic) NSInteger vadBeginLength;
@property (nonatomic) NSInteger vadBeginThreshold;
@property (nonatomic) NSInteger vadBeginDelay;
@property (nonatomic) NSInteger vadEndLength;
@property (nonatomic) NSInteger vadEndThreshold;
@property (nonatomic) NSInteger vadInterSpeechLength;

@end
