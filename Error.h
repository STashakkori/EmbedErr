#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <memory>
#include "Chron.h"
#include "Print.h"
#include "Log.h"

class Error {
public:
	const uint16_t errorCode;
	const std::string objectID;
	std::chrono::system_clock::time_point timestamp;

	Error(const uint16_t code, const std::string id, 
		                     std::chrono::system_clock::time_point timestamp)
		: errorCode(code), objectID(id), timestamp(timestamp) {}

	void print(void) {
		Printer errorPrinter;
		errorPrinter.print("Error: code: ", errorCode);
		errorPrinter.print("         id: ", objectID);
		errorPrinter.print("       time: ", Chron::timeToString(timestamp));
	};

	void log(void) {
		Logger errorLogger;
		errorLogger.log("Error: code: ", errorCode);
		errorLogger.log("         id: ", objectID);
		errorLogger.log("       time: ", Chron::timeToString(timestamp));
	};
};

#endif