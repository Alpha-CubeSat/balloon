#include "PhotoresistorMonitor.hpp"

PhotoresistorMonitor::PhotoresistorMonitor(){}

void PhotoresistorMonitor::execute(){
    int val = analogRead(constants::photoresistor::pin);
    if(val > constants::photoresistor::light_val){//TODO determine accurate light val
        sfr::photoresistor::covered = false;
    }
    else{
        sfr::photoresistor::covered = true;
    }
    /*
    delay(1000);
    Serial.print(covered);
    */
    
}