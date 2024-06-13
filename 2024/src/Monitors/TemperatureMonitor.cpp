#include "TemperatureMonitor.hpp"

TemperatureMonitor::TemperatureMonitor(unsigned int offset){}

void TemperatureMonitor::execute()
{   
    //set voltage
    sfr::temperature::voltage1 = (((analogRead(constants::temperature::pin1) * constants::sensor::voltage_ref) / constants::sensor::resolution));
    sfr::temperature::voltage2 = (((analogRead(constants::temperature::pin2) * constants::sensor::voltage_ref) / constants::sensor::resolution));
    
    //set temp_c_value
    sfr::temperature::temp_c_value1 = ( sfr::temperature::voltage1 - 0.5) * 100;
    sfr::temperature::temp_c_value2 = ( sfr::temperature::voltage2 - 0.5) * 100;

    //set temp_f_value
    sfr::temperature::temp_f_value1 = (sfr::temperature::temp_c_value1 * 9 / 5) + 32;
    sfr::temperature::temp_f_value2 = (sfr::temperature::temp_c_value2 * 9 / 5) + 32;
}