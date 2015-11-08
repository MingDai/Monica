//
//  NMT_DataUploaderConfig.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-25.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_core/JSONCompliant.h>
#import <nmt_core/grammar/NMT_IWordList.h>

/**
 * Represents a configuration for {@link NMT_ICloudDataUploader}. It allows the application
 * to override the NVC Upload command configuration.
 */
@protocol NMT_IDataUploadDelegate;

@interface NMT_DataUploaderParams : NSObject <NMT_JSONCompliant>

-(id) initWithGrammarId:(NSString *)grammarId type:(NSString *)type
               category:(NSString *)category
               wordList:(id<NMT_IWordList>)wordList
        forceFullUpload:(BOOL)forceFullUpload
               delegate:(id<NMT_IDataUploadDelegate>)delegate;

/**
 * Grammar ID to attach to the corresponding pWordList. Cannot be nil.
 */
@property (readonly, retain) NSString * grammarId;

/**
 * Type of content, e.g. "contacts", "custom_words" or "structured_content".
 * Cannot be nil.
 */
@property (readonly, retain) NSString * type;

/**
 * Category of the content, nil if the type is not "structured_content".
 */
@property (readonly, retain) NSString * category;

/**
 * Word list to upload. Cannot be nil.
 */
@property (readonly, retain) id<NMT_IWordList> wordList;

/**
 * Indicates whether to force the upload by clearing and uploading everything.
 */
@property (readonly, nonatomic) BOOL forceFullUpload;

/**
 * Listener to call on events. Cannot be nil.
 */
@property (readonly, weak) id<NMT_IDataUploadDelegate> delegate;

@end
