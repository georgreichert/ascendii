#include "../ascendii.h"

GameState::GameState(Screen* screen) {
    this->screen = screen;
}

GameState::~GameState() {

}

bool GameState::leaveStatus() {
    return leave;
}

GameState* GameState::getNextState() {
    GameState* temp = this->nextState;
    this->nextState = nullptr;
    return temp;
}
