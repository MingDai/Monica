//
//  ViewController.h
//  Monica
//
//  Created by Ming Dai on 11/7/15.
//  Copyright © 2015 Ming Dai. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SpeechKit/SKTransaction.h>
#import "AppDelegate.h"

@interface ViewController : UIViewController
{
    int counter;
}

@property (weak, nonatomic) IBOutlet UILabel *lblMonica;
@property (weak, nonatomic) IBOutlet UIButton *btnRecord;
@property (weak, nonatomic) IBOutlet UILabel *lblMessage;
@property (weak, nonatomic) IBOutlet UILabel *lblTime;
- (IBAction)btnRecord:(id)sender;
@property (assign) int counter;
@property (assign, nonatomic) SKTransactionEndOfSpeechDetection endpointer;

@end

