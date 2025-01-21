#include "log.h"

void openLogFile() {
    std::ofstream logFile("log", std::ios::trunc);  
    if (logFile.is_open()) {
        logFile.close(); 
    } else {
        std::cerr << "Failed to open log file.\n";
    }
}

void appendToLog(const std::string& text) {
    std::ofstream logFile("log", std::ios::app);
    if (logFile.is_open()) {
        auto now = std::chrono::system_clock::now();
        auto now_t = std::chrono::system_clock::to_time_t(now);
        std::tm* now_tm = std::localtime(&now_t);

        logFile << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S") << " - " << text << "\n";
        logFile.close();
    } else {
        std::cerr << "Failed to open log file for appending.\n";
    }
}