#include"logger.h"
#include"LogFileManager.h"

int main(){
    LogFileManager manager;
    manager.PlusLog(LOG_ERROR,MODE_ALL);
    manager.PlusLog(LOG_DEBUG,MODE_FILE);
    manager.PlusLog(LOG_WARNING,MODE_ALL);
    manager.PlusLog(LOG_WARNING,MODE_ALL);
    manager.PlusLog(LOG_ERROR,MODE_ALL);
    manager.PlusLog(LOG_DEBUG,MODE_FILE);
    manager.PlusLog(LOG_WARNING,MODE_ALL);
    manager.PlusLog(LOG_WARNING,MODE_ALL);
    manager.PlusLog(LOG_ERROR,MODE_ALL);
    manager.PlusLog(LOG_DEBUG,MODE_FILE);
    manager.PlusLog(LOG_WARNING,MODE_FILE);
    manager.PlusLog(LOG_WARNING,MODE_PRINT);
    manager.ChangeDate(3);
    manager.Play();
    //cout<<manager.getCount()<<endl;

    return 0;
}
