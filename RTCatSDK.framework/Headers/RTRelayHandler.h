//
//  RTRelayHandler.h
//  WebRTCSDK
//
//  Created by Think on 16/1/13.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


@class SRWebSocket;
@class RTSender;
@class RTSessionLinkConfig;
@protocol RTSessionObserver;


@class RTCPeerConnectionFactory;

@interface RTRelayHandler: NSObject
{
    NSString *_timestamp;
    NSMutableArray *_wits;
    
    NSMutableDictionary *_connector;
    NSMutableDictionary *_remote;
    NSString *_pwd;
    
    NSMutableDictionary *_jsonIceServer;
    NSString *_selfToken;
    
    RTCPeerConnectionFactory *_peerConnectionFactory;
    SRWebSocket *_socket;
    
    id<RTSessionObserver> _observer;
}

- (id)initWithObserver:(id<RTSessionObserver>)sessionObserver WithSocket:(SRWebSocket *)socket WithPeerConnectionFactory:(RTCPeerConnectionFactory *) factory timestamp:(NSString *)t;
- (void)onMessage:(NSString*) eventName withData:(NSDictionary *) data;
- (void)link:(RTSessionLinkConfig *)slc;
- (void)send:(RTSender *)sender;
- (void)sendTo:(RTSender*)sender to:(NSString *)to;
- (void)doRelease;

@end