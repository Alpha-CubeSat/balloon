#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#include <HardwareSerial.h>

namespace constants{
    namespace gps{
        constexpr int baud = 9600;
        constexpr int mand_deploy = 28000;
    }
    namespace photoresistor{
        constexpr int pin = 0;
        constexpr int light_val = 400;
    }
    namespace burnwire{
        constexpr int pin = 0;
    }
    namespace rockblock{
        constexpr int sleep_pin = 0;
        constexpr int baud = 19200;
        constexpr size_t rx_buffer_size = 0;
    }
};

#endif
