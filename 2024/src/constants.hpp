#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

namespace constants
{
    namespace time
    {
        constexpr unsigned long one_second = 1000;
        constexpr unsigned long one_minute = 60 * one_second;
        constexpr unsigned long ten_minutes = 10 * one_minute;
        constexpr unsigned long five_minutes = 5 * one_minute;

        constexpr int control_cycle_time_ms = 10;
    }
    namespace photoresistor
    {
        constexpr int pin = 22;
        constexpr int light_val = 700; //increased light val for natural light enviornment, this value will need to be determined
    }
    namespace burnwire
    {
        constexpr int pin = 30;
        constexpr int burn_wait = 500;
        constexpr int max_attempts = 10;
        constexpr int burn_time = 200;
        constexpr int fail_safe_deploy = time::one_second; 
    }
    namespace rockblock
    {
        constexpr int sleep_pin = 29;

        constexpr int min_sleep_period = 2 * time::one_minute;
        constexpr int max_same_mode = 10 * time::one_minute / time::control_cycle_time_ms;
        constexpr int min_downlink_period = time::one_second;
        constexpr int max_downlink_period = time::ten_minutes;

        constexpr int baud = 19200;
        constexpr size_t buffer_size = 63;
        constexpr size_t packet_size = 70;
        constexpr size_t num_commas = 5;
        constexpr size_t max_iter = 200;
        constexpr size_t num_commands = 4;
        constexpr size_t opcode_len = 2;
        constexpr size_t arg1_len = 4;
        constexpr size_t arg2_len = 4;
        constexpr size_t command_len = opcode_len + arg1_len + arg2_len;
        constexpr size_t max_conseq_read = 3;

        constexpr int num_initial_downlinks = 2;

        constexpr uint8_t mission_mode[opcode_len] = {0x00, 0x00};
        constexpr uint8_t rockblock_downlink_period[opcode_len] = {0x01, 0x00};
        constexpr uint8_t request_image_fragment[opcode_len] = {0x02, 0x00};

        constexpr uint8_t standby[arg1_len] = {0x00, 0x00, 0x00, 0x00};
        constexpr uint8_t high_altitude[arg1_len] = {0x01, 0x00, 0x00, 0x00};
        constexpr uint8_t deployment[arg1_len] = {0x02, 0x00, 0x00, 0x00};
        constexpr uint8_t post_deployment[arg1_len] = {0x03, 0x00, 0x00, 0x00};

        constexpr uint8_t true_arg[arg1_len] = {0x01, 0x00, 0x00, 0x00};
        constexpr uint8_t false_arg[arg1_len] = {0x00, 0x00, 0x00, 0x00};

        constexpr uint8_t active[arg1_len] = {0x01, 0x00, 0x00, 0x00};
        constexpr uint8_t inactive[arg1_len] = {0x00, 0x00, 0x00, 0x00};

        constexpr uint8_t no_arg_2[arg2_len] = {0x00, 0x00, 0x00, 0x00};

        constexpr uint8_t mission_mode_high_altitude[command_len] = {
            mission_mode[0], mission_mode[1],
            high_altitude[0], high_altitude[1], high_altitude[2], high_altitude[3],
            no_arg_2[0], no_arg_2[1], no_arg_2[2], no_arg_2[3]};

        constexpr uint8_t mission_mode_deployment[command_len] = {
            mission_mode[0], mission_mode[1],
            deployment[0], deployment[1], deployment[2], deployment[3],
            no_arg_2[0], no_arg_2[1], no_arg_2[2], no_arg_2[3]};

        constexpr uint8_t mission_mode_standby[command_len] = {
            mission_mode[0], mission_mode[1],
            standby[0], standby[1], standby[2], standby[3],
            no_arg_2[0], no_arg_2[1], no_arg_2[2], no_arg_2[3]};

        constexpr uint8_t mission_mode_post_deployment[command_len] = {
            mission_mode[0], mission_mode[1],
            post_deployment[0], post_deployment[1], post_deployment[2], post_deployment[3],
            no_arg_2[0], no_arg_2[1], no_arg_2[2], no_arg_2[3]};

        constexpr int known_commands[num_commands][command_len] = {
            {mission_mode_deployment[0], mission_mode_deployment[1], mission_mode_deployment[2], mission_mode_deployment[3], mission_mode_deployment[4], mission_mode_deployment[5], mission_mode_deployment[6], mission_mode_deployment[7], mission_mode_deployment[8], mission_mode_deployment[9]},
            {mission_mode_standby[0], mission_mode_standby[1], mission_mode_standby[2], mission_mode_standby[3], mission_mode_standby[4], mission_mode_standby[5], mission_mode_standby[6], mission_mode_standby[7], mission_mode_standby[8], mission_mode_standby[9]},
            {mission_mode_high_altitude[0], mission_mode_high_altitude[1], mission_mode_high_altitude[2], mission_mode_high_altitude[3], mission_mode_high_altitude[4], mission_mode_high_altitude[5], mission_mode_high_altitude[6], mission_mode_high_altitude[7], mission_mode_high_altitude[8], mission_mode_high_altitude[9]},
            {mission_mode_post_deployment[0], mission_mode_post_deployment[1], mission_mode_post_deployment[2], mission_mode_post_deployment[3], mission_mode_post_deployment[4], mission_mode_post_deployment[5], mission_mode_post_deployment[6], mission_mode_post_deployment[7], mission_mode_post_deployment[8], mission_mode_post_deployment[9]}};
    }
    namespace camera
    {
        constexpr int content_length = 64;
        constexpr int bytes_allocated_serial_opcode = 2;
        constexpr int bytes_allocated_fragment = 4;
    }
    namespace gps
    {
        constexpr int baud = 9600; 
        constexpr int TXPin = 8;
        constexpr int RXPin =7;
        constexpr int mand_deploy = 28000;
        constexpr int high_altitude = 20000;
        const unsigned char SetCfgNav5[] = {0xB5, 0x62, 0x06, 0x24, 0x24, 0x00, 0x01, 0x01,
                                            0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x27,
                                            0x00, 0x00, 0x05, 0x00, 0xFA, 0x00, 0xFA, 0x00,
                                            0x64, 0x00, 0x2C, 0x01, 0x00, 0x3C, 0x00, 0x00,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x00, 0x00, 0x56, 0x76};
        constexpr uint8_t CheckNav[] = {0xB5, 0x62, 0x06, 0x24, 0x00, 0x00, 0x2A, 0x84};
        constexpr float min_altitude_average = 0;
        constexpr float max_altitude_average = 35000;
        constexpr float min_longitude_average = -77.6088;
        constexpr float max_longitude_average = -75.9180;
        constexpr float min_latitude_average = 42.0987;
        constexpr float max_latitude_average = 43.156;
    }
    namespace sensor
    {
        constexpr int collect = 3;
        constexpr int resolution = 1023;
        constexpr float voltage_ref = 3.3;

    }
    namespace temperature {
        constexpr int pin1 = A16;
        constexpr int pin2 = A17;
        constexpr int min_temp_c = -100;
        constexpr int max_temp_c = 200;
        constexpr int min_temp_f = -148;
        constexpr int max_temp_f = 392;
        constexpr int min_voltage = 0;
        constexpr int max_voltage = 5;
    } 
    namespace video
    {
        constexpr int pin = 2;
        constexpr int four_hours = 14400000;
    }
};

#endif