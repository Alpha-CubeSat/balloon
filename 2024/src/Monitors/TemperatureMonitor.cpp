#include "TemperatureMonitor.hpp"

TemperatureMonitor::TemperatureMonitor(unsigned int offset): TimedControlTask<void>(offset){}

void TemperatureMonitor::execute()
{   /*
    Serial.print(sfr::temperature::temp2_c_value);
    Serial.println("C");
    Serial.print(sfr::temperature::temp2_f_value);
    Serial.println("F");
    delay(500);
    */

    //set voltage
    sfr::temperature::voltage1 = (((analogRead(constants::temperature::pin1) * constants::sensor::voltage_ref) / constants::sensor::resolution));
    sfr::temperature::voltage2 = (((analogRead(constants::temperature::pin2) * constants::sensor::voltage_ref) / constants::sensor::resolution));
    
    //set temp_c_value
    sfr::temperature::temp1_c_value = ( sfr::temperature::voltage1 - 0.5) * 100;
    sfr::temperature::temp2_c_value = ( sfr::temperature::voltage2 - 0.5) * 100;

    //set temp_f_value
    sfr::temperature::temp1_f_value = (sfr::temperature::temp1_c_value * 9 / 5) + 32;
    sfr::temperature::temp2_f_value = (sfr::temperature::temp2_c_value * 9 / 5) + 32;
}