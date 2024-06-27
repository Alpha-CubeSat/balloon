#include "NormalReportMonitor.hpp"

NormalReportMonitor:: NormalReportMonitor() {}

void NormalReportMonitor::execute()
{
    //Serial.print("alt: "); Serial.print(sfr::gps::altitude_average); Serial.println(" m");
    //Serial.print("long: "); Serial.print(sfr::gps::longitude_average); Serial.println(" deg");
    //Serial.print("lat: "); Serial.print(sfr::gps::latitude_average); Serial.println(" deg");
    uint8_t downlink_period = map(sfr::rockblock::downlink_period, constants::rockblock::min_downlink_period, constants::rockblock::max_downlink_period, 0, 255);
    uint8_t altitude = map(sfr::gps::altitude_average, constants::gps::min_altitude_average, constants::gps::max_altitude_average, 0, 255);
    uint8_t longitude = map(sfr::gps::longitude_average, constants::gps::min_longitude_average, constants::gps::max_longitude_average, 0, 255);
    uint8_t latitude = map(sfr::gps::latitude_average, constants::gps::min_latitude_average, constants::gps::max_longitude_average, 0, 255);
    uint8_t temperature_c = map(sfr::temperature::temp1_c_value, constants::temperature::min_temp_c, constants::temperature::max_temp_c, 0, 255);
    uint8_t temperature_f = map(sfr::temperature::temp1_f_value, constants::temperature::min_temp_f, constants::temperature::max_temp_f, 0, 255);
    uint8_t temperature_voltage = map(sfr::temperature::voltage1, constants::temperature::min_voltage, constants::temperature::max_voltage, 0, 255); //min=0 and max=5.
    //Serial.print("mapped alt: "); Serial.println(altitude);
    //Serial.print("mapped long: "); Serial.println(longitude);
    //Serial.print("mapped lat: "); Serial.println(latitude);
    sfr::rockblock::report[0] = 21;
    sfr::rockblock::report[1] = altitude; 
    sfr::rockblock::report[2] = longitude; 
    sfr::rockblock::report[3] = latitude; 
    sfr::rockblock::report[4] = sfr::photoresistor::covered;
    sfr::rockblock::report[5] = (uint8_t)sfr::mission::mode;
    sfr::rockblock::report[6] = (uint8_t)sfr::burnwire::mode;
    sfr::rockblock::report[7] = sfr::burnwire::attempts;
    sfr::rockblock::report[8] = downlink_period;
    sfr::rockblock::report[9] = temperature_c;
   //sfr::rockblock::report[10] = temperature_f;
    /*
    Serial.println("Normal Report: ");
    Serial.println("-----------------------------------------");
    Serial.print("Tag: ");
    Serial.println(sfr::rockblock::report[0]);
    Serial.print("Alititude: ");
    Serial.println(sfr::rockblock::report[1]);
    Serial.print("Longitude: ");
    Serial.println(sfr::rockblock::report[2]);
    Serial.print("Latitude: ");
    Serial.println(sfr::rockblock::report[3]);
    Serial.print("Covered: ");
    Serial.println(sfr::rockblock::report[4]);
    Serial.print("Mode: ");
    Serial.println(sfr::rockblock::report[5]);
    Serial.print("Burnwire mode: ");
    Serial.println(sfr::rockblock::report[6]);
    Serial.print("Burn wire attempts: ");
    Serial.println(sfr::rockblock::report[7]);
    Serial.print("Downlink Period: ");
    Serial.println(sfr::rockblock::report[8]);
    Serial.print("Temperature(°C): ");
    Serial.println(sfr::rockblock::report[9]);
    */
    
}