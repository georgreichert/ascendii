#include "../ascendii.h"

// colors can be passed as one dimensional array of integers (left to right, line by line) or as single color value (see function below)
Sprite::Sprite(std::string sprite[], int colors[], int width, int height) {
    init(sprite, colors, width, height);
}

// colors can be passed as one dimensional array of integers (see above function) (left to right, line by line) or as single color value
Sprite::Sprite(std::string sprite[], int color, int width, int height) {
    int colors[width * height];
    for (int i = 0; i < width * height; i++) {
        colors[i] = color;
    }
    init(sprite, colors, width, height);
}

// this constructor is only used for cloning sprites
Sprite::Sprite(CHAR_INFO** sprite, int width, int height) {
    this->sprite = sprite;
    this->width = width;
    this->height = height;
}

// initialize sprite after different constructors are handled
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

// draws sprite to the screen at specified origin coordinates
void Sprite::draw(Screen* screen, int originX, int originY, bool flipHorizontal) {
    CHAR_INFO* buffer = screen->getBuffer();
    int screenWidth = screen->getWidth();
    if ((flipHorizontal && !this->flipped) || (!flipHorizontal && this->flipped)) {
        flip();
    }
    for (int y = originY; y < this->height + originY; y++) {
        for (int x = originX; x < this->width + originX; x++) {
            if (this->sprite[x-originX][y-originY].Char.AsciiChar != this->transparent) {
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

// colors can be passed as one dimensional array of integers (see function below) (left to right, line by line) or as single color value
void Sprite::setColor(int color) {
    int colors[this->width * this->height];
    for (int i = 0; i < this->width * this-> height; i++) {
        colors[i] = color;
    }
    setColor(colors);
}

// colors can be passed as one dimensional array of integers (see above function) (left to right, line by line) or as single color value
void Sprite::setColor(int colors[]) {
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            this->sprite[x][y].Attributes = colors[x + y * this->height];
        }
    }
}

// returns the color of one specific character
int Sprite::getColor(int x, int y) {
    return this->sprite[x][y].Attributes;
}

Sprite::~Sprite() {
    for (int i = 0; i < this->width; i++) {
        delete[] this->sprite[i];
    }
    delete[] this->sprite;
}

// private, only used by draw() method
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

// sprite cloning can be useful when you have to use the same sprite flipped and normally
// to boost performance

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

// sets the char that is not drawn, 0 for no transparency
void Sprite::setTransparent(char transparent) {
    this->transparent = transparent;
}
