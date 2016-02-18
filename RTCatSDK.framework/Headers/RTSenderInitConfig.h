//
//  RTSenderInitConfig.h
//  WebRTCSDK
//
//  Created by Think on 16/1/10.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTSessionSendConfig.h"

@class RTSessionLinkConfig;
@interface RTSenderInitConfig : RTSessionSendConfig
{
    NSString *_to;
    NSString *_pwd;
}

- (id)init:(RTSessionSendConfig *) ssc to:(NSString *)to pwd:(NSString *)pwd;
- (id)initNoTo:(RTSessionLinkConfig *) ssc pwd:(NSString *)pwd;
- (NSString *)getPwd;
- (NSString *)getTo;

@end
