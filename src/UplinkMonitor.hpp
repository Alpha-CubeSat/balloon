#ifndef UPLINK_MONITOR_HPP_
#define UPLINK_MONITOR_HPP_

#include "sfr.hpp"
#include "constants.hpp"
#include <IridiumSBD.h>
#include <Arduino.h>

class UplinkMonitor{
    public:
        UplinkMonitor();
        void execute();
        IridiumSBD rockblock;
};

#endif