#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#define LOG_ERROR 10
#define LOG_WARNING 20
#define LOG_EVENT 30
#define LOG_DEBUG 40
#define MODE_FILE 50
#define MODE_PRINT 60
#define MODE_ALL 70


using namespace std;

class Logger{
private:
    int log_type;
    int mode;
    string log_data;
    string log_alldata;
    string file_name;
    string getMilliseconds();
    void createFilename(string current_time);
public:
    Logger();
    Logger(int log_type, int mode);
    void log_create();
    string getLog_data();
    string getLog_Alldata();
    string getFilename();
    int getLogType();
    int getMode();
    void setLogAlldata(string s);
    //void setMode(int mode);
    void Print_Log();
    string getTimestamp();
};

