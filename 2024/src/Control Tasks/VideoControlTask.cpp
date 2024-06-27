#include "VideoControlTask.hpp"

VideoControlTask::VideoControlTask(){
    pinMode(constants::video::pin, OUTPUT);
    digitalWrite(constants::video::pin, HIGH);
}

void VideoControlTask::execute(){    
    if(millis() - sfr::time::start_time > constants::video::four_hours){
        digitalWrite(constants::video::pin, LOW);
    } else{
        digitalWrite(constants::video::pin, HIGH);
    }
}