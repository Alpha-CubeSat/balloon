#ifndef COMMAND_MONITOR_HPP_
#define COMMAND_MONITOR_HPP_

#include "sfr.hpp"

class CommandMonitor {
    public:
        CommandMonitor();
        void execute();
        void dispatch_change_mission_mode();
        void dispatch_change_true_false(bool& value);
        void dispatch_request_image_fragment();
        void dispatch_change_rockblock_downlink_period();
        void dispatch_change_burnwire_time();
        void dispatch_change_burnwire_timeout();
        uint16_t get_decimal_opcode(const uint8_t* hex_opcode_bytes);
        uint32_t get_decimal_arg(const uint8_t* hex_arg_bytes);
};

#endif