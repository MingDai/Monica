//
//  Param.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-23.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

//typedef enum {
//    PARAM_TYPE_AUDIO = 1,
//    PARAM_TYPE_TTS = 2,
//    PARAM_TYPE_STRING = 3,
//    PARAM_TYPE_INTEGER = 4,
//    PARAM_TYPE_BYTES = 5,
//    PARAM_TYPE_DICTIONARY = 6,
//    PARAM_TYPE_SEQUENCE = 7,
//    PARAM_TYPE_SEQUENCE_START = 8,
//    PARAM_TYPE_SEQUENCE_CHUNK = 9,
//    PARAM_TYPE_SEQUENCE_END = 10
//} ParamType;

/**
 * Represents a parameter that is sent in an NMAS command. Contains the logic
 * for sending the specific parameter type.
 */
@protocol NMT_IParam <NSObject>

@end

/*
 * Creates a DataParam object.
 */
@protocol NMT_IDataParam <NMT_IParam>

@end


/*
 * Creates a DataParam object.
 */
@protocol NMT_ITtsParam <NMT_IParam>

@end

