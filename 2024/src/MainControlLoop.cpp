#include "MainControlLoop.hpp"

//Constructor for the main control loop class. Intializes various member variables using values from constants::timecontrol
MainControlLoop::MainControlLoop()
    : ControlTask<void>(),
    clock_manager(constants::timecontrol::control_cycle_time),
    camera_report_monitor(constants::timecontrol::camera_report_monitor_offset),
    command_monitor(constants::timecontrol::command_monitor_offset),
    normal_report_monitor(constants::timecontrol::normal_report_monitor_offset),
    photoresistor_monitor(constants::timecontrol::photoresistor_monitor_offset),
    temperature_monitor(constants::timecontrol::temperature_monitor_offset),
    burnwire_control_task(constants::timecontrol::burnwire_control_task_offset),
    camera_control_task(constants::timecontrol::camera_control_task_offset),
    rockblock_control_task(constants::timecontrol::rockblock_control_task_offset),
    mission_manager(constants::timecontrol::mission_manager_offset),
    video_control_task(constants::timecontrol::rockblock_control_task_offset),
    gps_monitor(constants::timecontrol::rockblock_control_task_offset)
{
    delay(1000);
}

void MainControlLoop::execute()
{
    // camera_report_monitor.execute();
    // command_monitor.execute();
    normal_report_monitor.execute();
    photoresistor_monitor.execute();
    temperature_monitor.execute();
    gps_monitor.execute();
     //camera_control_task.execute();
    rockblock_control_task.execute();
    //burnwire_control_task.execute(); 

     //mission_manager.execute();
 

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
  

