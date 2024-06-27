#include "GPSMonitor.hpp" //try commenting out
#include <SoftwareSerial.h>

TinyGPS gps;

GPSMonitor::GPSMonitor()
{

    //delay(1000);
}

void GPSMonitor::execute()
{
    //SoftwareSerial ss(constants::gps::RXPin, constants::gps::TXPin);
        /*
        while (Serial2.available())
        {
            //Serial.print("Serial2 Avaiable");
        }
        */

    for (unsigned long start = millis(); millis() - start < 1000;)
    {
        while (Serial2.available())
            {
                char c = Serial2.read();
                if (gps.encode(c))
                    sfr::gps::new_data = true;
            }
    }

    if (sfr::gps::new_data)
    {
        //Serial.print("LOCK");
        float flat, flon;
        gps.f_get_position(&flat, &flon);
        sfr::gps::latitude = flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat;
        sfr::gps::longitude = flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon;
        sfr::gps::altitude = gps.f_altitude() == TinyGPS::GPS_INVALID_ALTITUDE ? 0 : gps.f_altitude();

        sfr::gps::latitude_buffer.push_front(sfr::gps::latitude);
        if (sfr::gps::latitude_buffer.size() > constants::sensor::collect)
        {
            sfr::gps::latitude_buffer.pop_back();
        }
        float latitude_sum = std::accumulate(sfr::gps::latitude_buffer.begin(), sfr::gps::latitude_buffer.end(), 0.0);
        sfr::gps::latitude_average = latitude_sum / sfr::gps::latitude_buffer.size();

        sfr::gps::longitude_buffer.push_front(sfr::gps::longitude);
        if (sfr::gps::longitude_buffer.size() > constants::sensor::collect)
        {
            sfr::gps::longitude_buffer.pop_back();
        }
        float longitude_sum = std::accumulate(sfr::gps::longitude_buffer.begin(), sfr::gps::longitude_buffer.end(), 0.0);
        sfr::gps::longitude_average = longitude_sum / sfr::gps::longitude_buffer.size();

        if(sfr::gps::altitude < constants::gps::max_altitude_average){
            sfr::gps::altitude_buffer.push_front(sfr::gps::altitude);
            if (sfr::gps::altitude_buffer.size() > constants::sensor::collect)
            {
                sfr::gps::altitude_buffer.pop_back();
            }
            float altitude_sum = std::accumulate(sfr::gps::altitude_buffer.begin(), sfr::gps::altitude_buffer.end(), 0.0);
            sfr::gps::altitude_average = altitude_sum / sfr::gps::altitude_buffer.size();
        }
    }
    
}
