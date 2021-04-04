#ifndef INPUT_H
#define INPUT_H

#include "../ascendii.h"

class Input {
    private:
        static unsigned char keyboardState[256];
        static unsigned char lastKeyboardState[256];
        static unsigned long long int keyPressTime[256];
        static bool initialized;
        static void initialize();

    public:
        static void update(int deltaTime);
        static bool getKeyDown(int key);
        static int getKeyHold(int key);
        static bool getKeyUp(int key);
};

#endif // INPUT_H
