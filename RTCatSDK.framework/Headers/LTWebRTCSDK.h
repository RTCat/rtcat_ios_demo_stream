//
//  LTWebRTCSDK.h
//  WebRTCSDK
//
//  Created by Think on 16/1/10.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LTWebRTCSDK : NSObject

+ (NSString *)curVersion;

+ (LTWebRTCSDK *)shareInstance;

- (void)initWebRTC;
- (void)destroyWebRTC;

@end
