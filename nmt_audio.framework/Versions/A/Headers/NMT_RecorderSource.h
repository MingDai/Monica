//
//  RecorderSource.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-13.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_SingleSinkSource.h>

/**
 * Creates recorder source object.
 */
@protocol NMT_RecorderSourceDelegate;

@interface NMT_RecorderSource : NMT_SingleSinkSource

@property (readonly, nonatomic, weak) id<NMT_RecorderSourceDelegate> delegate;

/**
 * Starts recording audio. The audio is buffered when no audio sink is connected.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 * @param delegate Delegate to send progress notifications to.
 * @return YES if the recording session started successfully. NO otherwise.
 */
- (BOOL)startRecording:(id<NMT_RecorderSourceDelegate>)delegate;

/**
 * Stops recording. There may still be delayed audio chunks after calling
 * this function.
 * @remarks This method must be overridden by the subclass or an exception will be thrown.
 */
- (void)stopRecording;

@end

@protocol NMT_RecorderSourceDelegate <NSObject>

/**
 * The recorder has started recording.
 * @param recorder
 */
- (void)onRecorderStarted:(NMT_RecorderSource*)recorder;

/**
 * The recorder has stopped recording.
 * @param recorder
 */
- (void)onRecorderStopped:(NMT_RecorderSource*)recorder;

/**
 * The recorder has encountered an error.
 * @param recorder
 * @param code Implementation specific error code.
 * @param message Error message.
 */
- (void)onRecorderError:(NMT_RecorderSource*)recorder code:(NSInteger)code message:(NSString*)message;

@end
