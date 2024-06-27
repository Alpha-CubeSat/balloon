#include "ClockManager.hpp"

ClockManager::ClockManager()
{
}

void ClockManager::execute()
{
    cycle_time = millis() - sfr::mission::cycle_start;

    if (cycle_time < constants::time::control_cycle_time_ms) {
        delay(constants::time::control_cycle_time_ms - cycle_time);
    }
}