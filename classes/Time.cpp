#include "../ascendii.h"

int Time::throttle = 20;
int Time::lastFrame = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

int Time::getDeltaTime() {
    unsigned long long int thisFrame = 0;
    int deltaTime = 0;
    while (deltaTime < Time::throttle) {
        thisFrame = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        deltaTime = thisFrame - lastFrame;
    }
    int r = deltaTime;
    Time::lastFrame = thisFrame;
    return r;
}
