#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../ascendii.h"

class GameState {
    private:

    protected:
        Screen* screen = nullptr;
        bool leave = false;
        GameState* nextState = nullptr;

    public:
        GameState(Screen* screen);
        virtual ~GameState() = 0;
        virtual void keyInput(int key) = 0;
        virtual void update(int deltaTime) = 0;
        GameState* getNextState();
        bool leaveStatus();
};

#endif // GAMESTATE_H
