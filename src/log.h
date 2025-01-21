#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

// create the log file
void openLogFile();

// add new line in log file
void appendToLog(const std::string& text);

#endif // LOG_H
