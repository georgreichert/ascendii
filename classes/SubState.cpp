#include "../ascendii.h"

// start between 0.0f (left edge) and 1.0f (right edge)
// width between 0.0f an 1.0f, 0-100% of the screen
// height in lines
// startLine is topmost line of the SubState
SubState::SubState(Screen* screen, float start, float width, int startLine, int height) : GameState(screen) {
    this->start = start;
    this->width = width;
    this->startLine = startLine;
    this->height = height;
}

SubState::~SubState() {

}

// SubStates can be focuesed or unfocused, which can be useful for menus, for example
void SubState::toggleFocus() {
    this->focused = !this->focused;
}

// override with different return pointer type
// set this->nextState to the next GameState you want to load,
// which can be accessed by this method
// it is set back to nullptr afterwards, so you can return to this
// SubState later
SubState* SubState::getNextState() {
    SubState* temp = this->nextState;
    this->nextState = nullptr;
    return temp;
}
