#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#include <fstream>

class DebugLog {
    private:

    public:
        static void log(std::string text);
        static void reset();
};

#endif // DEBUGLOG_H

