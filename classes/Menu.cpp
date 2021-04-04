#include "../ascendii.h"

Menu::Menu(Screen* screen) {
    this->screen = screen;
}

void Menu::prev() {
    if (this->cursorPosition > 0) {
        this->menuElements[cursorPosition]->toggleActive();
        this->cursorPosition--;
        this->menuElements[cursorPosition]->toggleActive();
    }
}

void Menu::next() {
    if (this->cursorPosition < this->menuElements.size() - 1) {
        this->menuElements[cursorPosition]->toggleActive();
        this->cursorPosition++;
        this->menuElements[cursorPosition]->toggleActive();
    }
}

MenuElement* Menu::getMenuElement(int index) {
    if (index >= 0 && index < this->menuElements.size()) {
        return this->menuElements[index];
    }
}
