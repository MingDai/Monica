//
//  SKSession.h
//  SpeechKit
//
// Copyright 2010, Nuance Communications Inc. All rights reserved.
//
// Nuance Communications, Inc. provides this document without representation 
// or warranty of any kind. The information in this document is subject to 
// change without notice and does not represent a commitment by Nuance 
// Communications, Inc. The software and/or databases described in this 
// document are furnished under a license agreement and may be used or 
// copied only in accordance with the terms of such license agreement.  
// Without limiting the rights under copyright reserved herein, and except 
// as permitted by such license agreement, no part of this document may be 
// reproduced or transmitted in any form or by any means, including, without 
// limitation, electronic, mechanical, photocopying, recording, or otherwise, 
// or transferred to information storage and retrieval systems, without the 
// prior written permission of Nuance Communications, Inc.
// 
// Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are 
// trademarks or registered trademarks of Nuance Communications, Inc. or its 
// affiliates in the United States and/or other countries. All other 
// trademarks referenced herein are the property of their respective owners.
//

#import <Foundation/Foundation.h>
#import "SKTransaction.h"


@class SKAudioPlayer;
@class SKGrammarDefinition;
@class SKInterpretation;
@class SKRecognition;
@class SKSynchronizedList;
@class SKSynchronizationCommandSet;
@class SKTransaction;
@protocol SKAudio;
@protocol SKAudioPlayerDelegate;
@protocol SKTransactionDelegate;
@protocol SKSessionDelegate;

@interface SKSession : NSObject

/*!
 @abstract Audio Player.
 
 @discussion This is an instance of Audio Player that can be used to queue
 SKAudio objects. The user is responsible to start and stop the Audio Player
 whenever requested.
 */
@property (nonatomic, readonly) SKAudioPlayer *audioPlayer;

/*!
 @abstract Initialize the session.
 
 @discussion This method configures the session and may establish a connection 
 with the speech server.
 
 @param url Speech service endpoint (nmsps://ApplicationID@service.nuance.com:443)
 WARNING: We strongly encourage using SSL to make sure all transactions are
 made on a secure socket. (nmsps)
 @param appToken The application secret token
 @result SKSession instance, which must be kept alive until at least no more interactions
 with the speech server are expected.
 */
- (instancetype)initWithURL:(NSURL *)url appToken:(NSData*)token;

/*!
 @abstract Initialize the session.
 
 @discussion This method configures the session and may establish a connection
 with the speech server.
 
 @param url Speech service endpoint (nmsps://ApplicationID@service.nuance.com:443)
 WARNING: We strongly encourage using SSL to make sure all transactions are
 made on a secure socket. (nmsps)
 @param appToken The application secret token
 @param sslSummary The Common Name used inside the certificate subject field (CN=)
 This parameter is important to specify in order to prevent man-in-the-middle (MITM)
 attack styles where the middle man has a valid certificate but different than the expected target.
 The value of the string is a partial or fully-qualified domain name (FQDN) and may include a star (asterisk) for wildcard
 certificates - exactly as specified in the CN field of the server X.509. (example: *.nuancemobility.net)
 @param sslCertData The actual X509 certificate encoded in Base64
 
 If this value is specified:
 After standard certificate validity checks are complete, certificates in the chain of trust are byte-compared in sequence against this certificate
 from the target server host (the tip of the chain of trust) back to the root CA, until the first match is found.
 Any match means that the connection is allowed.  If none match, the connection is disallowed.
 
 Therefore, this parameter can be used to either provide a strong target host check, or to "pin" the chain of trust to a specific root
 or intermediate CA.  If the encoded certificate is a CA rather than the target server CN, it is important to also specify the sslSummary.
 Otherwise, the sslSummary is redundant and not strictly necessary.
 
 Since the encoded certificates contain validity dates and other items, certificate rotation 
 needs should be considered in the client design when using this parameter.
 @param delegate Session delegate to send event notifications to.
 @result SKSession instance, which must be kept alive until at least no more interactions
 with the speech server are expected.
 */
- (instancetype)initWithURL:(NSURL *)url
                   appToken:(NSData*)token
                 sslSummary:(NSString*)sslSummary
                sslCertData:(NSData*)sslCertData
                   delegate:(id<SKSessionDelegate>)delegate;

/*!
 @abstract Terminate the session.
 
 @discussion This method terminates the session, which includes disconnecting
 from the speech server and cancelling the current transaction if any. Once the sessionDidTerminate message is signaled to the provided
 SKSessionDelegate, it is safe to deallocate this SKSession instance.
 */
- (void)terminate;

/*!
 @abstract Perform a speech recognition.
 
 @param type Speech recognition model.
 @param detection End of speech detection.
 @param language Spoken language.
 @param delegate Transaction delegate.
 */
- (id<SKTransaction>)recognizeWithType:(NSString *)type
                           detection:(SKTransactionEndOfSpeechDetection)detection
                            language:(NSString *)language
                            delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform a speech recognition.
 
 @param type Speech recognition model
 @param detection End of speech detection
 @param language Spoken language
 @param options Options dictionary
 @param delegate Transaction delegate
 */
