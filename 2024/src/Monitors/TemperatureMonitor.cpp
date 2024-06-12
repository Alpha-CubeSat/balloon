#include "TemperatureMonitor.hpp"

TemperatureMonitor::TemperatureMonitor()
{
}

void TemperatureMonitor::execute()
{   
    //set voltage
    sfr::temperature::voltage = (((analogRead(constants::temperature::pin) * constants::sensor::voltage_ref) / constants::sensor::resolution));
    
    //set temp_c_value
    sfr::temperature::temp_c_value = ( sfr::temperature::voltage - 0.5) * 100;

    //set temp_f_value
    sfr::temperature::temp_f_value = (sfr::temperature::temp_c_value * 9 / 5) + 32;
}