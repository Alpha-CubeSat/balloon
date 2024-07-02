#include "MissionManager.hpp"

MissionManager::MissionManager()//Constructor, among others, called in MainControlLoop.cpp. 
{
    transition_to_standby();//Sets the initial state of MissionManager

    sfr::time::start_time = millis(); //The millis() function returns the number of milliseconds since the program started. So this sets start time to the time when MissionManager is called.
}

void MissionManager::execute() //Called in MainControlLoop.cpp as well.
{
    mission_mode_type mode = sfr::mission::mode; //mission_mode_type is an enum class. So mode can only be whatever is in that enum class. mode is intialized as standby.

    switch (mode) //Switch statement checks the value of mode and executes different code blocks based on its value. 
    {
    case mission_mode_type::standby: //If mode is standby, then execute dispatch_standby() etc etc. Dispatch functions make several checks to decide whether to transition to another mode. Once transitioned, dispatch_(that new state) will be called.
        dispatch_standby();
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
    if ((millis() - sfr::time::start_time) >= constants::burnwire::fail_safe_deploy || sfr::gps::altitude_average > constants::gps::mand_deploy)
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
    if ((millis() - sfr::time::start_time) >= constants::burnwire::fail_safe_deploy || sfr::gps::altitude_average > constants::gps::mand_deploy)
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
    Serial.print("Transitioning to Standby");
    sfr::mission::mode = mission_mode_type::standby;
    sfr::rockblock::downlink_period = constants::time::one_second*30; //CHANGED FOR TESTING
    sfr::rockblock::camera_downlink_period = constants::time::one_second*30;
}

void MissionManager::transition_to_deployment()
{
    Serial.print("Transitioning to Deployment");
    sfr::camera::turn_off = true;
    sfr::mission::mode = mission_mode_type::deployment;
    sfr::rockblock::downlink_period = constants::time::one_minute;
    sfr::rockblock::camera_downlink_period = constants::time::one_minute;
}

void MissionManager::transition_to_high_altitude()
{
    Serial.print("Transitioning to High Altitude");
    sfr::rockblock::downlink_period = constants::time::one_minute;
    sfr::rockblock::camera_downlink_period = constants::time::one_minute;
    sfr::mission::mode = mission_mode_type::high_altitude;
}

void MissionManager::transition_to_post_deployment()
{
    Serial.print("Transitioning to Post-Deployment");
    sfr::rockblock::downlink_period = constants::time::five_minutes;
    sfr::rockblock::camera_downlink_period = constants::time::five_minutes;
    sfr::mission::mode = mission_mode_type::post_deployment;
}