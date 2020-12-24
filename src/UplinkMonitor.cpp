#include "UplinkMonitor.hpp"

UplinkMonitor::UplinkMonitor():
    rockblock(Serial1, constants::rockblock::sleep_pin){
    Serial1.begin(19200);
    rockblock.setPowerProfile(IridiumSBD::DEFAULT_POWER_PROFILE);
    delay(1000);
    rockblock.begin();
}

void UplinkMonitor::execute(){
    if(rockblock.getWaitingMessageCount() > 0){
        rockblock.sendReceiveSBDBinary(sfr::rockblock::send_buffer, sfr::rockblock::send_size, sfr::rockblock::receive_buffer, sfr::rockblock::receive_size);
        if(sizeof(sfr::rockblock::receive_buffer) == constants::rockblock::command_size){
            char str[constants::rockblock::command_size + 1];
            str[constants::rockblock::command_size] = '\0';
            for (int i = 0; i < constants::rockblock::command_size; i++){
                str[i] = sfr::rockblock::receive_buffer[i];
            }
            String command_string(str);
            int comma_index = command_string.indexOf(",");
            int excl_index = command_string.indexOf("!");
            if(comma_index != -1 and excl_index != -1){
                int opcode = command_string.substring(0, comma_index).toInt();
                int argument = command_string.substring(comma_index + 1, excl_index).toInt();
                if(opcode == 1){
                    sfr::mission::mode = mission_mode_type::deploy_lightsail;
                }
            }
        }
    }

}