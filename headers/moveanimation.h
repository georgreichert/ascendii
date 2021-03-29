#include "../ascendii.h"

class MoveAnimation : public Animation {
    private:
        int startX;
        int startY;
        int endX;
        int endY;
        int duration;
        int currentDuration = 0;
        Sprite* sprite;

    public:
        // duration in milliseconds
        MoveAnimation(Sprite* sprite, int startX, int startY, int endX, int endY, int duration);
        void draw(Screen* screen, int deltaTime, bool flipHorizontal);
};
