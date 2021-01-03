#ifndef MAIN_CONTROL_LOOP_HPP_
#define MAIN_CONTROL_LOOP_HPP_

#include "sfr.hpp"
#include "constants.hpp"
#include "GPSMonitor.hpp"
#include "PhotoresistorMonitor.hpp"
#include "MissionManager.hpp"
#include "BurnwireControlTask.hpp"
#include "CameraControlTask.hpp"
#include "RockblockControlTask.hpp"

class MainControlLoop{
    protected:
        RockblockControlTask rockblock_control_task;
        GPSMonitor gps_monitor;
        PhotoresistorMonitor photoresistor_monitor;
        
        //MissionManager mission_manager;

        BurnwireControlTask burnwire_control_task;
        CameraControlTask camera_control_task;
    
    public:
        MainControlLoop();
        void execute();
};

#endif