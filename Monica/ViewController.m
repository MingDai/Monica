//
//  ViewController.m
//  Monica
//
//  Created by Ming Dai on 11/7/15.
//  Copyright © 2015 Ming Dai. All rights reserved.
//

#import <SpeechKit/SpeechKit.h>
#import "ViewController.h"
#import "SKSConfiguration.h"
#import <AVFoundation/AVFoundation.h>

// State Logic: IDLE -> LISTENING -> PROCESSING -> repeat
enum {
    SKSIdle = 1,
    SKSListening = 2,
    SKSProcessing = 3
};
typedef NSUInteger SKSState;

@interface ViewController () <SKTransactionDelegate, SKAudioDelegate, SKAudioPlayerDelegate>
{
    id<SKTransaction> transaction;
    SKSession* session;
    SKSState state;

    SKAudioFile* startEarcon;
    SKAudioFile* stopEarcon;
    SKAudioFile* errorEarcon;

}@end

bool running;
NSString* input;
int numStart, numEnd;
NSString* interval;


@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    transaction = nil;
    state = SKSIdle;
    
    _lblTime.hidden = true;
  
    // Create a session
    session = [[SKSession alloc] initWithURL:[NSURL URLWithString:SKSServerUrl]
                                       appToken:[NSData dataWithBytesNoCopy:SKSAppKey length:64 freeWhenDone:NO]];
    
    if (!session) {
        UIAlertView* alertView = [[UIAlertView alloc]initWithTitle:@"SpeechKit"
                                                           message:@"Failed to initialize SpeechKit session."
                                                          delegate:nil cancelButtonTitle:@"OK"
                                                 otherButtonTitles:nil, nil];
        [alertView show];
    }
    
    session.audioPlayer.delegate = self;
    // Tell the AudioPlayer to start playing as soon as we enqueue an Audio .
    [session.audioPlayer play];
    
        // Load all of the earcons from disk
        
        NSString* startEarconPath = [[NSBundle mainBundle] pathForResource:@"sk_start" ofType:@"pcm"];
        NSString* stopEarconPath = [[NSBundle mainBundle] pathForResource:@"sk_stop" ofType:@"pcm"];
        NSString* errorEarconPath = [[NSBundle mainBundle] pathForResource:@"sk_error" ofType:@"pcm"];
        
        startEarcon = [[SKAudioFile alloc] initWithURL:[NSURL fileURLWithPath:startEarconPath] delegate:self];
        [startEarcon load];
        
        stopEarcon = [[SKAudioFile alloc] initWithURL:[NSURL fileURLWithPath:stopEarconPath] delegate:self];
        [stopEarcon load];
        
         errorEarcon = [[SKAudioFile alloc] initWithURL:[NSURL fileURLWithPath:errorEarconPath] delegate:self];
        [errorEarcon load];
 }

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)btnRecord:(id)sender
{
   
    switch (state) {
        case SKSIdle:
            [[session audioPlayer] enqueue:startEarcon];
            break;
        case SKSListening:
            // Stop recording the user.
            [transaction stopRecording];
            // Disable the button until we received notification that the transaction is completed.
            [_btnRecord setEnabled:NO];
            
            break;
        case SKSProcessing:
            [transaction cancel];
            break;
        default:
            break;
    }
}

#pragma mark - SKAudioPlayerDelegate

- (void)audioPlayer:(SKAudioPlayer *)player willBeginPlaying:(id <SKAudio>)audio
{
}

- (void)audioPlayer:(SKAudioPlayer *)player didFinishPlaying:(id <SKAudio>)audio
{
    // We should make sure to let the start earcon finish playing before we start to listen.
    // This will ensure that there are no earcon artifacts in the recording.
    if(audio == startEarcon) {

            // Start listening to the user.
            //[_toggleRecogButton setTitle:@"Stop" forState:UIControlStateNormal];
            transaction = [session recognizeWithService:SKSNLUContextTag
                                                    detection:SKTransactionEndOfSpeechDetectionLong
                                                     language:@"eng-USA"
                                                         data:nil
                                                     delegate:self];

    }
}

