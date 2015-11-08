//
//  RecogSpec.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-24.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_cloudservices/NMT_IParam.h>

/**
 * A specification for a cloud recognition. Includes the command name,
 * the command settings, the audio parameter name and the spec for the
 * result structure.
 */
@interface NMT_RecogSpec : NSObject

/**
 * Creates a recog spec with a default command timeout of 10 seconds.
 * @param command    The recognition command name, which has been deployed on the
 *                   Nuance Mobile Application Server. (Cannot be null.)
 * @param settings   The command settings, sent in the BCP begin. Can be null.
 * @param audioParam The audio param name. (Cannot be null.)
 */
-(id) initWithCommand:(NSString *)command settings:(NSDictionary*)settings audioParam:(NSString *)audioParam;

/**
 * Creates a recog spec.
 * @param command    The recognition command name, which has been deployed on the
 *                   Nuance Mobile Application Server. (Cannot be null.)
 * @param settings   The command settings, sent in the BCP begin. Can be null.
 * @param audioParam The audio param name. (Cannot be null.)
 * @param timeoutMs  The command timeout, in milliseconds.
 */
-(id) initWithCommand:(NSString *)command settings:(NSDictionary *)settings audioParam:(NSString *)audioParam timeoutMs:(int)timeoutMs;


/**
 * Adds a parameter to be sent during the recognition.
 * @param param Arbitrary parameters associated with the recognition specified by
 *              the current {@link NMT_RecogSpec}.
 */
-(void) addParam:(id<NMT_IDataParam>)param;

@property (readonly, retain) NSString  * command;
@property (readonly, retain) NSString  * audioParam;
@property (readonly, retain) NSDictionary *settings;
@property (readonly, retain) NSArray * params;
@property (readonly) int timeout;

@end
