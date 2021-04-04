#ifndef MENUTEXTINPUT_H
#define MENUTEXTINPUT_H

#include "../ascendii.h"

class MenuTextInput : public MenuElement {
    private:
        std::string fixed;
        std::string variable;
        std::string spriteString[1];
        int maxLength;

    public:
        MenuTextInput(Sprite* sprite, std::string fixed, std::string variable, int maxLength, bool active = false, int inactiveColor = COLOR_WHITE, int activeColor = COLOR_RED);
        void keyInput();
        std::string getVariable();
};

#endif // MENUTEXTINPUT_H
