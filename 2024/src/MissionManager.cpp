#include "MissionManager.hpp"

MissionManager::MissionManager(unsigned int offset) : TimedControlTask<void>(offset) //Constructor, among others, called in MainControlLoop.cpp. Offset defined in Constants.cpp.
{
    transition_to_standby();//Sets the initial state of MissionManager

    sfr::timer::start_time = millis(); //The millis() function returns the number of milliseconds since the program started. So this sets start time to the time when MissionManager is called.
}

void MissionManager::execute() //Called in MainControlLoop.cpp as well.
{
    mission_mode_type mode = sfr::mission::mode; //mission_mode_type is an enum class. So mode can only be whatever is in that enum class. mode is intialized as standby.

    switch (mode) //Switch statement checks the value of mode and executes different code blocks based on its value. 
    {
    case mission_mode_type::standby: //If mode is standby, then execute dispatch_standby() etc etc. Dispatch functions make several checks to decide whether to transition to another mode. Once transitioned, dispatch_(that new state) will be called.
        //dispatch_standby();
        break;
    case mission_mode_type::high_altitude:
        dispatch_high_altitude(); 
        break;
    case mission_mode_type::deployment:
        dispatch_deployment();
        break;
    case mission_mode_type::post_deployment:
        dispatch_post_deployment();
        break;
    }
}

void MissionManager::dispatch_standby()
{
    if ((millis() - sfr::timer::start_time) >= constants::timer::fail_safe_deploy || sfr::gps::altitude_average > constants::gps::mand_deploy)
    {
        transition_to_deployment();
    }
    else if (sfr::gps::altitude_average > constants::gps::high_altitude)
    {
        transition_to_high_altitude();
    }
}

void MissionManager::dispatch_high_altitude()
{
    if ((millis() - sfr::timer::start_time) >= constants::timer::fail_safe_deploy || sfr::gps::altitude_average > constants::gps::mand_deploy)
    {
        transition_to_deployment();
    }
}

void MissionManager::dispatch_deployment()
{
    if (!sfr::photoresistor::covered)
    {
        sfr::camera::take_photo = true;
        BurnwireControlTask::transition_to_standby(); 
        transition_to_post_deployment();
    }
    else if (sfr::burnwire::attempts > constants::burnwire::max_attempts)
    {
        transition_to_post_deployment();
    }
}

void MissionManager::dispatch_post_deployment() {}

void MissionManager::transition_to_standby()
{
    sfr::mission::mode = mission_mode_type::standby;
    sfr::rockblock::downlink_period = constants::rockblock::five_minutes;
    sfr::rockblock::camera_downlink_period = constants::rockblock::five_minutes;
}

void MissionManager::transition_to_deployment()
{
    sfr::camera::turn_off = true;
    sfr::mission::mode = mission_mode_type::deployment;
    sfr::rockblock::downlink_period = constants::rockblock::one_minute;
    sfr::rockblock::camera_downlink_period = constants::rockblock::one_minute;
}

void MissionManager::transition_to_high_altitude()
{
    sfr::rockblock::downlink_period = constants::rockblock::one_minute;
    sfr::rockblock::camera_downlink_period = constants::rockblock::one_minute;
    sfr::mission::mode = mission_mode_type::high_altitude;
}

void MissionManager::transition_to_post_deployment()
{
    sfr::rockblock::downlink_period = constants::rockblock::five_minutes;
    sfr::rockblock::camera_downlink_period = constants::rockblock::five_minutes;
    sfr::mission::mode = mission_mode_type::post_deployment;
}