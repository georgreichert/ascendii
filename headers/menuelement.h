#ifndef MENUELEMENT_H
#define MENUELEMENT_H

#include "../ascendii.h"

class MenuElement {
    private:
        Sprite* sprite;
        bool active;
        int inactiveColor;
        int activeColor;

    public:
        MenuElement(Sprite* sprite, bool active = false, int inactiveColor = COLOR_WHITE, int activeColor = COLOR_RED);
        ~MenuElement();
        void toggleActive();
        int getWidth();
        int getHeight();
        void draw(Screen* Screen, int originX, int originY);
        bool isActive();
};

#endif // MENUELEMENT_H
