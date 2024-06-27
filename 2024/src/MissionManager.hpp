#ifndef MISSION_MANAGER_HPP_
#define MISSION_MANAGER_HPP_

#include "sfr.hpp"
#include "constants.hpp"

// Declares a class named MissionManager that is derived from the TimedControlTask<void> class using public inheritance.
// Suggests that MissionManager is a task that involves time control. 
class MissionManager 
{
public:
    MissionManager();
    void execute();
    void dispatch_standby();
    void dispatch_deployment();
    void dispatch_high_altitude();
    void dispatch_post_deployment();

    static void transition_to_standby();
    static void transition_to_high_altitude();
    static void transition_to_deployment();
    static void transition_to_post_deployment();
};

#endif