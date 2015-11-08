//
//  AudioQueuePlayerSink.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-21.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioQueue.h>
#import <nmt_audio/NMT_PlayerSink.h>

/**
 * Implementation of {@link NMT_PlayerSink} that plays to the device speaker.
 */
@interface NMT_AudioQueuePlayerSink : NMT_PlayerSink

/**
 * Creates a player that uses an NMT worker thread.
 *
 * @param audioType The audio type to play. Cannot be null.
 */


@property (nonatomic) AudioQueueRef audioQueue;

@end
