//
//  RTSessionSendConfig.h
//  WebRTCSDK
//
//  Created by Think on 16/1/10.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCMediaStream.h"
#import "RTStream.h"
/**
 * Session配置文件
 */
@interface RTSessionSendConfig : NSObject
{
    RTStream *_stream;
    NSDictionary *_jsonAttr;
    BOOL _data;
}

- (id)initWithStream:(RTStream *)stream withData:(NSDictionary *)attr isData:(BOOL)data;

- (BOOL)isData;
- (NSDictionary *)getAttr;
- (RTStream *)getStream;

@end
