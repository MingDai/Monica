//
//  NMT_ICloudRecognitionResult.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-09.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_core/JSONCompliant.h>

/**
 * A cloud recognition result object.
 */
@protocol NMT_ICloudRecognitionResult <NMT_JSONCompliant>

/**
 * @return The cloud recognition result type. (Cannot be null.)
 */
-(NSString *) type;

/**
 * @return The complete result in dictionary format. (Cannot be null.)
 */
-(NSDictionary *) dictionary;


/**
 * Indicates whether this is the final result, or more results are expected.
 * @return True, if there are no more results.
 */
-(BOOL) isFinal;

@end
