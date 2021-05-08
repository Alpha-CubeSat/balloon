#include "CommandMonitor.hpp"

CommandMonitor::CommandMonitor(){}

void CommandMonitor::execute(){
    if(sfr::rockblock::waiting_command == true){
        switch(sfr::rockblock::opcode_p){
            case 1:
                Serial.println("dispatch change burnwire");
                dispatch_change_burnwire();
                break;
            case 2:
                Serial.println("dispatch change camera");
                dispatch_change_camera();
                break;
            case 3:
                Serial.println("dispatch change rockblock");
                dispatch_change_rockblock();
                break;
            case 4:
                Serial.println("dispatch change mission");
                dispatch_change_mission();
                break;
            case 5:
                Serial.println("dispatch change video");
                dispatch_change_video();
                break;
        }
        sfr::rockblock::waiting_command = false;
        sfr::rockblock::opcode_p = 0;
        sfr::rockblock::arg_1_p = 0;
        sfr::rockblock::arg_2_p = 0;
    }
}

void CommandMonitor::dispatch_change_burnwire(){
    sfr::burnwire::fire = sfr::rockblock::arg_1_p;
    sfr::mission::mode = mission_mode_type::deployment;
    Serial.print("Setting fire command to: ");
    Serial.println(sfr::rockblock::arg_1_p);
    Serial.println(sfr::burnwire::fire);
}

void CommandMonitor::dispatch_change_camera(){
    sfr::camera::take_photo = sfr::rockblock::arg_1_p;
    Serial.print("Setting take command to: ");
    Serial.println(sfr::rockblock::arg_1_p);
    Serial.println(sfr::camera::take_photo);

}

void CommandMonitor::dispatch_change_rockblock(){
    switch(sfr::rockblock::arg_1_p){
        case 0:
            sfr::rockblock::downlink_period = constants::rockblock::one_minute * sfr::rockblock::arg_2_p;
            Serial.print("Setting downlink period to: ");
            Serial.println(constants::rockblock::one_minute * sfr::rockblock::arg_2_p);
            break;
        case 1:
            sfr::rockblock::downlink_period = constants::rockblock::one_minute / sfr::rockblock::arg_2_p;
            Serial.print("Setting downlink period to: ");
            Serial.println(constants::rockblock::one_minute / sfr::rockblock::arg_2_p);
            break;
    }
}

void CommandMonitor::dispatch_change_mission(){
    switch(sfr::rockblock::arg_1_p){
        case 0:
            sfr::mission::mode = mission_mode_type::standby;
            sfr::rockblock::downlink_period = constants::rockblock::five_minutes;
            Serial.print("Change mission mode to standby");
            //MissionManager::transition_to_standby();
            break;
        case 1:
            sfr::mission::mode = mission_mode_type::awaiting_uplink;
            sfr::rockblock::downlink_period = constants::rockblock::one_minute;
            Serial.print("Change mission mode to uplink");
            //MissionManager::transition_to_awaiting_uplink();
            break;
        case 2:
            sfr::mission::mode = mission_mode_type::deployment;
            sfr::burnwire::fire = true;
            Serial.print("Change mission mode to deployment");
            //MissionManager::transition_to_standby();
            break;
    }
}

void CommandMonitor::dispatch_change_video(){
    sfr::video::on = sfr::rockblock::arg_1_p;
    Serial.print("Change video to: ");
    Serial.println(sfr::rockblock::arg_1_p);
    Serial.println(sfr::video::on);
}