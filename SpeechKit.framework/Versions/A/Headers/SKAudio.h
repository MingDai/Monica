//
//  SKAudio.h
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


@class SKAudioPlayer;
@protocol SKAudioDelegate;

/*!
 @abstract Generic audio buffer protocol.
 
 @discussion Audio
 */
@protocol SKAudio <NSObject>

/*!
 @abstract Allows setting the delegate after initialization.
 
 @discussion This property is used in the case where the SKAudio instance is
 owned by SpeechKit (e.g. Text-to-Speech transaction) and provided to the user
 via a delegate. The user shall then set the delegate before invoking saveToURL
 to receive notification upon completion.
 */
@property (nonatomic, readwrite, weak) id<SKAudioDelegate> delegate;

/*!
 @abstract Save the audio to a file on the filesystem.
 */
- (BOOL)saveToURL:(NSURL *)url;

@end


/*!
 @abstract The SKSynthesizedAudio class represents TTS audio and word timing 
 data.
 
 @discussion This class is not initially constructed or created by a user.  
 Instead, synthesized audio is returned from a transaction as a response from a 
 TTS request or other special service request.  The received audio instance may 
 be played immediately with an SKAudioPlayer, saved in memory or stored to disk
 using saveToURL: for future playback.  The synthesized audio may be loaded 
 later with initWithURL: and played with the SKAudioPlayer.
 */
@interface SKSynthesizedAudio : NSObject <SKAudio>
@end

/*!
 @abstract The SKAudioFile class represents a traditional audio file without
 associated word timing information.
 
 @discussion This class is usually used to load user provided earcons.  The 
 transaction delegate may however provide an SKAudioFile instance instead of an
 SKSynthesizedAudio instance in transaction:didReceiveAudio: for non-traditional 
 TTS responses or service specific responses.
 */
@interface SKAudioFile : NSObject <SKAudio>

/*!
 @abstract Initializes an SKAudio instance with an URL.
 */
- (instancetype)initWithURL:(NSURL *)url delegate:(id<SKAudioDelegate>)delegate;

/*!
 @abstract Load the audio file from the filesystem specified by the URL at initialization.
 
 @discussion Asynchronously loads the file from the filesystem into an internal
 buffer ready for consumption. Once the process is complete, the audio:didFinishLoadingFromURL:
 or audio:didFailWithError: method of the delegate is called.
 */
- (BOOL)load;

@end


/*!
 @abstract The SKAudioDelegate provides methods for managing the lifecycle of 
 audio instances.
 */
@protocol SKAudioDelegate <NSObject>
@optional

/*!
 @abstract Called when the SKAudio instance has finished loading the content from URL.
 */
- (void)audio:(id <SKAudio>)audio didFinishLoadingFromURL:(NSURL*)url;

/*!
 @abstract Called when the SKAudio instance has finished saving the content to URL.
 */
- (void)audio:(id <SKAudio>)audio didFinishSavingToURL:(NSURL*)url;

/*!
 @abstract Called when a fatal error has occurred.
 */
- (void)audio:(id <SKAudio>)audio didFailWithError:(NSError*)error;

@end
