//
//  CloudServices.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-22.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_cloudservices/NMT_ICloudServices.h>
#import <nmt_cloudservices/NMT_TransactionConfig.h>
#import <nmt_cloudservices/NMT_ICloudRecognizer.h>
#import <nmt_cloudservices/NMT_ICloudVocalizer.h>
#import <nmt_cloudservices/NMT_ICloudDataUploader.h>
#import <nmt_cloudservices/NMT_DataUploaderConfig.h>

NS_ROOT_CLASS
@interface NMT_CloudServicesFactory

/**
 * Creates a CloudServices instance with parameter values from CloudConfig object
 * and application context object.
 *
 * @param config          The cloud configuration.
 * @param appContext      The application context object.
 */
+(id<NMT_ICloudServices>) createCloudServicesWithConfig:(NMT_CloudConfig *)config delegate:(id<NMT_ICloudServicesDelegate>)delegate context:(id)context;

/**
 * \brief Creates a transaction from the specified configuration.
 *
 * \param rConfig Transaction configuration to use.
 * \return ITransaction instance that must be released via its release
 *         method once no longer needed by the application.
 */
+(id<NMT_ITransaction>) createTransaction:(NMT_TransactionConfig *) config;

/**
 * Creates a SSLConfig object.
 *
 * @param selfSigned  Use self-signed certificate or not
 * @param certSummary The certificate summary can be null. However, the value
 *                    cannot be empty.
 * @param certData    Certificate data can be null. However, the value cannot
 *                    be empty.
 */
+(id<NMT_ICloudServicesConfigSection>) createSslConfigSection:(BOOL)isSelfSigned summary:(NSString *)certSummary cert:(NSData *)certData;

/**
 * Makes an SSLConfig object.
 *
 * @param disableCalllog Enable or disable call log feature.
 *                       Disable call log by setting disableCalllog = true.
 *                       Enable call log by setting disableCalllog = false.
 */
+(id<NMT_ICloudServicesConfigSection>) createCalllogConfigSection:(BOOL)disableCalllog;

/**
 * Makes an SSLConfig object.
 *
 * @param disableCalllog Enable or disable call log feature.
 *                       Disable call log by setting disableCalllog = true.
 *                       Enable call log by setting disableCalllog = false.
 *
 * @param chunkSize     size of call log buffer chunk. Chunk size will decide frequency of receiving
 *                      call log buffer. Minimums size if 20K.
 *
 * @param retentionDays    Specifies the suggested number of days for preserving the call log data in the cloud. The effective data retention
 *                       period is subject to a number of conditions on the server side and may be automatically adjusted to a higher or
 *                       lower value than the specified one. The value of -1 indicates no specific value for the data retention and the server default value will be used. Other
 *                       negative values or 0 is not allowed. The default value is -1.
 *
 * @param rootId    Input RootId.
 *                  If rootId is null, a new root ID is generated.
 *                  If rootId is not null, the value of rootId is used as the root session event ID.
 *
 */
+(id<NMT_ICloudServicesConfigSection>) createCalllogConfigSection:(BOOL)disableCalllog chunkSize:(NSInteger)chunkSize retentionDays:(NSInteger)retentionDays rootId:(NSString *)rootId;


/**
 * \brief Creates an instance of ICloudRecognizer. This instance performs network
 * recognitions using Cloud Services transactions.
 *
 * @param cloudServices The cloud services instance to use.
 */
+(id<NMT_ICloudRecognizer>) createCloudRecognizerWithCloudServices:(id<NMT_ICloudServices>)cloudServices;


/**
 * \brief Creates an instance of ICloudVocalizer. This instance performs network
 * text-to-speech using Cloud Services transactions.
 * \param pCloudServices Cloud Services instance to be used internally for the TTS. Cannot be NULL.
 * \return ICloudVocalizer instance.
 */
+(id<NMT_ICloudVocalizer>)createCloudVocalizerWithCloudServices:(id<NMT_ICloudServices>)cloudServices;



/**
 * \brief Creates an instance of ICloudDataUploader. This instance can be used to
 *        upload or delete data on the server. Once no longer needed, it's important
 *        to release the instance. This must be done before releasing the parent ICloudServices.
 * \param pCloudServices Cloud Services instance to be used internally for the data upload. Cannot be NULL.
 * \param rConfig Configuration to use for the commands that will originate from this
 *        ICloudDataUploader instance.
 * \return ICloudDataUploader instance.
 */
+(id<NMT_ICloudDataUploader>) createCloudDataUploaderWithCloudServices:(id<NMT_ICloudServices>)cloudServices config:(NMT_DataUploaderConfig *)config;

@end

