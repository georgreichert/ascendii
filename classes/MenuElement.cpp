#include "../ascendii.h"

// active elements are shown with activeColor,
// inactive elements are shown with inactiveColor
MenuElement::MenuElement(Sprite* sprite, bool active, int inactiveColor, int activeColor) {
    this->active = active;
    this->sprite = sprite;
    this->inactiveColor = inactiveColor;
    this->activeColor = activeColor;
}

MenuElement::~MenuElement() {
    delete this->sprite;
}

// toggle active state of an element and change its color accordingly
void MenuElement::toggleActive() {
    this->active = !this->active;
    if(this->active && this->sprite->getColor(0,0) != this->activeColor) {
        this->sprite->setColor(this->activeColor);
    } else if (!this->active && this->sprite->getColor(0,0) != this->inactiveColor) {
        this->sprite->setColor(this->inactiveColor);
    }
}

void MenuElement::draw(Screen* screen, int originX, int originY) {
    this->sprite->draw(screen, originX, originY);
}

int MenuElement::getWidth() {
    return this->sprite->getWidth();
}

int MenuElement::getHeight() {
    return this->sprite->getHeight();
}

bool MenuElement::isActive() {
    return this->active;
}
