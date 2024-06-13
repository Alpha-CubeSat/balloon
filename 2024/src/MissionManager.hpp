#ifndef MISSION_MANAGER_HPP_
#define MISSION_MANAGER_HPP_

#include "sfr.hpp"
#include "constants.hpp"
#include "Control Tasks/TimedControlTask.hpp"

// Declares a class named MissionManager that is derived from the TimedControlTask<void> class using public inheritance.
// Suggests that MissionManager is a task that involves time control. 
class MissionManager : public TimedControlTask<void> 
{
public:
    MissionManager(unsigned int offset); //offset is a variable in TimedControlTask.hpp
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