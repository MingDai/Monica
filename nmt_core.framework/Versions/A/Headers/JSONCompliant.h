//
//  JSONCompliant.h
//  Nuance Mobile Toolkit
//
//  Created by administrator on 2012-10-26.
//  Copyright (c) 2012 administrator. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Interface for objects that can be represented by JSON.
 * <p>
 * Note: there is no 'fromJSON()' method. Any class that can be created from
 * JSON may have its own static creation method or constructor, but it is not
 * part of this interface.
 */

@protocol NMT_JSONCompliant <NSObject>

/**
 * Get the JSON representation of the object.
 * @return A new JSON object representing the object.
 */
-(NSData *) toJSON;

@end
