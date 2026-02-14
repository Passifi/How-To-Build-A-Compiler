#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
enum LoggingType {
    Error,
    Info,
    Additional,

};

struct LogEntry {
    LoggingType type;
    string value;
    time_t timestamp; 
};

class Logger {
    public:
        Logger();
        void logError(string value);
        void logInfo(string value);
        void logExtendedInfo(vector<string> value);
        void openLog();
        ~Logger();
    private:
        ofstream logFile;
        string getTimestamp();
};