//
//  RTReceiver.h
//  WebRTCSDK
//
//  Created by Think on 16/1/10.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCDataChannel.h"
#import "RTCICECandidate.h"
#import "RTCPeerConnection.h"
#import "RTCPeerConnectionFactory.h"
#import "RTCSessionDescriptionDelegate.h"

#import "SRWebSocket.h"
#import "RTChannel.h"
#import "RTStream.h"

@protocol RTReceiverObserver <NSObject>
/**
 * 接收到 数据流
 * @param stream
 */
- (void)receiverStream:(RTStream *)stream;


/**
 * 接收到 消息流
 * @param message
 */
- (void)receiverMessage:(NSString *)message;

/**
 * 触发关闭事件
 */
- (void)receiverClose;

@end

@interface RTReceiver : RTChannel
{
    NSString *_role;
    double _audioSent;
    double _videoSent;
    NSTimer *_statsTimer;
    
    NSString *_pwd;
    NSString *_from;
    
    id<RTReceiverObserver> _observer;
    NSDictionary *_jsonSdp;
    RTStream *_stream;
    //dataChannel observer
}

- (id)init:(NSDictionary *)configDic withChannelId:(NSString *)channelid WithSocket:(SRWebSocket *)socket WithPeerConnectionFactory:(RTCPeerConnectionFactory *) factory;
- (void)response;
- (void)addObserver:(id<RTReceiverObserver>) observer;
- (NSString *)getFrom;
- (void)close;

@end