- (id<SKTransaction>)recognizeWithType:(NSString *)type
                           detection:(SKTransactionEndOfSpeechDetection)detection
                            language:(NSString *)language
                             options:(NSDictionary *)options
                            delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform a speech recognition.
 
 @param type Speech recognition model
 @param detection End of speech detection
 @param language Spoken language
 @param grammars List of grammar definitions
 @param options Options dictionary
 @param audioUrl Recognize from the audio file at URL (raw PCM: 16-bit 16 kHz).
 If nil audio will be recorded from the microphone instead.
 @param delegate Transaction delegate
 */
- (id<SKTransaction>)recognizeWithType:(NSString *)type
                           detection:(SKTransactionEndOfSpeechDetection)detection
                            language:(NSString *)language
                            grammars:(NSArray *)grammars
                             options:(NSDictionary *)options
                            audioUrl:(NSURL *)url
                            delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform a custom speech recognition.
 
 @discussion This method recognizes speech using a custom service which may 
 perform many service specific tasks.  The result is not limited to speech 
 recognition and may return application data, audio or any of the possible 
 transaction results.
 
 @param service Service ID.
 @param detection End of speech detection.
 @param language Spoken language.
 @param data Application specific data dictionary.
 @param delegate Transaction delegate.
 */
- (id<SKTransaction>)recognizeWithService:(NSString *)service
                              detection:(SKTransactionEndOfSpeechDetection)detection
                               language:(NSString *)language
                                   data:(NSDictionary *)data
                               delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform a custom speech recognition.
 
 @param service Service ID.
 @param detection End of speech detection.
 @param language Spoken language.
 @param data Application specific data dictionary.
 @param grammars List of grammar definitions
 @param options Options dictionary.
 @param audioUrl Recognize from the audio file at URL (raw PCM: 16-bit 16 kHz).
 If nil audio will be recorded from the microphone instead.
 @param delegate Transaction delegate.
 */
- (id<SKTransaction>)recognizeWithService:(NSString *)service
                                detection:(SKTransactionEndOfSpeechDetection)detection
                                 language:(NSString *)language
                                     data:(NSDictionary *)data
                                 grammars:(NSArray*)grammars
                                  options:(NSDictionary *)options
                                 audioUrl:(NSURL *)url
                                 delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Send a message to a custom service.
 
 @discussion This method is the same as the recognizeWithService:... methods 
 except that it does not record and stream audio to the service.  Instead this 
 method may be used for non-speech queries such as configuration or text 
 recognition.
 
 @param type Speech recognition model
 @param detection End of speech detection
 @param language Spoken language
 @param delegate Transaction delegate
 */
- (id<SKTransaction>)transactionWithService:(NSString *)service
                                 language:(NSString *)language
                                     data:(NSDictionary *)data
                                 delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Send a message to a custom service.
 
 @param type Speech recognition model
 @param detection End of speech detection
 @param language Spoken language
 @param options Options dictionary
 @param delegate Transaction delegate
 */
- (id<SKTransaction>)transactionWithService:(NSString *)service
                                 language:(NSString *)language
                                     data:(NSDictionary *)data
                                   grammars:(NSArray*)grammars
                                  options:(NSDictionary *)options
                                 delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Peform text to speech from a string.
 
 @discussion For simplicity, this method will automatically receive the SKAudio 
 data, enqueue it on the session SKAudioPlayer, and play the audio.  However, 
 this will only happen if the delegate does not implement the 
 transaction:didReceiveAudio: method.  You should only implement the 
 transaction:didReceiveAudio: method if you need to retrieve the SKAudio data in 
 the case that you may play the audio multiple times or if you want to cache it 
 for later use.  If you do implement transaction:didReceiveAudio: and you want 
 to immediately play the audio, you must enqueue it with the SKAudioPlayer and 
 ensure the audio player is playing.
 
 @param string The text to synthesize.
 @param voice The voice to use for speech synthesis.
 @param delegate Transaction delegate.
 */
- (id<SKTransaction>)speakString:(NSString *)string
                     withVoice:(NSString *)voice
                      delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform text to speech from SSML markup.
 
 @param markup The SSML to synthesize.
 @param voice The voice to use for speech synthesis.
 @param delegate Transaction delegate.
 */
- (id<SKTransaction>)speakMarkup:(NSString *)markup
                     withVoice:(NSString *)voice
                      delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform text to speech from a string.
 
 @param string The text to synthesize.
 @param language The language to use for speech synthesis.  The server will 
 select the best voice for the language.
 @param delegate Transaction delegate.
 */
- (id<SKTransaction>)speakString:(NSString *)string
                  withLanguage:(NSString *)language
                      delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform text to speech from SSML markup.
 
 @param markup The SSML to synthesize.
 @param language The language to use for speech synthesis.  The server will 
 select the best voice for the language.
 @param delegate Transaction delegate.
 */
- (id<SKTransaction>)speakMarkup:(NSString *)markup
                  withLanguage:(NSString *)language
                      delegate:(id <SKTransactionDelegate>)delegate;

@end

/*!
 @abstract The SKSessionDelegate protocol provides methods for being notified of session events.
 */
@protocol SKSessionDelegate <NSObject>
@optional

/*!
 @abstract Called when the SKSession instance has terminated and can be safely deallocated.
 */
- (void)sessionDidTerminate:(SKSession*)session;

@end