//
//  NMT_IAudioEnergyInfo.h
//  nmt
//
//  Created by Builder on 2014-06-13.
//  Copyright (c) 2014 Nuance Communications Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NMT_IAudioEnergyInfo <NSObject>

/**
 * The audio energy level is within the range from 0 to 90, the value is proportional to
 * the loudness of the audio. Based on the experiments, only the audio with the
 * energy value greater than 40 will be heard by normal human ears.
 * @param nChannelIndex Zero-based index for the Audio Channel
 * @return Energy value given in dB SPL (Sound Pressure Level)
 */
-(float) getEnergyLevel:(int) nChannelIndex;

/**
 * The amplitude level (between -1 and +1) at the time that the callback was raised.
 * @param nChannelIndex Zero-based index for the Audio Channel
 * @return Amplitude Level between -1 and +1
 */
-(float) getInstantAmplitudeLevel:(int) nChannelIndex;


/**
 * Retrieve the number of channels in the current AudioEnergyInfo
 * @return nChannelIndex Zero-based index for the Audio Channel
 */
-(int) channelCount;

@end