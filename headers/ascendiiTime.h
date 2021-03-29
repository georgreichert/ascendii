#ifndef ASCENDIITIME_H
#define ASCENDIITIME_H

class Time {
    private:
        static int throttle;
        static int lastFrame;

    public:
        // only use once per frame and store it in a variable, or throttling mechanism will cause cumulative delays
        static int getDeltaTime();
};

#endif // ASCENDIITIME_H
