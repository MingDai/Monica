//
//  NMT_BluetoothManager.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2014-04-18.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <nmt_audio/NMT_AudioType.h>

/**
 * NMT helper class to manage Bluetooth
 */
@interface NMT_BluetoothManager : NSObject

/**
 * The method detects the connected Bluetooth headset and returns
 * the adjusted desired audio type which is compatible with the 
 * audio frequency of the connected headset.
 *
 * @param audioType The desired audio type
 *
 * @return The bluetooth compatible audio type. May return nil
 *         if no compatibale audio type avaiable.
 */
+ (const NMT_AudioType *) getBluetoothCompatibleAudioType:(const NMT_AudioType *) desiredAudioType;

@end
