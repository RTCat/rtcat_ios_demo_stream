//
//  RTSession.h
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

#import "RTReceiver.h"
#import "RTSender.h"
#import "SRWebSocket.h"

@protocol RTSessionObserver <NSObject>

- (void)sessionInToken:(NSString *)token;
- (void)sessionOutToken:(NSString *)token;
- (void)sessionConnected:(NSArray *)wits;
- (void)sessionRemote:(RTReceiver *)receiver;
- (void)sessionLocal:(RTSender *)sender;
- (void)sessionMessageWithToken:(NSString *)token messgae:(NSString *)message;
- (void)sessionError:(NSString *)error;

@end

@class RTP2pHandler;
@class RTRelayHandler;

@interface RTSession : NSObject
{
    NSInteger _timeout;
    RTCPeerConnectionFactory *_peerConnectionFactory;
    SRWebSocket *_socket;
    NSString *_timestamp;
    
    NSMutableDictionary *_jsonIceServer;
    NSString *_selfToken;
    NSString *_pwd;
    NSString *_type;
    
    id<RTSessionObserver> _observer;
    
    RTP2pHandler *_p2pHandler;
    RTRelayHandler *_relayHandler;
}
- (id)initWithToken:(NSString *)token WithUrl:(NSString *)url WithPeerConnectionFactory:(RTCPeerConnectionFactory *) factory;
- (void)addObserver:(id<RTSessionObserver>) observer;
- (void)connect;
- (void)link:(RTSessionLinkConfig *)slc;

- (void)sendWithConfig:(RTSessionSendConfig *)ssc;
- (void)sendWithRTSender:(RTSender *)sender;
- (void)sendP2pTo:(RTSessionSendConfig *)ssc to:(NSString *)to;
- (void)sendToRalayWithSender:(RTSender *)sender to:(NSString *)to;
- (void)disconnect;

@end
