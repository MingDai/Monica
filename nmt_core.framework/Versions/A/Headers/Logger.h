//
//  Logger.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-11-13.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum _NMT_LOG_LEVEL {
    NMT_LOG_NONE    = 0x0,
    NMT_LOG_ERROR = 0x1,
    NMT_LOG_WARN  = 0x2,
    NMT_LOG_INFO  = 0x4,
    NMT_LOG_DEBUG = 0x8,
    NMT_LOG_VERBOSE = 0x10,
    NMT_LOG_PROFILE = 0x20
} NMT_LOG_LEVEL;


@interface NMT_LogInfo : NSObject

@property (readonly, nonatomic) NMT_LOG_LEVEL eLoggingLevel; /**< NMT log level */
@property (readonly, nonatomic) int64_t       iSystemTime;	 /**< Time, in nanoseconds, retrieved from the system
                                                              clock (wall lock), based on epoch Jan 1 1970. */
@property (readonly, retain)   NSString *     sMessage;      /**< UTF8 encoded C string containing the message, guaranteed
                                                              to be non-null when instance received by \ref FNmtLogCallback */
@property (readonly, retain)   NSString *     sFuncName;     /**< C string containing the undecorated function/method name of
                                                              the log entry */
@property (readonly, retain)   NSString *     sFilePath;     /**< C string containing the relative source file path of the log
                                                              entry */
@property (readonly, nonatomic)   int         nFileLineNo;   /**< Line number in the source file of the log entry */
@end



@protocol NMT_LoggerDelegate <NSObject>

-(void) onLogCallback:(NMT_LogInfo *) rNmtLogInfo;

@end

@interface NMT_Logger : NSObject

+(void) debug:(NSString *)format, ...;
+(void) info:(NSString *)format, ...;
+(void) warn:(NSString *)format, ...;
+(void) error:(NSString *)format, ...;

+(int) level;
+(void) setLevel:(int) level;

+(void) setDelegate:(id<NMT_LoggerDelegate>)delegate;

@end
