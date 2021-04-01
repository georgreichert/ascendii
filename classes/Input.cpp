#include "../ascendii.h"

bool Input::initialized = false;
unsigned char Input::keyboardState[256];
unsigned char Input::lastKeyboardState[256];

void Input::initialize() {
    if (!Input::initialized) {
        GetKeyState(0);
        Input::initialized = GetKeyboardState(Input::keyboardState);
        Input::initialized = GetKeyboardState(Input::lastKeyboardState);
    }
}

bool Input::getKeyDown(int key) {
    initialize();
    DebugLog::log(std::to_string(Input::keyboardState[key]));
    if ((Input::keyboardState[key] & 128) && !(Input::lastKeyboardState[key] & 128)) {
        return true;
    }
    return false;
}

void Input::update(int deltaTime) {
    for (int i = 0; i < 256; i++) {
        Input::lastKeyboardState[i] = Input::keyboardState[i];
    }
    GetKeyState(0);
    GetKeyboardState(Input::keyboardState);
}
