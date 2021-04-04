#include "../ascendii.h"

bool Input::initialized = false;
unsigned char Input::keyboardState[256];
unsigned char Input::lastKeyboardState[256];
unsigned long long int Input::keyPressTime[256];

void Input::initialize() {
    if (!Input::initialized) {
        GetKeyState(0);
        Input::initialized = GetKeyboardState(Input::keyboardState);
        Input::initialized = GetKeyboardState(Input::lastKeyboardState);
    }
}

bool Input::getKeyDown(int key) {
    initialize();
    if ((Input::keyboardState[key] & 128) && !(Input::lastKeyboardState[key] & 128)) {
        return true;
    }
    return false;
}

bool Input::getKeyUp(int key) {
    initialize();
    if (!(Input::keyboardState[key] & 128) && (Input::lastKeyboardState[key] & 128)) {
        return true;
    }
    return false;
}

int Input::getKeyHold(int key) {
    initialize();
    if ((Input::keyboardState[key] & 128) && (Input::lastKeyboardState[key] & 128)) {
        return Input::keyPressTime[key];
    }
    return 0;
}

void Input::update(int deltaTime) {
    for (int i = 0; i < 256; i++) {
        Input::lastKeyboardState[i] = Input::keyboardState[i];
        if ((Input::keyboardState[i] & 128) && (Input::lastKeyboardState[i] & 128)) {
            Input::keyPressTime[i] += deltaTime;
        } else {
            Input::keyPressTime[i] = 0;
        }
    }
    GetKeyState(0);
    GetKeyboardState(Input::keyboardState);
}
