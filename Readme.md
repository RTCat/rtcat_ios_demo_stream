## 实时猫 iOS Stream Demo

[实时猫](https://shishimao.com) iOS Stream Demo

## 使用

1.下载代码
```
	git clone https://github.com/zombiecong/rtcat_ios_demo_stream.git
```

2.下载 `RTCat.framework`

3.把 `RTCat.framework` 移到 `rtcat_ios_demo_stream` 文件夹下

4.用`Xcode` 打开 `RTCatDemoStream.xcodeproj`

5.运行项目


## 部分代码说明

初始化`_localView ` 用于显示 `RTStream`

```
CGSize size = [UIScreen mainScreen].bounds.size;
    
CGRect rLocal = CGRectMake(10, 10 + 20, size.width - 20, size.height/2 - 20  - 20);
_localView = [[LTRTCEAGLVideoView alloc] initWithFrame:rLocal];
[_localView setBackgroundColor:[UIColor redColor]];
```

获得本地视频流，并播放

```
    
RTCat *cat = [RTCat shareInstance];
_localStream = [cat createStreamWithVideo:YES withAudio:YES Fps:20 width:_localView.bounds.size.width height:_localView.bounds.size.height videoIndex:RTCamrareBack withDelagete:self];
[_localStream play:_localView];
    
```


实现 `Protocol`

```
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

```



