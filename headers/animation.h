#include "../ascendii.h"

class Animation {
    private:

    public:
        virtual void draw(Screen* screen, int deltaTime, bool flipHorizontal, char transparent) = 0;
};
