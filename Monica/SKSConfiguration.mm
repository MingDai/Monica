//
//  SKSConfiguration.mm
//  SpeechKitSample
//
//  All Nuance Developers configuration parameters can be set here.
//
//  Copyright (c) 2015 Nuance Communications. All rights reserved.
//

#import "SKSConfiguration.h"

// All fields are required.
// Your credentials can be found in your Nuance Developers portal, under "Manage My Apps".
unsigned char SKSAppKey[] = {0x9d, 0xa2, 0x9e, 0x67, 0x6f, 0xe7, 0x1c, 0x69, 0x7c, 0xf9, 0x24, 0x1e, 0x8a, 0x10, 0xcf, 0x44, 0x3a, 0x72, 0xd4, 0xdc, 0x04, 0x0e, 0xff, 0x28, 0x16, 0x13, 0x28, 0x41, 0x66, 0x27, 0xd2, 0x03, 0xc9, 0x70, 0x6b, 0x38, 0x58, 0x87, 0xa1, 0xd4, 0x80, 0xc5, 0xf2, 0x0a, 0xd5, 0xc2, 0x4e, 0x10, 0x34, 0x22, 0xec, 0x38, 0x31, 0xeb, 0x60, 0x47, 0xfe, 0x89, 0x88, 0x65, 0xb0, 0x5a, 0x68, 0x79};
NSString* SKSAppId = @"NMDPTRIAL_5wackywillies_gmail_com20151107114006";
NSString* SKSServerHost = @"nmsp.dev.nuance.com";
NSString* SKSServerPort = @"443";


NSString* SKSServerUrl = [NSString stringWithFormat:@"nmsp://%@@%@:%@", SKSAppId, SKSServerHost, SKSServerPort];

// Only needed if using NLU/Bolt
NSString* SKSNLUContextTag = @"V1_Project885_App434";


