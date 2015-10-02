//
//  SpheroMacroHelper.m
//
//  Created by Torrey Betts on 9/28/15.
//  Copyright © 2015 Torrey Betts. All rights reserved.
//

#import "SpheroMacroHelper.h"

@implementation SpheroMacroHelper

+ (RKMacroObject *)performCommandsUsingRobot:(RKConvenienceRobot *)robot timesToRepeat:(uint8_t)timesToRepeat autoplay:(BOOL)autoplay commands:(void (^)(RKMacroObject *macro))commands completion:(void (^)(RKMacroObject *macro))completion
{
    RKMacroObject *macro = [RKMacroObject new];
    if (!commands)
        return macro;

    [macro addCommand:[RKMCLoopFor commandWithRepeats:++timesToRepeat]];
    commands(macro);
    [macro addCommand:[RKMCLoopEnd command]];

    if (completion)
        completion(macro);

    if (autoplay && robot)
    {
        RKMacroPlayer *player = [[RKMacroPlayer alloc] initWithRobot:robot.robot];
        [player play:macro];
    }

    return macro;
}

+ (void)calibrateUsingMacro:(RKMacroObject *)macro heading:(int)heading delay:(int)delay
{
    [macro addCommand:[RKMCCalibrate commandWithHeading:heading delay:delay]];
    [macro addCommand:[RKMCDelay commandWithDelay:delay]];
}

+ (void)delayUsingMacro:(RKMacroObject *)macro delay:(int)delay
{
    [macro addCommand:[RKMCDelay commandWithDelay:delay]];
}

+ (void)stabilizationUsingMacro:(RKMacroObject *)macro setting:(int)setting delay:(int)delay
{
    [macro addCommand:[RKMCStabilization commandWithSetting:setting delay:delay]];
    [macro addCommand:[RKMCDelay commandWithDelay:delay]];
}

+ (void)rollUsingMacro:(RKMacroObject *)macro speed:(float)speed heading:(int)heading delay:(int)delay
{
    [macro addCommand:[RKMCRoll commandWithSpeed:speed heading:heading delay:delay]];
    [macro addCommand:[RKMCDelay commandWithDelay:delay]];
}

+ (void)rotateUsingMacro:(RKMacroObject *)macro rotation:(short)rotation delay:(int)delay
{
    [macro addCommand:[RKMCRotateOverTime commandWithRotation:rotation delay:delay]];
    [macro addCommand:[RKMCDelay commandWithDelay:delay]];
}

+ (void)ledBackChangeUsingMacro:(RKMacroObject *)macro color:(UIColor *)color intensity:(float)intensity delay:(int)delay
{
    if (!color)
        return;

    [macro addCommand:[RKMCFrontLED commandWithIntensity:intensity delay:delay]];
    [macro addCommand:[RKMCDelay commandWithDelay:delay]];
}

+ (void)ledChangeUsingMacro:(RKMacroObject *)macro color:(UIColor *)color fadeInto:(BOOL)fadeInto delay:(int)delay
{
    if (!color)
        return;

    CGFloat red, green, blue, alpha;
    [color getRed:&red green:&green blue:&blue alpha:&alpha];

    if (fadeInto)
        [macro addCommand:[RKMCSlew commandWithRed:red green:green blue:blue delay:delay]];
    else
        [macro addCommand:[RKMCRGB commandWithRed:red green:green blue:blue delay:delay]];

    [macro addCommand:[RKMCDelay commandWithDelay:delay]];
}

+ (void)stopUsingMacro:(RKMacroObject *)macro delay:(int)delay
{
    [macro addCommand:[RKMCStop commandWithSpeed:0.0 delay:delay]];
}

@end
