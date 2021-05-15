#ifndef TEMPERATURE_MONITOR_HPP_
#define TEMPERATURE_MONITOR_HPP_

#include "sfr.hpp"
#include "constants.hpp"
#include "Control Tasks/TimedControlTask.hpp"

class TemperatureMonitor : public TimedControlTask<void>{
    public:
        TemperatureMonitor(unsigned int offset);
        void execute();
};

#endif