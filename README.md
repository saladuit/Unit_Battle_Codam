# **Codam_Unit_Battle**
A Codam Coding College battle session

## Project Goal
The game consists of 10 frames.  In each frame the player has
two opportunities to knock down 10 pins.  The score for the frame is the total
number of pins knocked down, plus bonuses for strikes and spares.

A spare is when the player knocks down all 10 pins in two tries.  The bonus for
that frame is the number of pins knocked down by the next roll.  So in frame 3
above, the score is 10 (the total number knocked down) plus a bonus of 5 (the
number of pins knocked down on the next roll.)

A strike is when the player knocks down all 10 pins on his first try.  The bonus
for that frame is the value of the next two balls rolled.

In the tenth frame a player who rolls a spare or strike is allowed to roll the extra
balls to complete the frame.  However no more than three balls can be rolled in
tenth frame.

Write a program that can calculate the score of a bowlingame. The program should be called like this:
```console
./bolwing_game 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
20
```
Invalid input should display Error\n like this:
```console
./bolwing_game a 100 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
Error\n
```

## Rules
Abide the rules of TDD at all times:

You are not allowed to write any production code until you have first written a failing unit test.

You are not allowed to write more of a unit test than is sufficient to fail– and not compiling is failing. 

You are not allowed to write more production code that is sufficient to pass the currently failing unit test.

You will work in a team of 2-4 people in which half of the team will write the FAILING UNITE TESTS and the other half of the team will write code that makes the tests pass. Good communication will be of the utmost importance!

## winning conditions
The code has to take in 0-21 valid bowling scores and calculate the apropiate scores

The code will be graded on a mix of coverage

The projects with the best scores will be graded by nicolas and a winner will be picked

## Usage
Run the following command before starting your project or add these commands to your .zsh or .bashrc
```console
	export LIBRARY_PATH=/sgoinfre/criterion_test/.brew/lib:${LIBRARY_PATH}
	export C_INCLUDE_PATH=/sgoinfre/criterion_test/.brew/include:${C_INCLUDE_PATH}
```
Alternatively run the bash script inside the folder
```console
	bash environment.sh
```
Compile the project
```console
make;
```
Recompile the project
```console
make re:	
```
Remove all of the files.
```console
make fclean
```
Run all of the tests.
```console
make tests_run
```
Recompile your tests.
```console
make re_tests
```
Find leaks in your program
```console
make fsan
```
Compile a debuggable executable
```console
make debug
```
## License
The MIT License (MIT)

Copyright (c) 2021 Saladin Lorenzo Afoh

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
