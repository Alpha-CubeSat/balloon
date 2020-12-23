#include "UplinkMonitor.hpp"

UplinkMonitor::UplinkMonitor():
    rockblock(Serial1, constants::rockblock::sleep_pin){
    Serial1.begin(19200);
    rockblock.setPowerProfile(IridiumSBD::DEFAULT_POWER_PROFILE);
    rockblock.begin();
}

void UplinkMonitor::execute(){
    if(rockblock.getWaitingMessageCount() > 0){
        rockblock.sendReceiveSBDBinary(sfr::rockblock::tx_data, sfr::rockblock::tx_data_size, sfr::rockblock::rx_buffer, sfr::rockblock::rx_buffer_size);
    }

}