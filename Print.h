#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <sstream>

#define MAX_ARGS 10

class Printer {
public:
    template <typename... Args>
    void print(Args&&... args) {
        if constexpr (sizeof...(Args) > MAX_ARGS) { return; }

        std::ostringstream oss;
        ((oss << std::forward<Args>(args)), ...);

        std::cout << oss.str() << std::endl;

        if constexpr (sizeof...(Args) >= MAX_ARGS) {
            return; // Return when maximum number of arguments
        }
    }
};

#endif
