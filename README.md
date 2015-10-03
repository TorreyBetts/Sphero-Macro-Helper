## Requirements

- Xcode
- Sphero SDK
- A robot sold and supported by Sphero

## Installation

Simply copy the source files found in this repository to your Xcode project.

## Usage

Macros from the Sphero iOS SDK worked like the snippet below.

    RKMacroObject *macro = [RKMacroObject new];
    [macro addCommand:[RKMCLoopFor commandWithRepeats:2]];
    [macro addCommand:[RKMCRGB commandWithRed:0 green:0 blue:0 delay:250]];
    [macro addCommand:[RKMCDelay commandWithDelay:250]];
    [macro addCommand:[RKMCSlew commandWithRed:1 green:0 blue:0 delay:1000]];
    [macro addCommand:[RKMCDelay commandWithDelay:1000]];
    [macro addCommand:[RKMCLoopEnd command]];
    RKMacroPlayer *player = [[RKMacroPlayer alloc] initWithRobot:_robot.robot];
    [player play:macro];
    
With the Sphero Macro Helper, the macro usage has been simplified.

    [SpheroMacroHelper performCommandsUsingRobot:_robot timesToRepeat:5 autoplay:YES commands:^(RKMacroObject *macro)
    {
        [SpheroMacroHelper ledFrontChangeUsingMacro:macro color:[UIColor blackColor] fadeInto:NO delay:250];
        [SpheroMacroHelper ledFrontChangeUsingMacro:macro color:[UIColor redColor] fadeInto:YES delay:1000];
    } completion:nil];

## License

The MIT License (MIT)

Copyright (c) 2015 Torrey Betts

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.