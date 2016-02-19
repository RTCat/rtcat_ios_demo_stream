//
//  ViewController.m
//  RTCatDemoStream
//
//  Created by chencong on 2/18/16.
//  Copyright © 2016 shishimao. All rights reserved.
//

#import "ViewController.h"

#import <RTCatSDK/RTCat.h>
#import <RTCatSDK/RTStream.h>
#import <RTCatSDK/LTRTCEAGLVideoView.h>

@interface ViewController ()
{
    RTStream *_localStream;
}

@property (strong, nonatomic) LTRTCEAGLVideoView *localView;
@property (strong, nonatomic) RTCVideoTrack *localVideoTrack;

@end

@interface ViewController (RTCEAGLVideoView)<RTCEAGLVideoViewDelegate>
@end

@interface ViewController (StreamObserverDelagate)<RTStreamObserverDelagate,RTStreamObserverDelagate>
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGSize size = [UIScreen mainScreen].bounds.size;
    
    CGRect rLocal = CGRectMake(10, 10 + 20, size.width - 20, size.height/2 - 20  - 20);
    _localView = [[LTRTCEAGLVideoView alloc] initWithFrame:rLocal];
    [_localView setBackgroundColor:[UIColor redColor]];
    
    [self.view addSubview:_localView];
    
    
    [_localView setDelegate:self];

    
    RTCat *cat = [RTCat shareInstance];
    _localStream = [cat createStreamWithVideo:YES withAudio:YES Fps:20 width:_localView.bounds.size.width height:_localView.bounds.size.height videoIndex:RTCamrareBack withDelagete:self];
    [_localStream play:_localView];
    
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveLocalVideoTrack:(RTCVideoTrack *)localVideoTrack {
    NSLog(@"%s",__FUNCTION__);
    if (self.localVideoTrack) {
        [self.localVideoTrack removeRenderer:self.localView];
        self.localVideoTrack = nil;
        [self.localView renderFrame:nil];
    }
    self.localVideoTrack = localVideoTrack;
    [self.localVideoTrack addRenderer:self.localView];
}

- (void)videoView:(RTCEAGLVideoView*)videoView didChangeVideoSize:(CGSize)size {
    NSLog(@"%s",__FUNCTION__);
}




@end
