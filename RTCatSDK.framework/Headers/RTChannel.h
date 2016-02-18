//
//  RTChannel.h
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
#import "SRWebSocket.h"
#import "RTConfig.h"

/**
 * Channel 数据通道,Receiver 和 Sender 的父类
 * 数据通道用于建立点对点连接
 */
@interface RTChannel : NSObject
{
    NSString *_channelId;
    NSDictionary *_jsonAttr;
    NSMutableArray *_iceServers;
    
    NSInteger _status;
    SRWebSocket *_socket;
    RTCPeerConnection *_peerConnection;
    RTCPeerConnectionFactory *_factory;
    RTCDataChannel *_dataChannel;
}

- (id)initWithChannelId:(NSString *)channelid WithSocket:(SRWebSocket *)socket WithPeerConnectionFactory:(RTCPeerConnectionFactory *) factory;
- (void)candidate:(NSDictionary *) candidate;
- (void)socketSendMessage:(NSString *)eventName dataDic:(NSDictionary *) data;

- (NSString *)getId;
- (NSDictionary *)getAttr;

@end
