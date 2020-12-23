#ifndef SFR_HPP_
#define SFR_HPP_

#include "mission_mode_type.enum"
 
namespace sfr{
    namespace gps{
        extern float altitude;
    }
    namespace photoresistor{
        extern bool covered;
    } 
    namespace mission{
        extern mission_mode_type mode;
    }
    namespace burnwire{
        extern bool on;
    }
    namespace camera{
        extern bool photo_taken;
        extern bool take_photo;
    }
    namespace rockblock{
        extern uint8_t tx_data;
        extern size_t tx_data_size;
        extern uint8_t rx_data;
        extern size_t rx_data_size;
    }
};

#endif