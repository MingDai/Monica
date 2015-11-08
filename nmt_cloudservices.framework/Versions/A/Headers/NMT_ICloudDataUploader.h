//
//  CloudDataUploader.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-25.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_cloudservices/NMT_ICloudServices.h>
#import <nmt_cloudservices/NMT_DataUploaderParams.h>
#import <nmt_cloudservices/NMT_ITransactionResult.h>
#import <nmt_cloudservices/NMT_ITransactionError.h>
#import <nmt_core/grammar/NMT_IWordList.h>

@protocol NMT_IDataUploadDelegate;
@protocol NMT_IDataDeleteDelegate;
@protocol NMT_IWordList;

/**
 * A CloudDataUploader uploads the contents of a {@link NMT_WordList} through a
 * {@link NMT_CloudServices}, for use in a later recognition.
 */
@protocol NMT_ICloudDataUploader <NSObject>


/**
 * Upload a word list to the server. This method will decide whether to
 * upload the full list, or to upload only recent modifications.
 * @param params Structure that contains parameters to apply for this upload session.
 * @return YES if the asynchronous request could be made, NO otherwise.
 */
-(BOOL) uploadData:(NMT_DataUploaderParams *)params;

/**
 * Deletes everything from the server.
 * @param listener Cannot be nil.
 * @return YES if the asynchronous request could be made, NO otherwise.
 */
-(BOOL) deleteAll:(id<NMT_IDataDeleteDelegate>)listener;

/**
 * Cancels the current upload or delete transaction, if any.
 */
-(void) cancel;

@end


/**
 * Listens for the result of the upload transaction.
 */
@protocol NMT_IDataUploadDelegate <NSObject>

/**
 * The upload succeeded.
 * @param uploader
 * @param result May be null if no upload occurred due to 0 effective
 * changes.
 * @param wordList The word list that was uploaded.
 * @param nothingToUpload True if there was nothing to upload. False otherwise.
 */
-(void) onCloudUploadSuccess:(id<NMT_ICloudDataUploader>)uploader
           result:(id<NMT_ITransactionResult>)result
        grammarId:(NSString *)grammarId
      grammarType:(NSString *)grammarType
         wordList:(id<NMT_IWordList>)wordList
         nothingToUpload:(BOOL)nothingToUpload;

/**
 * There was an error when uploading
 * @param uploader
 * @param error
 * @param wordList The word list that was uploaded
 */
-(void) onCloudUploadError:(id<NMT_ICloudDataUploader>)uploader
                     error:(id<NMT_ITransactionError>)error
                  wordList:(id<NMT_IWordList>)wordList;

@end


/**
 * Listens for the result of the delete transaction
 */
@protocol NMT_IDataDeleteDelegate <NSObject>
/**
 * The deletion succeeded
 * @param uploader
 * @param result May be null if no upload occurred due to 0 effective
 * changes.
 */
-(void) onCloudDeleteSuccess:(id<NMT_ICloudDataUploader>)uploader result:(id<NMT_ITransactionResult>)result;

/**
 * There was an error when deleting
 * @param uploader
 * @param error
 */
-(void) onCloudDeleteError:(id<NMT_ICloudDataUploader>)uploader  error:(id<NMT_ITransactionError>)error;

@end
