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

class Loger {
    public:
        Loger();
        void logError(string value);
        void logInfo(string value);
        void logExtendedInfo(vector<string> value);
        void openLog();
        ~Loger();
    private:
        ofstream logFile;
        string getTimestamp();
};