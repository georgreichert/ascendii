#include "../ascendii.h"

MoveAnimation::MoveAnimation(Sprite* sprite, int startX, int startY, int endX, int endY, int duration) {
    this->startX = startX;
    this->startY = startY;
    this->endX = endX;
    this->endY = endY;
    this->duration = duration;
    this->sprite = sprite;
}

void MoveAnimation::draw(Screen* screen, int deltaTime, bool flipHorizontal, char transparent) {
    this->currentDuration += deltaTime;
    float lerpValue = (float)this->currentDuration / this->duration;
    DebugLog::log(std::to_string(lerpValue) + " " + std::to_string(this->currentDuration) + " " + std::to_string(this->duration));
    this->sprite->draw(screen, startX + lerpValue * (endX - startX),
                       startY + lerpValue * (endY - startY), flipHorizontal, transparent);
}
