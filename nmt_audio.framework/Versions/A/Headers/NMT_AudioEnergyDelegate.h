//
//  AudioEnergyDelegate.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2013-01-30.
//  Copyright (c) 2013 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NMT_IAudioEnergyInfo.h"

@protocol NMT_AudioEnergyDelegate <NSObject>

/**
 * Called when a new energy value is available
 * @param energyInfo Contains info related to the energy of the audio signal.
 */
-(void) onEnergyLevelAvailable:(id<NMT_IAudioEnergyInfo>)energyInfo;

@end
