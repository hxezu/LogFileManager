#include "logger.h"

Logger::Logger(){
    this->log_type = LOG_ERROR;
    this->mode = MODE_ALL;
    this->log_data="";
    this->log_alldata="";
    this->file_name="";
    log_create();
}

Logger::Logger(int log_type, int mode ):log_type(log_type){
    if(log_type==LOG_DEBUG) this->mode = MODE_FILE;
    else if (log_type==LOG_EVENT) this->mode = MODE_PRINT;
    else    this->mode = mode;
    this->log_data="";
    this->log_alldata="";
    this->file_name="";
    log_create();
}


void Logger::createFilename(string current_time){
    string tmp;
    for(int i=0; i<4;i++){
        tmp+=current_time.at(i);
    }
    tmp+="년";
    for(int j=4 ; j<6 ; j++){
        tmp+=current_time.at(j);
    }
    tmp+="월";
    for(int z=6 ; z<8 ; z++){
        tmp+=current_time.at(z);
    }
    tmp+="일.txt";
    this->file_name = tmp;
}

void Logger::log_create(){
    string current_time = getTimestamp();
    log_alldata += current_time+":";
    createFilename(current_time);
    log_alldata = log_alldata+"["+file_name+"]";

    if(this->log_type==LOG_EVENT){
        log_alldata +="[LogFileManager.cpp: 20]";
    }else log_alldata +="[logger.cpp: 19]";

    switch(this->log_type){
        case(LOG_ERROR): this->log_alldata+="-error"; break;
        case(LOG_DEBUG): this->log_alldata+="-debug"; break;
        case(LOG_WARNING): this->log_alldata+="-warning"; break;
        case(LOG_EVENT): this->log_alldata+="-event"; break;
    }


    if(mode==MODE_ALL){
        log_data = log_alldata;
    }
    else if(mode==MODE_PRINT){
        log_data = log_alldata;
        string some="x";
        log_alldata = some;
    }
    else if(mode==MODE_FILE){
        log_data = "x";
    }

}

string Logger::getLog_data(){
    return this->log_data;
}

string Logger::getLog_Alldata(){
    return this->log_alldata;
}

string Logger::getMilliseconds(){
    struct timeval time_now{};
    gettimeofday(&time_now, nullptr);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

    char result[4];
    string tmp = to_string(msecs_time);
    int i=tmp.size()-1;
    int z = 3;
    for(i ; i >= (tmp.size()-5); i--){
        result[z--] = tmp.at(i);
    }
    string allresult = result;

    return allresult;
}

string Logger::getTimestamp()
{
    string result="";
    time_t currentSec = time(NULL);
    tm *t = localtime(&currentSec);
    ostringstream oss;
    oss.clear();
    oss << t->tm_year+1900;
    switch(t->tm_mon)
    {
        case(0): oss << "01"; break;
        case(1): oss << "02"; break;
        case(2): oss << "03"; break;
        case(3): oss << "04"; break;
        case(4): oss << "05"; break;
        case(5): oss << "06"; break;
        case(6): oss << "07"; break;
        case(7): oss << "08"; break;
        case(8): oss << "09"; break;
        case(9): oss << "10"; break;
        case(10): oss << "11"; break;
        case(11): oss << "12"; break;
    }
    oss << setfill('0') << setw(2) << t->tm_mday ;
    oss << setfill('0') << setw(2) << t->tm_hour;
    oss << setfill('0') << setw(2) << t->tm_min;
    result += oss.str();
    result += getMilliseconds();
    return result;
}

string Logger::getFilename(){
    return this->file_name;
}

void Logger::Print_Log(){
    cout <<this->log_alldata <<endl;
    cout <<this->log_data <<endl;
}

int Logger::getLogType(){
    return this->log_type;
}

int Logger::getMode(){
    return this->mode;
}

void Logger::setLogAlldata(string s){
    this->log_alldata = s;
}

