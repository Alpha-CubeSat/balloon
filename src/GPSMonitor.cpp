#include "GPSMonitor.hpp"

GPSMonitor::GPSMonitor(HardwareSerial ser):
    hwSer(ser){
    hwSer.begin(constants::gps::baud);
}

void GPSMonitor::execute(){
    if(Serial2.available() > 0){
        uint8_t GPSchar = hwSer.read();
        gps.encode(GPSchar);
        sfr::gps::altitude = gps.altitude.meters();
    }
}