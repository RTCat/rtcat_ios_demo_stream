//
//  RTConfig.h
//  WebRTCSDK
//
//  Created by Think on 16/1/10.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

enum RTStatus: NSInteger {
    DISCONNECTED = 0,
    CONNECTING = 1,
    CONNECTED = 2
};

@interface RTConfig : NSObject
{
}

+ (NSString *)WSS;

@end
