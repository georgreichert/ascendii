#ifndef MENU_H
#define MENU_H

#include "../ascendii.h"

class Menu {
    protected:
        std::vector<MenuElement*> menuElements;
        Screen* screen;
        int cursorPosition = 0;

    public:
        Menu(Screen* screen);
        void prev();
        void next();
        virtual void draw(int originX, int originY) = 0;
        virtual void select() = 0;
        MenuElement* getMenuElement(int index);
};

#endif // MENU_H
