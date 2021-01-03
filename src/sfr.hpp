#ifndef SFR_HPP_
#define SFR_HPP_

#include "mission_mode_type.enum"
#include "constants.hpp"

 
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
        extern uint8_t fault_report[70];
        extern uint8_t old_fault_report[70];
        extern size_t fault_report_size;
    }
};

#endif