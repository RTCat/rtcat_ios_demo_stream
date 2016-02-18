//
//  RTSender.h
//  WebRTCSDK
//
//  Created by Think on 16/1/10.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCDataChannel.h"
#import "RTCICECandidate.h"
#import "RTCMediaStream.h"
#import "RTCPeerConnection.h"
#import "RTCICEServer.h"
#import "RTCPeerConnectionFactory.h"
#import "RTCSessionDescription.h"
#import "RTCSessionDescriptionDelegate.h"

#import "SRWebSocket.h"
#import "RTChannel.h"
#import "RTStream.h"
#import "RTSenderInitConfig.h"

@protocol RTSenderObserver <NSObject>

/**
 * 触发关闭事件
 */
- (void)senderClose;

@end

@interface RTSender : RTChannel
{
    id<RTSenderObserver> _observer;
    NSString *_to;

    NSString *_pwd;
    RTStream *_stream;
    BOOL _hasData;
    NSTimer *_statsTimer;
    
    NSString *_role;
    double _audioSent;
    double _videoSent;

    NSMutableArray *_queuedRemoteCandidates;
}

- (id)init:(RTSenderInitConfig *)configDic WithSocket:(SRWebSocket *)socket WithPeerConnectionFactory:(RTCPeerConnectionFactory *) factory;
- (void)addObserver:(id<RTSenderObserver>) observer;
- (void)receive:(NSDictionary *)sdp;
- (void)sendMessage:(NSDictionary *)message;
- (NSString *)getTo;
- (void)close;

@end
