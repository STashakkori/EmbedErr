#ifndef LOG_H
#define LOG_H

#include <fstream>

class Logger {
public:
    Logger() {
        logFilePath = "log.txt";
    }

    template <typename... Args>
    void log(Args&&... args) {
        std::ofstream outputFile(logFilePath, std::ios::app);
        if (outputFile.is_open()) {
            ((outputFile << std::forward<Args>(args)), ...);
            outputFile << std::endl;
        }
        else { std::cerr << "Log could not open output file." << std::endl; }
    }

    void clear() {
        std::ofstream outputFile(logFilePath, std::ios::out);
        if (outputFile.is_open()) {
            outputFile << "";  // Write an empty string to clear
        }
        else { std::cerr << "Log could not open file." << std::endl; }
    }

private:
    std::string logFilePath;
};

#endif