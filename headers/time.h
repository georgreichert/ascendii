#ifndef TIME_H
#define TIME_H

class Time {
    private:
        static int throttle;
        static int lastFrame;

    public:
        static int getDeltaTime();
};

#endif // TIME_H
