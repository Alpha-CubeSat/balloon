#ifndef SFR_HPP_
#define SFR_HPP_

#include "Arduino.h"
#include "Modes/mission_mode_type.enum"
#include "Modes/rockblock_mode_type.enum"
#include "Modes/burnwire_mode_type.enum"
#include "Control Tasks/BurnwireControlTask.hpp"
#include "RockblockSimulator.hpp"
#include "constants.hpp"
#include "MissionManager.hpp"
#include <SD.h>
#include <Adafruit_VC0706.h>
#include <TinyGPS.h>
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <numeric>

namespace sfr
{
    namespace time
    {
        extern float start_time;
    }
    namespace photoresistor
    {
        extern bool covered;
    }
    namespace mission
    {
        extern mission_mode_type mode;
        extern int cycle_start;
    }
    namespace burnwire
    {
        extern burnwire_mode_type mode;
        extern int attempts;
        extern int start_time;
        extern int camera_attempts;
        extern int burn_time;
    }
    namespace camera
    {
        extern bool photo_taken_sd_failed;
        extern bool take_photo;
        extern bool turn_on;
        extern bool turn_off;
        extern bool powered;
        extern uint8_t buffer[255];
        extern int current_serial;
        extern int fragment_number;
        extern int fragment_number_requested;
        extern int serial_requested;
        extern bool fragment_requested;
        extern int images_written;
        extern int fragments_written;
        extern int image_lengths[255];
        extern bool report_ready;
        extern bool full_image_written;
        extern bool report_downlinked;
        extern char filename[15];
        extern uint16_t jpglen;
    }
    namespace rockblock
    {
        extern unsigned long last_communication;
        extern bool sleep_mode; //ADDED
        extern bool last_downlink_normal;
        extern int camera_commands[99][constants::rockblock::command_len];
        extern int camera_max_fragments[99];
        extern int camera_num_fragments;
        extern bool downlink_camera;
        extern unsigned long last_downlink;
        extern unsigned long downlink_period;
        extern unsigned long camera_downlink_period;
        extern rockblock_mode_type mode;
        extern bool waiting_message;
        extern char buffer[constants::rockblock::buffer_size];
        extern uint8_t report[constants::rockblock::packet_size];
        extern uint8_t camera_report[constants::rockblock::packet_size];
        extern int commas[constants::rockblock::num_commas];
        extern uint8_t opcode[2];
        extern uint8_t arg_1[4];
        extern uint8_t arg_2[4];
#ifndef SIMULATOR
        // extern HardwareSerial serial;
#else
        extern RockblockSimulator serial;
#endif
        extern bool flush_status;
        extern bool waiting_command;
        extern size_t conseq_reads;
        extern uint16_t f_opcode;
        extern uint32_t f_arg_1;
        extern uint32_t f_arg_2;
        extern int timeout;
        extern int start_time;
        extern bool last_timed_out;
        extern int num_downlinks;
    }
    namespace gps
    {
        extern float altitude;
        extern std::deque<float> altitude_buffer;
        extern float altitude_average;
        extern float latitude;
        extern std::deque<float> latitude_buffer;
        extern float latitude_average;
        extern float longitude;
        extern std::deque<float> longitude_buffer;
        extern float longitude_average;
        extern bool new_data;
    }
    namespace temperature {
        extern float temp1_c_value;
        extern float temp1_f_value;
        extern float temp2_c_value;
        extern float temp2_f_value;
        extern float voltage1;
        extern float voltage2;
    } 
};

#endif