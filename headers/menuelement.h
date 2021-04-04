#ifndef MENUELEMENT_H
#define MENUELEMENT_H

#include "../ascendii.h"

class MenuElement {
    protected:
        Sprite* sprite;
        bool active;
        int inactiveColor;
        int activeColor;

    public:
        // active elements are shown with activeColor,
        // inactive elements are shown with inactiveColor
        MenuElement(Sprite* sprite, bool active = false, int inactiveColor = COLOR_WHITE, int activeColor = COLOR_RED);
        ~MenuElement();
        // toggle active state of an element and change its color accordingly
        void toggleActive();
        int getWidth();
        int getHeight();
        void draw(Screen* Screen, int originX, int originY);
        bool isActive();
};

#endif // MENUELEMENT_H
