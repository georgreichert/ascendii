#include "../headers/debuglog.h"

void DebugLog::log(std::string text) {
    static int logCounter = 0;
    std::ofstream log("debug/log.txt", std::ofstream::app);
    log << logCounter << ") " << text << std::endl;
    log.close();
    logCounter++;
}

void DebugLog::reset() {
    std::ofstream log("debug/log.txt", std::ofstream::out);
    log << "";
    log.close();
}
