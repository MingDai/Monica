//
//  SimpleWordList.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-12-07.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <nmt_core/grammar/NMT_IWordList.h>

@interface NMT_SimpleWordList : NSObject<NMT_IWordList>

+(id) wordListWithChecksum:(int)checksum;

-(void)appendWord:(NMT_WordAction *)wordAction;

@end
