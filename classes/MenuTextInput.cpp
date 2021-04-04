#include "../ascendii.h"

MenuTextInput::MenuTextInput(Sprite* sprite, std::string fixed, std::string variable, int maxLength, bool active, int inactiveColor, int activeColor) :
        MenuElement(sprite, active, inactiveColor, activeColor) {
    this->maxLength = maxLength;
    this->fixed = fixed;
    this->variable = variable;
    this->spriteString[0] = fixed + variable;
}

void MenuTextInput::keyInput() {
    if (this->active && this->variable.length() < this->maxLength - 1) {
        for (char i = 'A'; i <= 'Z'; i++) {
            if (Input::getKeyDown(i)) {
                if (Input::getKeyHold(VK_SHIFT)) {
                    this->variable += i;
                } else {
                    this->variable += i + 32;
                }
                delete this->sprite;
                this->spriteString[0] = this->fixed + this->variable;
                this->sprite = new Sprite(this->spriteString, COLOR_RED, this->spriteString[0].length(), 1);
            }
        }
        if (Input::getKeyDown(VK_SPACE)) {
            this->variable += " ";
            delete this->sprite;
            this->spriteString[0] = this->fixed + this->variable;
            this->sprite = new Sprite(this->spriteString, COLOR_RED, this->spriteString[0].length(), 1);
        }
        if (Input::getKeyDown(VK_BACK)) {
            this->variable = this->variable.substr(0, this->variable.length() - 1);
            delete this->sprite;
            this->spriteString[0] = this->fixed + this->variable;
            this->sprite = new Sprite(this->spriteString, COLOR_RED, this->spriteString[0].length(), 1);
        }
    }
}

std::string MenuTextInput::getVariable() {
    return this->variable;
}
