//
//  RTSessionLinkConfig.h
//  WebRTCSDK
//
//  Created by Think on 16/1/12.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTStream.h"

@interface RTSessionLinkConfig : NSObject
{
     RTStream *_stream;
}

- (id)initWithStream:(RTStream *)stream;
- (RTStream *)getStream;

@end
