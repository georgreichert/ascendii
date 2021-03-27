################################
#     ascendii Game Engine     #
################################

****************
*** CONTENTS ***

1) Setup
2) Basic game loop
3) Working with GameStates
4) Drawing to the screen
5) Working with Sprites
6) Working with MenuElements
7) Working with SubStates
8) Using the DebugLog

****************
*** 1) Setup ***

Copy files and folders into your project folder, then
#include "ascendii.h"

**************************
*** 2) Basic game loop ***

This basic game loop is implemented using Stacks of GameStates, but other implementations are of course possible.

int main() {
    srand((unsigned)time(0));
    DebugLog::reset();
    Screen* screen = new Screen();
    screen->fullScreen();
    int key = -1;
    bool pressed = false;
    int deltaTime = 0;
    std::stack<GameState*> stateStack;
    stateStack.push(new YourGameState(screen)); // You have to write your own GameStates that inherit from GameState

    while (1) {
        deltaTime = Time::getDeltaTime();

	// these are all the Keys currently defined in the "ascendii.h" file
        if (GetAsyncKeyState(VK_ESCAPE)) {
            key = KEY_ESC;
        } else if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
            key = KEY_SPACE;
        } else if (GetAsyncKeyState(VK_UP)) {
            key = KEY_UP;
        } else if (GetAsyncKeyState(VK_DOWN)) {
            key = KEY_DOWN;
        } else if (GetAsyncKeyState(VK_LEFT)) {
            key = KEY_LEFT;
        } else if (GetAsyncKeyState(VK_RIGHT)) {
            key = KEY_RIGHT;
        } else if (GetAsyncKeyState('A')) {
            key = 'A';
        } else if (GetAsyncKeyState('S')) {
            key = 'S';
        } else if (GetAsyncKeyState('D')) {
            key = 'D';
        } else if (GetAsyncKeyState('J')) {
            key = 'J';
        } else if (GetAsyncKeyState('K')) {
            key = 'K';
        } else if (GetAsyncKeyState('L')) {
            key = 'L';
        } else {
            pressed = false;
            key = -1;
        }
        if (!pressed && key != -1) {
            stateStack.top()->keyInput(key);
            pressed = true;
        }
        GameState* next = stateStack.top()->getNextState();
        if (next != nullptr) {
            stateStack.push(next);
        }
        if (stateStack.top()->leaveStatus()) {
            delete stateStack.top();
            stateStack.pop();
        }
        if (stateStack.empty()) {
            break;
        }
        screen->updateWidth();
        screen->clear();
        stateStack.top()->update(deltaTime);
        screen->write(std::to_string(1000 / deltaTime) + " FPS", 0, 0, COLOR_WHITE);
        screen->draw();
    }

    while(!stateStack.empty()) {
        delete stateStack.top();
        stateStack.pop();
    }
    Database::destroy();
    delete screen;

}

**********************************
*** 3) Working with GameStates ***

GameStates can be used to create different functionality for each part of the game in a
standardized manner. GameStates can represent levels of the game, or menus, for example.
The GameState class is an abstract class that provides the basic functionality every GameState
needs:

GameState* getNextState();
bool leaveStatus();

getNextState() can be used to access the next GameState that should be loaded, which, in the basic
game loop provided here, is then added on top of the GameState-stack. It can be set from within the
GameStates methods with

this->nextState = pointerToNextGameState;

leaveStatus() is used in a similar manner. To indicate that a GameState wants to close, use

this->leave = true;

inside the GameStates methods. In the basic game loop above, this will cause the deletion and removal
of the state from the stack, returning to the underlying GameState from which it was loaded. If the
state-stack is empty, the loop breaks and the game ends.
Each child of the GameState class must provide a constructor that takes a pointer to a Screen, a destrucor 
and these 2 methods:

void keyInput(int key);
void update(int deltaTime);

