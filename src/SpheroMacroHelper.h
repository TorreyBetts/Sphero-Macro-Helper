//
//  SpheroMacroHelper.h
//
//  Created by Torrey Betts on 9/28/15.
//  Copyright © 2015 Torrey Betts. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RobotKit/RobotKit.h>

/*!
The SpheroMacroHelper class was created to simplify the use of macros that are provided by the Sphero SDK.

When using the Sphero SDK macro classes require several lines of code to define the macro for execution.

    RKMacroObject *macro = [RKMacroObject new];
    [macro addCommand:[RKMCLoopFor commandWithRepeats:2]];
    [SpheroMacroHelper rotateUsingMacro:macro rotation:180 delay:500];
    [macro addCommand:[RKMCDelay commandWithDelay:500]];
    [macro addCommand:[RKMCLoopEnd command]];
    RKMacroPlayer *player = [[RKMacroPlayer alloc] initWithRobot:_robot.robot];
    [player play:macro];

To simplify macro creation and give it a more iOS feel like when working with UIView animations, macro commands are added into a command block and are executed first with an option to repeat after completion. Once commands are executed a second set of commands can also be executed.

    [SpheroMacroHelper performCommandsUsingRobot:_robot timesToRepeat:1 autoplay:YES commands:^(RKMacroObject *macro)
    {
        [SpheroMacroHelper rotateUsingMacro:macro rotation:180 delay:500];
    } completion:nil];

 */
@interface SpheroMacroHelper : NSObject

/** Perform a sequence of macro commands and an optional completion sequence of macro commands.

 @param robot The connected robot instance that the macro commands will be executed.
 @param timesToRepeat Number of times to repeat the commands within the commands block.
 @param autoplay Automatically start the sequence of macro commands within the commands and completion blocks.
 @param commands Block of macro commands.
 @param completion Block of macro commands that execute after the commands block completes.
 @return The RKMacroObject instance that was created

 */
+ (RKMacroObject *)performCommandsUsingRobot:(RKConvenienceRobot *)robot
                               timesToRepeat:(uint8_t)timesToRepeat
                                    autoplay:(BOOL)autoplay
                                    commands:(void (^)(RKMacroObject *macro))commands
                                  completion:(void (^)(RKMacroObject *macro))completion;

/** Macro command to calibrate the robot by setting it's heading direction

 @param macro The connected robot instance that the macro commands will be executed.
 @param heading The heading direction the robot will be calibrated to. Valid values are 0-359.
 @param delay The delay in milliseconds after this command to execute the next command. Valid values are 0-255.

 */
+ (void)calibrateUsingMacro:(RKMacroObject *)macro heading:(int)heading delay:(int)delay;

/** Macro command to add a delay between other macro commands. This macro allows for the delay to exceed the 255 millisecond delay limit.

 @param macro The connected robot instance that the macro commands will be executed.
 @param delay The delay in milliseconds after this command to execute the next command. Valid values are 0-65535.

 */
+ (void)delayUsingMacro:(RKMacroObject *)macro delay:(int)delay;

/** Macro command to fade the front LED in the robot to the specified color.

 @param macro The connected robot instance that the macro commands will be executed.
 @param color The color for the LED to change to.
 @param fadeInto Specifies if the LED will fade into the newly assigned color.
 @param delay The delay in milliseconds after this command to execute the next command.

 */
+ (void)ledFrontChangeUsingMacro:(RKMacroObject *)macro color:(UIColor *)color fadeInto:(BOOL)fadeInto delay:(int)delay;

/** Macro command to change the back LED in the robot to the specified color and intensity.

 @param macro The connected robot instance that the macro commands will be executed.
 @param color The color for the LED to change to.
 @param intensity The intensity the back LED will be lit at. Valid values are 0.0-1.0.
 @param delay The delay in milliseconds after this command to execute the next command.

 */
+ (void)ledBackChangeUsingMacro:(RKMacroObject *)macro color:(UIColor *)color intensity:(float)intensity delay:(int)delay;

/** Macro command to roll the robot at a given heading direction and speed.

 @param macro The connected robot instance that the macro commands will be executed.
 @param speed The speed at which the robot will roll. Valid values are 0.0-1.0.
 @param heading The heading direction the robot will be calibrated to. Valid values are 0-359.
 @param delay The delay in milliseconds after this command to execute the next command. Valid values are 0-255.

 */
+ (void)rollUsingMacro:(RKMacroObject *)macro speed:(float)speed heading:(int)heading delay:(int)delay;

/** Macro command to rotate the robot over a given time.

 @param macro The connected robot instance that the macro commands will be executed.
 @param rotation The number of degrees the robot should rotate. Valid values are -32767-32767.
 @param delay The delay in milliseconds after this command to execute the next command. Valid values are 0-65535.

 */
+ (void)rotateUsingMacro:(RKMacroObject *)macro rotation:(short)rotation delay:(int)delay;

/** Macro command to turn robot stabilization on or off.

 @param macro The connected robot instance that the macro commands will be executed.
 @param setting The stabilization setting. Valid values are 0-1, 0=off and 1=on.
 @param delay The delay in milliseconds after this command to execute the next command. Valid values are 0-255.

 */
+ (void)stabilizationUsingMacro:(RKMacroObject *)macro setting:(int)setting delay:(int)delay;

/** Macro command to stop the robot without altering its current heading direction.

 @param macro The connected robot instance that the macro commands will be executed.
 @param delay The delay in milliseconds after this command to execute the next command. Valid values are 0-255.

 */
+ (void)stopUsingMacro:(RKMacroObject *)macro delay:(int)delay;

@end
