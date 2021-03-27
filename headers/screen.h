#ifndef SCREEN_H
#define SCREEN_H

#include "../ascendii.h"

class Screen {
    private:
        HANDLE hWrite;
        COORD bufferSize;
        COORD characterPosition = {0, 0};
        SMALL_RECT consoleWriteArea;
        CHAR_INFO consoleBuffer[50000];
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        void updateWidth();

    public:
        Screen();
        void draw();
        CHAR_INFO* getBuffer();
        void clear();
        int getWidth();
        void horizontalLine(int originX, int originY, int length, int color = COLOR_WHITE , char c = '#');
        void verticalLine(int originX, int originY, int length, int color = COLOR_WHITE, char c = '#');
        void write(std::string word, int originX, int originY, int color = COLOR_WHITE);
        void fullScreen();
};

#endif // SCREEN_H
