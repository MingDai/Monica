//
//  NMT_DataUploaderConfig.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-25.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_core/JSONCompliant.h>


/**
 * Represents a configuration for {@link NMT_ICloudDataUploader}. It allows the application
 * to override the NVC Upload command configuration.
 */

@interface NMT_DataUploaderConfig : NSObject <NMT_JSONCompliant>

-(id) initWithCommand:(NSString *)command settings:(NSDictionary *)settings timeout:(int)timeout
         chunkSize:(int)chunkSize totalSize:(int)totalSize;

/**
 * Command name.
 * Default is "NVC_DATA_UPLOAD_CMD".
 */
@property (readonly, retain) NSString * commandName;

/**
 * Command settings, can be NULL.
 * Default is NULL.
 */
@property (readonly, retain) NSDictionary * commandSettings;

/**
 * Timeout in milliseconds before the command should complete.
 * Default is 40000.
 */
@property (readonly) int commandTimeout;

/**
 * Number of items per data block.
 * Default is 50.
 */
@property (readonly) int commandChunkSize;


/**
 * Total number of items per NVC command.
 * Default is 200.
 */
@property (readonly) int commandTotalSize;

@end