# pragma mark - SKTransactionDelegate

- (void)transactionDidBeginRecording:(id<SKTransaction>)transaction
{
    NSLog(@"transactionDidBeginRecording");
    state = SKSListening;
    [_btnRecord setTitle:@"Listening.." forState:UIControlStateNormal];
}

- (void)transactionDidFinishRecording:(id<SKTransaction>)transaction
{
    NSLog(@"transactionDidFinishRecording");
    state = SKSProcessing;
    [_btnRecord setTitle:@"What are you doing?" forState:UIControlStateNormal];
    
    [[session audioPlayer] playAudio:stopEarcon];
}


- (void)transaction:(id<SKTransaction>)transaction didReceiveRecognition:(SKRecognition *)recognition
{
    NSLog([NSString stringWithFormat:@"didReceiveRecognition: %@", recognition.text]);
    state = SKSIdle;
    _lblMessage.text = recognition.text;
    input = recognition.text;
    NSRange searchNumber = [input rangeOfString:@"for"];
    if (searchNumber.location == NSNotFound)
    {
        
    }else
    {
        numStart = searchNumber.location + searchNumber.length;
        NSString* strNum = [input substringFromIndex:(numStart)];
        
        NSRange searchEndNumber = [input rangeOfString:@" "];
        numEnd = searchNumber.length + 1;
        interval = [input substringWithRange:NSMakeRange(numStart, numEnd)];
        _lblMessage.text = interval;
        int number;
        
        if (interval == @"one")
        {
            number = 1;
        }
        if (interval == @"two")
        {
            number = 2;
        }
        if (interval == @"three")
        {
            number = 3;
        }
        if (interval == @"four")
        {
            number = 4;
        }
        if(running == false)
        {
            running = true;
            _lblTime.hidden = false;
            counter = 10;
            NSTimer *countdownTimer = [NSTimer scheduledTimerWithTimeInterval:1
                                                                       target:self
                                                                     selector:@selector(updateTimer:)
                                                                     userInfo:nil
                                                                      repeats:YES];
        }else
        {
            running = false;
        }

        

    }
}

- (void)transaction:(id<SKTransaction>)transaction didReceiveServiceResponse:(NSDictionary *)response
{
    NSLog([NSString stringWithFormat:@"didReceiveServiceResponse: %@", [response description]]);
    state = SKSIdle;
    [self resetTransaction];
}

- (void)transaction:(id<SKTransaction>)transaction didReceiveInterpretation:(SKInterpretation *)interpretation
{
    NSLog([NSString stringWithFormat:@"didReceiveInterpretation: %@", interpretation.result]);
    state = SKSIdle;
    [self resetTransaction];
}

- (void)transaction:(SKTransaction *)transaction didFinishWithSuggestion:(NSString *)suggestion
{
    NSLog(@"didFinishWithSuggestion");
    
}

- (void)transaction:(SKTransaction *)transaction didFailWithError:(NSError *)error suggestion:(NSString *)suggestion
{
    NSLog([NSString stringWithFormat:@"didFailWithError: %@. %@", [error description], suggestion]);
    
    state = SKSIdle;
    [self resetTransaction];
    
    [[session audioPlayer] playAudio:errorEarcon];
}
- (void)resetTransaction
{
    [[NSOperationQueue mainQueue] addOperationWithBlock:^{
        transaction = nil;
        [_btnRecord setEnabled:YES];
    }];
}

- (void)updateTimer:(NSTimer *)timer
{
    printf("timer running");
    counter = counter -1;
    int hours = counter / 3600;
    int minutes = (counter % 3600) / 60;
    int seconds = (counter %3600) % 60;
    _lblTime.text =[NSString stringWithFormat:@"Time Remaining %02d:%02d:%02d", hours, minutes, seconds];
    if(counter <=0) {[timer invalidate]; }
}

@end
