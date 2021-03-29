#ifndef SUBSTATE_H
#define SUBSTATE_H

#include "../ascendii.h"

class SubState : public GameState {
    private:

    protected:
        float width;
        float start;
        int height;
        int startLine;
        bool focused = false;
        SubState* nextState = nullptr;

    public:
        // start between 0.0f (left edge) and 1.0f (right edge)
        // width between 0.0f an 1.0f, 0-100% of the screen
        // height in lines
        // startLine is topmost line of the SubState
        SubState(Screen* screen, float start, float width, int startLine, int height);
        virtual ~SubState() = 0;
        virtual void keyInput(int key) = 0;
        virtual void update(int deltaTime) = 0;
        // SubStates can be focuesed or unfocused, which can be useful for menus, for example
        virtual void toggleFocus();
        // override with different return pointer type
        // set this->nextState to the next GameState you want to load,
        // which can be accessed by this method
        // it is set back to nullptr afterwards, so you can return to this
        // SubState later
        SubState* getNextState();
};

#endif // SUBSTATE_H
