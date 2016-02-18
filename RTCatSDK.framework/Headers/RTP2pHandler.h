//
//  RTP2pHandler.h
//  WebRTCSDK
//
//  Created by Think on 16/1/13.
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

@protocol RTSessionObserver;

@interface RTP2pHandler: NSObject
{
    NSString *_timestamp;
    NSMutableArray *_wits;
    
    NSMutableDictionary *_local;
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
- (void)send:(RTSessionSendConfig *) ssc;
- (void)sendTo:(RTSessionSendConfig *)ssc to:(NSString *)to;
- (void)doRelease;

@end