//
//  CloudVocalizer.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-25.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_cloudservices/NMT_ICloudServices.h>
#import <nmt_cloudservices/NMT_TtsSpec.h>
#import <nmt_cloudservices/NMT_ITransactionError.h>
#import <nmt_audio/NMT_AudioSource.h>

@protocol NMT_ICloudVocalizerDelegate;

/**
 * A cloud vocalizer performs a network TTS using a cloud services transaction.
 * A single instance may be used for multiple TTS requests, but only one TTS
 * request may be active at a time.
 */
@protocol NMT_ICloudVocalizer <NSObject>


/**
 * Generates TTS. If TTS generation is already in process, invoking this
 * module cancels the active TTS request.
 * @param ttsSpec Describes the TTS to generate. Cannot be nil.
 * @param delegate Listener for the success or failure of the transaction.
 * @return The audio source that provides the generated TTS audio. Returns nil on error.
 */
-(NMT_AudioSource*)generateTts:(NMT_TtsSpec *)ttsSpec delegate:(id<NMT_ICloudVocalizerDelegate>)delegate;

/**
 * Cancels the current TTS request, if there is one.
 */
-(void) cancel;
                   
@end


/**
 * Listens for the result of the TTS transaction. The result of this
 * transaction does not eflect the state of playing audio.
 */
@protocol NMT_ICloudVocalizerDelegate <NSObject>

/**
 * The transaction completed successfully.
 */
-(void) onCloudVocalizerSuccess;

/**
 * There was an error during the transaction.
 * @param error The error.
 */
-(void) onCloudVocalizerError:(id<NMT_ITransactionError>)error;

@end
