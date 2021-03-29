#include "../ascendii.h"

class Animation {
    private:

    public:
        virtual void draw(Screen* screen, int deltaTime, bool flipHorizontal) = 0;
};
