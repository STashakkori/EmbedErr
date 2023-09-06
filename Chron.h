#ifndef CHRON_H
#define CHRON_H

#include <chrono>
#include <ctime>

class Chron {
public:
    static std::chrono::system_clock::time_point getCurrentTime() {
        return std::chrono::system_clock::now();
    }

    static std::string timeToString(
                           const std::chrono::system_clock::time_point& tp) {
        std::time_t time = std::chrono::system_clock::to_time_t(tp);
        std::tm tm_struct;

    #ifdef _WIN32
        gmtime_s(&tm_struct, &time);
    #else
        std::gmtime_r(&time, &tm_temp);
    #endif

        std::ostringstream oss;
        oss << std::put_time(&tm_struct, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    static std::time_t toTimeT(
                    const std::chrono::system_clock::time_point& timePoint) {
        return std::chrono::system_clock::to_time_t(timePoint);
    }
};

#endif