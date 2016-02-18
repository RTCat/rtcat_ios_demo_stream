//
//  RTStream.h
//  WebRTCSDK
//
//  Created by Think on 16/1/12.
//  Copyright © 2016年 北京乐塔克科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCPeerConnectionFactory.h"
#import "RTCMediaStream.h"
#import "RTCEAGLVideoView.h"
#import "RTCAudioTrack.h"
#import "RTCVideoTrack.h"

enum RTCamrareIndexPosition: NSInteger {
    RTCamrareFront = 1,
    RTCamrareBack = 2
};

typedef NS_ENUM(NSInteger, LTStreamState) {
    // Disconnected from servers.
    kLTStreamStateDisconnected,
    // Connecting to servers.
    kLTStreamStateConnecting,
    // Connected to servers.
    kLTStreamStateConnected,
};

@protocol RTStreamObserverDelagate <NSObject>
- (void)didChangeState:(LTStreamState)state;

- (void)didReceiveLocalVideoTrack:(RTCVideoTrack *)localVideoTrack;

- (void)didReceiveRemoteVideoTrack:(RTCVideoTrack *)remoteVideoTrack;

- (void)didError:(NSError *)error;

@end

@interface RTStream : NSObject

@property (nonatomic, weak) id<RTStreamObserverDelagate> streamDelegate;

- (id)initLocalStream:(RTCPeerConnectionFactory *)peerConnectionFactory withVideo:(BOOL)isVideo withAudio:(BOOL)isAudio withW:(NSInteger)w withH:(NSInteger)h withFPS:(NSInteger)fps
      withCameraIndex:(NSInteger)cameraPos withDelagete:(id<RTStreamObserverDelagate>) streamDelegate;
- (id)initRemoteStream:(RTCMediaStream *)remoteStream;


- (void)play:(RTCEAGLVideoView *) glSurfaceView;
- (void)switchCamera;

- (RTCVideoTrack *)getVideoTrack;
- (RTCAudioTrack *)getAudioTrack;
- (RTCMediaStream *)getMediaStream;

@end