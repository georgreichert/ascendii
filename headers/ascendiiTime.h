#ifndef ASCENDIITIME_H
#define ASCENDIITIME_H

class Time {
    private:
        static int throttle;
        static int lastFrame;

    public:
        static int getDeltaTime();
};

#endif // ASCENDIITIME_H
