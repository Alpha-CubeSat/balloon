#include "PhotoresistorMonitor.hpp"

PhotoresistorMonitor::PhotoresistorMonitor(){}

void PhotoresistorMonitor::execute(){
    int val = analogRead(constants::photoresistor::pin);
    sfr::photoresistor::covered = val < constants::photoresistor::light_val; 
}