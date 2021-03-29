#ifndef SPRITE_H

#include "../ascendii.h"

class Sprite {
    private:
        CHAR_INFO** sprite;
        int width;
        int height;
        void flip();
        bool flipped = false;
        char transparent = 0;
        // this constructor is only used for cloning sprites
        Sprite(CHAR_INFO** sprite, int width, int height);

    public:
        // colors can be passed as one dimensional array of integers (left to right, line by line) or as single color value (see function below)
        Sprite(std::string sprite[], int colors[], int width, int height);
        // colors can be passed as one dimensional array of integers (left to right, line by line) or as single color value (see function above)
        Sprite(std::string sprite[], int color, int width, int height);
        ~Sprite();
        // initialize sprite after different constructors are handled
        void init(std::string sprite[], int colors[], int width, int height);
        // draws sprite to the screen at specified origin coordinates
        void draw(Screen* screen, int originX, int originY, bool flipHorizontal = false);
        int getWidth();
        int getHeight();
        // colors can be passed as one dimensional array of integers (left to right, line by line) or as single color value (see function below)
        void setColor(int color);
        // colors can be passed as one dimensional array of integers (left to right, line by line) or as single color value (see function above)
        void setColor(int colors[]);
        // returns the color of one specific character
        int getColor(int width, int height);
        // sets the char that is not drawn, 0 for no transparency
        void setTransparent(char transparent);
        // sprite cloning can be useful when you have to use the same sprite flipped and normally
        // to boost performance
        Sprite* clone();
};

#endif // SPRITE_H

