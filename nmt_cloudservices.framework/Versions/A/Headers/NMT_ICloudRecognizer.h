//
//  CloudRecognizer.h
//  Nuance Mobile Toolkit
//
//  Created by Nuance User on 10/24/12.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_cloudservices/NMT_ICloudServices.h>
#import <nmt_cloudservices/NMT_ICloudRecognitionResult.h>
#import <nmt_cloudservices/NMT_ICloudRecognitionError.h>
#import <nmt_cloudservices/NMT_RecogSpec.h>
#import <nmt_audio/NMT_AudioSource.h>

/**
 * Listener interface for cloud recognition results.
 */
@protocol NMT_ICloudRecognizerDelegate <NSObject>

/**
 * A result was received.
 * @param result
 */
-(void) onCloudRecognizerResult:(id<NMT_ICloudRecognitionResult>)result;

/**
 * An error occurred.
 * @param error
 */
-(void) onCloudRecognizerError:(id<NMT_ICloudRecognitionError>)error;

@end


/**
 * Creates a CloudRecognizer object.
 */
@protocol NMT_ICloudRecognizer <NSObject>

/**
 * Starts a recognition.
 * @param recogSpec The specification for the recognition. Cannot be nil.
 * @param audioSource The audio source. The recognizer will connect to the
 * audio source until {@link #processResult} or {@link #cancel} is called. Cannot be nil.
 * @param delegate The result listener. Cannot be nil.
 * @return YES if the recognition could be successfully started. NO otherwise.
 */
-(BOOL) startRecognition:(NMT_RecogSpec *)recogSpec audioSource:(NMT_AudioSource*)audioSource delegate:(id<NMT_ICloudRecognizerDelegate>)delegate;

/**
 * Ends the recognition command, and waits for a result from the server. No
 * more audio or parameters can be processed after calling this method.
 */
-(void) processResult;

/**
 * Sets the results cadence in milliseconds.
 * Only relevant when expecting multiple results.
 */
-(void) setCadence:(unsigned int)cadence;

/**
 * Cancels the recognition. This is safe to call even if there is no active
 * recognition.
 */
-(void) cancel;

/**
 * Sends an extra parameter. You must call this method after calling {@link #startRecognition},
 * but before calling {@link #processResult}.
 * @param param The parameter to add to the recognition command.
 */
-(void) sendParam:(id<NMT_IParam>)param;


@end


