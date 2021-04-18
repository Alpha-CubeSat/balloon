#include "sfr.hpp"

namespace sfr
{
    namespace photoresistor
    {
        bool covered = true;
    }
    namespace mission
    {
        mission_mode_type mode = mission_mode_type::ascent;
    }
    namespace burnwire
    {
        bool fire = false;
        burnwire_mode_type mode = burnwire_mode_type::standby;
        int attempts = 0;
        int start_time = 0;
    }
    namespace camera
    {
        bool take_photo = false;
        bool photo_taken = false;
        uint8_t buffer[255] = {0};
        uint16_t current_serial = 0;
        uint8_t fragment_number = 0;
        uint8_t max_fragments = 0;
        uint8_t data_length = 0;
        uint8_t fragment_number_requested = 3;
        uint8_t serial_requested = 0;
        bool fragment_requested = false;
        uint8_t images_written = 0;
        uint16_t image_lengths[255];
        bool report_ready = false;
        bool full_image_written = false;
        bool report_downlinked = true;
    }
    namespace rockblock
    {
        unsigned long last_downlink = 0;
        rockblock_mode_type mode = rockblock_mode_type::send_at;
        bool waiting_message = false;
        char buffer[constants::rockblock::buffer_size] = {0};
        uint8_t report[constants::rockblock::packet_size] = {0};
        int commas[constants::rockblock::num_commas] = {0};
        unsigned char data_length[4] = {0};
        unsigned char opcode[2] = {0};
        unsigned char arg_1[4] = {0};
        unsigned char arg_2[4] = {0};


        int num_iter = 0;
        bool waiting_command = false;
    }
    namespace gps
    {
        float altitude = 0.0;
    }
}