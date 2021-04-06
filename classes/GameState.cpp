#include "../ascendii.h"

GameState::GameState(Screen* screen) {
    this->screen = screen;
}

GameState::~GameState() {

}

// set this->leave = true to indicate that this GameState wants to end,
// which can be accessed by this method
bool GameState::leaveStatus() {
    return this->leave;
}

// set this->nextState to the next GameState you want to load,
// which can be accessed by this method
// it is set back to nullptr afterwards, so you can return to this
// GameState later
GameState* GameState::getNextState() {
    GameState* temp = this->nextState;
    this->nextState = nullptr;
    return temp;
}
