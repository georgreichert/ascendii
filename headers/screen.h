#ifndef SCREEN_H
#define SCREEN_H

#include "../ascendii.h"

class Screen {
    private:
        HANDLE hWrite;
        COORD bufferSize;
        COORD characterPosition = {0, 0};
        SMALL_RECT consoleWriteArea;
        // change this array size if your console window is wider than 330 characters
        // arraysize should be larger than 150 * screens width
        CHAR_INFO consoleBuffer[50000];
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        // ensures correct display after resizing the console window
        void updateWidth();

    public:
        // sonsoleTitle sets text in title bar
        Screen(std::string consoleTitle);
        void draw();
        CHAR_INFO* getBuffer();
        // should usually be called before drawing to reset all characters in buffer to whitespace
        void clear();
        int getWidth();
        void horizontalLine(int originX, int originY, int length, int color = COLOR_WHITE , char c = '#');
        void verticalLine(int originX, int originY, int length, int color = COLOR_WHITE, char c = '#');
        // writes a string to the screen
        void write(std::string word, int originX, int originY, int color = COLOR_WHITE);
        void fullScreen();
};

#endif // SCREEN_H
