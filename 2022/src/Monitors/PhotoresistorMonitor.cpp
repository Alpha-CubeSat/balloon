#include "PhotoresistorMonitor.hpp"

PhotoresistorMonitor::PhotoresistorMonitor(unsigned int offset): TimedControlTask<void>(offset){}

void PhotoresistorMonitor::execute(){
    int val = analogRead(constants::photoresistor::pin);
    std::cout << "Photoresistor value is: " << val << std::endl;
    if(val > constants::photoresistor::light_val){
        sfr::photoresistor::covered = false;
    }
    else{
        sfr::photoresistor::covered = true;
    }
}