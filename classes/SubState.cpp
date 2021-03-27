#include "../ascendii.h"

SubState::SubState(Screen* screen, float start, float width, int startLine, int height) : GameState(screen) {
    this->start = start;
    this->width = width;
    this->startLine = startLine;
    this->height = height;
}

SubState::~SubState() {

}

void SubState::toggleFocus() {
    this->focused = !this->focused;
}

SubState* SubState::getNextState() {
    SubState* temp = this->nextState;
    this->nextState = nullptr;
    return temp;
}
