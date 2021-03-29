#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#include <fstream>

class DebugLog {
    private:

    public:
        static void log(std::string text);
        // erases the previous log file
        static void reset();
};

#endif // DEBUGLOG_H

