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
        SubState(Screen* screen, float start, float width, int startLine, int height);
        virtual ~SubState() = 0;
        virtual void keyInput(int key) = 0;
        virtual void update(int deltaTime) = 0;
        virtual void toggleFocus();
        SubState* getNextState();
};

#endif // SUBSTATE_H
