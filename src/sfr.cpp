#include "sfr.hpp"
#include "constants.hpp"
 
namespace sfr{
    namespace gps{
        float altitude = 0.0;
    }
    namespace photoresistor{
        bool covered = true;
    } 
    namespace mission{
        mission_mode_type mode = mission_mode_type::ascent;
    }
    namespace burnwire{
        bool on = false;
    }
    namespace camera{
        bool photo_taken = false;
        bool take_photo = false;
    }
    namespace rockblock{
        uint8_t fault_report[70] = {0};
        uint8_t old_fault_report[70] = {2};
        size_t fault_report_size = sizeof(fault_report);
    }
}