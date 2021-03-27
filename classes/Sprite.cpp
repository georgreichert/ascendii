#include "../ascendii.h"

Sprite::Sprite(std::string sprite[], int colors[], int width, int height) {
    init(sprite, colors, width, height);
}

Sprite::Sprite(std::string sprite[], int color, int width, int height) {
    int colors[width * height];
    for (int i = 0; i < width * height; i++) {
        colors[i] = color;
    }
    init(sprite, colors, width, height);
}

Sprite::Sprite(CHAR_INFO** sprite, int width, int height) {
    this->sprite = sprite;
    this->width = width;
    this->height = height;
}

void Sprite::init(std::string sprite[], int colors[], int width, int height) {
    this->width = width;
    this->height = height;
    this->sprite = new CHAR_INFO*[width];
    for (int i = 0; i < width; i++) {
        this->sprite[i] = new CHAR_INFO[height];
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            this->sprite[x][y].Char.AsciiChar = sprite[y][x];
            this->sprite[x][y].Attributes = colors[x + y * width];
        }
    }
}

void Sprite::draw(Screen* screen, int originX, int originY, bool flipHorizontal, char transparent) {
    CHAR_INFO* buffer = screen->getBuffer();
    int screenWidth = screen->getWidth();
    if ((flipHorizontal && !this->flipped) || (!flipHorizontal && this->flipped)) {
        flip();
    }
    for (int y = originY; y < this->height + originY; y++) {
        for (int x = originX; x < this->width + originX; x++) {
            if (this->sprite[x-originX][y-originY].Char.AsciiChar != transparent) {
                buffer[x + y * screenWidth] = this->sprite[x-originX][y-originY];
            }
        }
    }
}

int Sprite::getWidth() {
    return this->width;
}

int Sprite::getHeight() {
    return this->height;
}

void Sprite::setColor(int color) {
    int colors[this->width * this->height];
    for (int i = 0; i < this->width * this-> height; i++) {
        colors[i] = color;
    }
    setColor(colors);
}

void Sprite::setColor(int colors[]) {
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            this->sprite[x][y].Attributes = colors[x + y * this->height];
        }
    }
}

int Sprite::getColor(int x, int y) {
    return this->sprite[x][y].Attributes;
}

Sprite::~Sprite() {
    for (int i = 0; i < this->width; i++) {
        delete[] this->sprite[i];
    }
    delete[] this->sprite;
}

void Sprite::flip() {
    CHAR_INFO temp;
    for (int x = 0; x < this->width / 2; x++) {
        for (int y = 0; y < this->height; y++) {
            temp = this->sprite[x][y];
            this->sprite[x][y] = this->sprite[this->width - 1 - x][y];
            this->sprite[this->width - 1 - x][y] = temp;
        }
    }
    this->flipped = !this->flipped;
}

Sprite* Sprite::clone() {
    CHAR_INFO** newSprite;
    newSprite = new CHAR_INFO*[this->width];
    for (int i = 0; i < width; i++) {
        newSprite[i] = new CHAR_INFO[this->height];
    }
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            newSprite[x][y] = this->sprite[x][y];
        }
    }
    return new Sprite(newSprite, this->width, this->height);
}
