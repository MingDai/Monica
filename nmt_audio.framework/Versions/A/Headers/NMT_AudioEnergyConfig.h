//
//  NMT_AudioEnergyConfig.h
//  nmt
//
//  Created by Luc_Moreault on 2014-06-13.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Initialize the AudioEnergyCalculatorPipe with specific values.
 * @param iRefreshRateMs   Rate (in MS) at which the calculation will 
 * be done and the listener callback raised.
 */
@interface NMT_AudioEnergyConfig : NSObject

@property (nonatomic) int   iRefreshRateMs;

@end