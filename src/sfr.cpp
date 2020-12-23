#include "sfr.hpp"
 
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
        uint8_t tx_data = {0};
        size_t tx_data_size = 0;
        uint8_t rx_buffer = 0;
    }
}