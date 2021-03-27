#ifndef SPRITE_H

#include "../ascendii.h"

class Sprite {
    private:
        CHAR_INFO** sprite;
        int width;
        int height;
        void flip();
        bool flipped = false;
        Sprite(CHAR_INFO** sprite, int width, int height);

    public:
        Sprite(std::string sprite[], int colors[], int width, int height);
        Sprite(std::string sprite[], int color, int width, int height);
        ~Sprite();
        void init(std::string sprite[], int colors[], int width, int height);
        void draw(Screen* screen, int originX, int originY, bool flipHorizontal = false, char transparent = 0);
        int getWidth();
        int getHeight();
        void setColor(int color);
        void setColor(int colors[]);
        int getColor(int width, int height);
        Sprite* clone();
};

#endif // SPRITE_H

