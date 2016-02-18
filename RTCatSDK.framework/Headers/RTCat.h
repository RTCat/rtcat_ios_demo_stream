//
//  RTCat.h
//  WebRTCSDK
//
//  Created by Think on 16/1/10.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCPeerConnectionFactory.h"
#import "RTSession.h"
#import "RTStream.h"

/**
 *  RTCat Android SDK入口,用于创建 session 和 stream
 */

@interface RTCat : NSObject

+ (RTCat *)shareInstance;

- (RTSession *)createSessionWithToken:(NSString*) token;
- (RTSession *)createSessionWithToken:(NSString*) token withUrl:(NSString *)url;

- (RTStream *)createStreamWithDelagete:(id<RTStreamObserverDelagate>) streamDelegate;;
- (RTStream *)createStreamWithVideo:(BOOL)isVideo withAudio:(BOOL)isAudio withDelagete:(id<RTStreamObserverDelagate>) streamDelegate;
- (RTStream *)createStreamWithVideo:(BOOL)isVideo withAudio:(BOOL)isAudio Fps:(NSInteger)fps width:(NSInteger)w height:(NSInteger)h videoIndex:(NSInteger)facing withDelagete:(id<RTStreamObserverDelagate>) streamDelegate;

@end