which are used to receive and process keyboard inputs and to update the GameState with each frame.
keyInput(int key) will be discarded in the future, and input will be handled in its own class that
will be accessible inside the update method, to enable the handling of simultaneous key inputs.
The update method is called once per frame by the game loop. It's main use is for game logic and to draw
to the screen. The deltaTime, the time since the last frame was drawn to the screen, that is  passed to 
update() is available through

Time::getDeltaTime()

which must not be used more than once per loop cycle, because it contains a throttling mechanism to slow the
engine down to 50 FPS, because the theoretically possible 500-1000 FPS that can be achieved in the console
kept crashing the program randomly.


********************************
*** 4) Drawing to the screen ***

In your custom gamestates update method, you can draw to the Screen by using the draw() 
method of the Object you want to draw, for example

someSprite->draw(screen, 0, 0, true);

will draw the sprite someSprite with its upper left corner in the upper left corner
of the screen, the bool tells it to flip horizontally first. 
Please note that currently no means of error detection are implemented,
so drawing outside the bounds of your screen will cause the program to crash, especially
to the left side, because it will try to access negative array indexes.
This can also happen if you calculate the coordinates for drawing at runtime and then
resize the console window to a very small size, which tends to push objects over the
left edge of the screen.
You can always get the current width of the screen through using

this->screen->getWidth()

inside your gamestates methods.
The Screen class also has some predefined functions for drawing basic shapes or writing strings
to the screen, currently these are

void horizontalLine(int originX, int originY, int length, int color = COLOR_WHITE , char c = '#');
void verticalLine(int originX, int originY, int length, int color = COLOR_WHITE, char c = '#');
void write(std::string word, int originX, int originY, int color = COLOR_WHITE);

The screen itself has a draw() method too, which is used to write the screens buffer to the console, 
which should be done once per game loop. clear() is used to clear the buffer before drawing the new
frame to it.

*******************************
*** 5) Working with Sprites ***

To create a new sprite, use

new Sprite(std::string sprite[], int color, int width, int height);

or

new Sprite(std::string sprite[], int colors[], int width, int height);

"color" is one color code for the whole sprite, "colors" is a one-dim. array of
integer values with which you can set the color of every pixel, line by line
from left to right. For example

std::string player[5] = {
        "####  ##      ####  ##  ## ###### #### ",
        "## ## ##     ##  ##  ####  ##     ## ##",
        "####  ##     ######   ##   ####   #### ",
        "##    ##     ##  ##   ##   ##     ## ##",
        "##    ###### ##  ##   ##   ###### ##  #"
    };
Sprite* someSprite = new Sprite(player, COLOR_YELLOW, player[0].length(), 5);

creates a "PLAYER"-sprite, completely in yellow characters.

************************************
*** 6) Working with MenuElements ***

A MenuElement is just an Object that conatains a sprite and has predefined colors for
an active and an inactive state. This state can be toggled by using

someMenuElement->toggleActive();

As with sprites, you can simply draw it to the screen by using

someMenuElement->draw(Screen* Screen, int originX, int originY);

*********************************
*** 7) Working with SubStates ***

A substate is a portion of the screen that is implemented as its own GameState, which
can be useful, for example, if you have your screen split into two parts that both include
different functionality or if you want to have instances of the same type of SubState more
than once on your screen. SubStates can track if they are currently focused or not, which can be
toggled by

someSubState->toggleFocus();

SubStates are abstract classes, as are GameStates. To create a new SubState, use

new ChildOfSubState(Screen* screen, float start, float width, int startLine, int height);

For example

new ChildOfSubState(this->screen, 0.3f, 0.5f, 10, 20);

will create a SubState with its left edge at 30% of the screen width, a width of 50% the screens width,
starting at line 10 of the screen (which is the 11th line, of course) and with a height of 20,
ending at line 30.

*****************************
*** 8) Using the DebugLog ***

To use the DebugLog, create a directory in your games root directory called "debug". To write to the logfile
in this directory, just use the static method

DebugLog::log(std::string)

inside your code. Log entries will written to a "log.txt" file. To clear the log file, you can use 

DebugLog::reset()

which the standard game loop uses when the game starts.