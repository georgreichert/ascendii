#include "../headers/debuglog.h"


// to use DebugLog, create /debug directory in your root directory
void DebugLog::log(std::string text) {
    static int logCounter = 0;
    std::ofstream log("debug/log.txt", std::ofstream::app);
    log << logCounter << ") " << text << std::endl;
    log.close();
    logCounter++;
}

// erases the previous log file
void DebugLog::reset() {
    std::ofstream log("debug/log.txt", std::ofstream::out);
    log << "";
    log.close();
}
