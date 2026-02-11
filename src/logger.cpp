#include "../include/Loger.h"
#include "macros.h"
Loger::Loger() {
    // get todays date as a string
    time_t timestamp;
    time(&timestamp);
    string currentTime = ctime(&timestamp);
    this->logFile = ofstream("logFile",std::ios::out);
    if(!this->logFile.is_open())  
    {
        printError("Couldn't open logfile");
    }
}

void Loger::logError(string value) {
    cout << getTimestamp() << endl;
    string completeOutput = value + " at: " + getTimestamp();
    this->logFile.write(completeOutput.c_str(), sizeof(char)*completeOutput.length());
}

string Loger::getTimestamp() {
    time_t timestamp = time(NULL);
    cout << ctime(&timestamp) << endl;
    return ctime(&timestamp);
}

Loger::~Loger() {
    this->logFile.close();
}