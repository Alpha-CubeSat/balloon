#include "MainControlLoop.hpp"

MainControlLoop::MainControlLoop()
    : ControlTask<void>(),
    clock_manager(constants::timecontrol::control_cycle_time),
    camera_report_monitor(constants::timecontrol::camera_report_monitor_offset),
    command_monitor(constants::timecontrol::command_monitor_offset),
    normal_report_monitor(constants::timecontrol::normal_report_monitor_offset),
    photoresistor_monitor(constants::timecontrol::photoresistor_monitor_offset),
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
    gps_monitor.execute();
    Serial.println("altitude:"+ String(sfr::gps::altitude));
    Serial.println("average:"+ String(sfr::gps::altitude_average));
    
    Serial.println("longitude:"+ String(sfr::gps::longitude));
    Serial.println("average:"+ String(sfr::gps::longitude_average));

    Serial.println("latitude:"+ String(sfr::gps::latitude));
    Serial.println("average:"+ String(sfr::gps::latitude_average));
        /*
   burnwire_control_task.execute();
       */
    mission_manager.execute();
}