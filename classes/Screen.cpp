#include "../ascendii.h"

Screen::Screen() {
    this->hWrite = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("Fight Club");
    GetConsoleScreenBufferInfo(this->hWrite, &this->consoleInfo);
    this->bufferSize = {this->consoleInfo.dwSize.X, 150};
    this->consoleWriteArea = {0, 0, this->consoleInfo.dwSize.X, 150};
    SetConsoleScreenBufferSize(this->hWrite, this->bufferSize);
}

void Screen::draw() {
    updateWidth();
    WriteConsoleOutputA(this->hWrite, this->consoleBuffer, this->bufferSize, this->characterPosition, &this->consoleWriteArea);
}

CHAR_INFO* Screen::getBuffer() {
    return this->consoleBuffer;
}

void Screen::updateWidth() {
    GetConsoleScreenBufferInfo(this->hWrite, &this->consoleInfo);
    this->bufferSize = {this->consoleInfo.dwSize.X, 150};
    this->consoleWriteArea = {0, 0, this->consoleInfo.dwSize.X, 150};
    SetConsoleScreenBufferSize(this->hWrite, this->bufferSize);
}

void Screen::clear() {
    for (int i = 0; i < this->consoleInfo.dwSize.X * 150; i++) {
        this->consoleBuffer[i].Char.AsciiChar = ' ';
        this->consoleBuffer[i].Attributes = 7;
    }
}

int Screen::getWidth() {
    return this->consoleInfo.dwSize.X;
}

void Screen::horizontalLine(int originX, int originY, int length, int color, char c) {
    for (int x = originX; x < originX + length; x++) {
        this->consoleBuffer[x + originY * this->getWidth()].Char.AsciiChar = c;
        this->consoleBuffer[x + originY * this->getWidth()].Attributes = color;
    }
}

void Screen::verticalLine(int originX, int originY, int length, int color, char c) {
    for (int y = originY; y < originY + length; y++) {
        this->consoleBuffer[originX + y * this->getWidth()].Char.AsciiChar = c;
        this->consoleBuffer[originX + y * this->getWidth()].Attributes = color;
    }
}

void Screen::write(std::string word, int originX, int originY, int color) {
    for (int x = originX; x < originX + word.length(); x++) {
        this->consoleBuffer[x + this->getWidth() * originY].Char.AsciiChar = word[x-originX];
        this->consoleBuffer[x + this->getWidth() * originY].Attributes = color;
    }
}

void Screen::fullScreen() {
    ShowWindow(GetConsoleWindow() , SW_MAXIMIZE);
}
