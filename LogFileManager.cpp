#include"LogFileManager.h"

LogFileManager::LogFileManager(){}

LogFileManager::~LogFileManager(){
    for (int i = 0; i < LOG_SIZE; i++) {
        delete log_manager[i];
        log_manager[i] = { NULL };
    }
}

void LogFileManager::PlusLog(int loge_type, int loge_mode){
    if(count < LOG_SIZE-1){
        if(log_manager[count]==nullptr){
            log_manager[count] = new Logger(loge_type, loge_mode);
            this->print_info[count++] +=log_manager[count]->getLog_data();
        }
        else{
            log_manager[count] = nullptr;
            this->print_info[count] = "";
            log_manager[count] = new Logger(loge_type, loge_mode);
            this->print_info[count++] +=log_manager[count]->getLog_data();
        }
    }
    else{
        log_manager[count] = new Logger(LOG_EVENT, MODE_ALL);
        this->print_info[count] +=log_manager[count]->getLog_data();
        log_manager[count]->setLogAlldata(this->print_info[count]);
        count = 0;
        this->print_info[count] = "";
        log_manager[count] = nullptr;
        log_manager[count] = new Logger(loge_type, loge_mode);
        this->print_info[count++] +=log_manager[count]->getLog_data();
    }
}

void LogFileManager::Play(){
    for(int z=0; z<LOG_SIZE ; z++){
        if(this->print_info[z]!="x")
            cout<<this->print_info[z]<<endl;
    }

    for(int i=0 ; i < LOG_SIZE ; i++){
        ofstream ostr;
        ostr.open(log_manager[i]->getFilename(), ios::app);
        if(!ostr){
            cout << "파일 생성에 실패하였습니다.";
            assert(false);
        }
        if(log_manager[i]->getLog_Alldata()!="x")
            ostr<<log_manager[i]->getLog_Alldata()+"\n";
        ostr.close();
    }

}

void LogFileManager::ChangeDate(int num){
    int number = num-1;
    Logger logg(log_manager[number]->getLogType(),log_manager[number]->getMode());
    this->print_info[number] = logg.getLog_data();
    log_manager[number]->setLogAlldata(logg.getLog_Alldata());
}

int LogFileManager::getCount(){
    return count;
}






