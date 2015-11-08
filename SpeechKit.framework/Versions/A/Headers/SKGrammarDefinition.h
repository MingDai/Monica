//
//  SKGrammarDefinition.h
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

/*!
 @class SKGrammarDefinition
 @abstract The SKGrammarDefinition class contains recognition grammar 
 data used during a recognition transaction.
 
 @discussion The grammar definition is a light container allowing the 
 transaction to pass essential information to the server to perform various 
 grammar oriented operations from constrained recognition to complex NLU-like 
 interpretations.
 
 Usage:
 SKSynchronizedList *list;
 
 SKGrammarDefinition *cloudDef = [SKGrammarDefinition definitionWithCloudID:@"cloud_grammar"];
 SKGrammarDefinition *listDef = [SKGrammarDefinition definitionFromSynchronizedObject:list];
 SKGrammarDefinition *instantDef = [SKGrammarDefinition definitionFromItems:[@"one", @"two"] withID:@"instants"];
 
 [session recognizeWithType:SKTransactionSpeechTypeDictation
                  detection:SKTransactionEndOfSpeechDetectionLong
                   language:@"en_us"
                   grammars:[cloudDef, listDef, instantDef]
                    options:nil
                   delegate:self];
 */
@interface SKGrammarDefinition : NSObject

/*!
 @abstract Construct a grammar definition from a provisioned static grammar ID.
 */
+ (instancetype)definitionWithCloudID:(NSString *)ID;

/*!
 @abstract Construct a grammar definition from an URL.
 
 @discussion This method allows the user to construct a grammar definition from an URL
 that points to the grammar file. The ID parameter is user-defined and is returned to the
 user as context.
 */
+ (instancetype)definitionFromURL:(NSURL*)url withID:(NSString*)ID;

/*!
 @abstract Construct a grammar definition from the ID and version information 
 for data uploaded with a synchronized list or synchronization command.
 */
+ (instancetype)definitionWithSynchronizedObjectID:(NSString *)ID version:(NSString *)version;


/*!
 @abstract Construct a grammar definition from a list of items and a user 
 specified ID.
 
 @discussion This method allows the user to construct a temporary list that may 
 be used for a single transaction when the overhead of synchronizing and 
 deleting a list is prohibitive.  If the same set of items or a variation of the 
 the items will be reused then a synchronized list should be used instead as it 
 will reduce bandwidth consumption and recognition latency.
 */
+ (instancetype)definitionFromItems:(NSArray *)items withID:(NSString *)ID;

@end
