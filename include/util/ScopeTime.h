#include <iostream>
#include <string>
#include <sys/time.h>
class ScopeTime{
public:
    ScopeTime( const std::string& task ):mTask(task){
        gettimeofday( &mBeginTime, NULL );
    }
    ~ScopeTime(){
        struct timeval endTime;
        gettimeofday( &endTime, NULL );
        // std::cout << "start_s:" << mBeginTime.tv_sec << "  start_us:" << mBeginTime.tv_usec << " \n";
        // std::cout << "end_s:" << endTime.tv_sec << " end_us:" << endTime.tv_usec << " \n";
        std::cout << mTask <<" cost: " 
                  << (endTime.tv_sec-mBeginTime.tv_sec)*1000000 + (endTime.tv_usec - mBeginTime.tv_usec)
                  << " us" << std::endl;
    }
private:
    std::string mTask;
    struct timeval mBeginTime;
};