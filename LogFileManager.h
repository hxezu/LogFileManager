#pragma once
#include"logger.h"
#include<fstream>
#include<cassert>
#define LOG_SIZE 10
#define CURRENT_DATE 100

//static int count=0;

class LogFileManager{
private:
    int count = 0;
    //int count;
    string print_info[LOG_SIZE];
    Logger* log_manager[LOG_SIZE]={NULL};
public:
    LogFileManager();
    ~LogFileManager();
    void PlusLog(int loge_type, int loge_mode);
    void Play();
    void ChangeDate(int num);
    int getCount();
};