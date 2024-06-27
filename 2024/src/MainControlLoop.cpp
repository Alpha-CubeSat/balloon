#include "MainControlLoop.hpp"

//Constructor for the main control loop class. Intializes various member variables using values from constants::timecontrol
MainControlLoop::MainControlLoop():
    clock_manager(),
    camera_report_monitor(),
    command_monitor(),
    normal_report_monitor(),
    photoresistor_monitor(),
    temperature_monitor(),
    burnwire_control_task(),
    camera_control_task(),
    rockblock_control_task(),
    mission_manager(),
    video_control_task(),
    gps_monitor()
{
    delay(1000);
}

void MainControlLoop::execute()
{
    
    sfr::mission::cycle_start = millis();
    camera_report_monitor.execute();
    // command_monitor.execute();
    normal_report_monitor.execute();
    photoresistor_monitor.execute();
    temperature_monitor.execute();
    gps_monitor.execute();
    camera_control_task.execute();
    rockblock_control_task.execute();
    //burnwire_control_task.execute(); 

    mission_manager.execute();
    clock_manager.execute();
 

}


/**
 * Notes on mission_manager object:
 * The MissionManager class has methods such as dispatch_standby(), dispatch_deployment(),
 * dispatch_high_altitude(), and dispatch_post_deployment(). These methods are responsible 
 * for transitioning the system to different mission modes based on certain conditions or events.
 * The MissionManager class also has static methods transition_to_standby(), transition_to_high_altitude(), 
 * transition_to_deployment() transition the system to a specific mission mode without going through the 
 * dispatch methods and transition_to_post_deployment(). These static methods are used to directly 
 * transition the system to a specific mission mode without going through the dispatch methods.
 */
  

