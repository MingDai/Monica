//
//  SKAudioPlayer.h
//  SpeechKit
//
// Copyright 2010, Nuance Communications Inc. All rights reserved.
//
// Nuance Communications, Inc. provides this document without representation 
// or warranty of any kind. The information in this document is subject to 
// change without notice and does not represent a commitment by Nuance 
// Communications, Inc. The software and/or databases described in this 
// document are furnished under a license agreement and may be used or 
// copied only in accordance with the terms of such license agreement.  
// Without limiting the rights under copyright reserved herein, and except 
// as permitted by such license agreement, no part of this document may be 
// reproduced or transmitted in any form or by any means, including, without 
// limitation, electronic, mechanical, photocopying, recording, or otherwise, 
// or transferred to information storage and retrieval systems, without the 
// prior written permission of Nuance Communications, Inc.
// 
// Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are 
// trademarks or registered trademarks of Nuance Communications, Inc. or its 
// affiliates in the United States and/or other countries. All other 
// trademarks referenced herein are the property of their respective owners.
//

#import <Foundation/Foundation.h>


@protocol SKAudio;
@protocol SKAudioPlayerDelegate;


/*!
 @class SKAudioPlayer
 @abstract The SKAudioPlayer class manages and plays sequences of audio and
 synthesized text.
 */
@interface SKAudioPlayer : NSObject

@property (nonatomic, readwrite, weak) id <SKAudioPlayerDelegate> delegate;

/*!
 @abstract Start playing the currently enqueued audio.
 */
- (void)play;

/*!
 @abstract Empty the audio queue and immediately start playing the provided
 audio.
 */
- (void)playAudio:(id <SKAudio>)audio;

/*!
 @abstract Pause the currently playing audio.
 */
- (void)pause;

/*!
 @abstract Stop the currently playing audio and empty the audio queue.
 */
- (void)stop;

/*!
 @abstract Append the audio to the audio queue.
 
 @discussion Audio in the queue will continue to play sequentially as long as
 the queue contains audio items.
 */
- (void)enqueue:(id <SKAudio>)audio;

/*!
 @abstract Remove the audio by reference from the audio queue.
 */
- (void)dequeue:(id <SKAudio>)audio;

@end


/*!
 @abstract The SKAudioPlayerDelegate provides methods for managing the lifecycle
 of an audio player and its associated audio content.
 */
@protocol SKAudioPlayerDelegate <NSObject>
@optional

/*!
 @abstract Called when the player will begin playing the designated audio item.
 */
- (void)audioPlayer:(SKAudioPlayer *)player willBeginPlaying:(id <SKAudio>)audio;

/*!
 @abstract Called when the player finishes playing the designated audio
 instance.
 */
- (void)audioPlayer:(SKAudioPlayer *)player didFinishPlaying:(id <SKAudio>)audio;

@end
