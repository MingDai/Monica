//
//  NMT_SpeechDetectionDelegate.h
//  nmt
//
//  Created by Hao Zhou on 2014-02-05.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Creates a SpeechDetectionDelegate object.
 */
@protocol NMT_SpeechDetectionDelegate <NSObject>

/**
 * Called when the start of speech is detected.
 */
-(void) onStartOfSpeech;

/**
 * Called when the end of speech is detected.
 */
-(void) onEndOfSpeech;

@end
