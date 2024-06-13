
#include "MainControlLoop.hpp" //Include variables from this file
#include "Control Tasks/PinControlTask.hpp"

MainControlLoop mcl; //Declares an instance of the class
PinControlTask pin_control_task;

//ifndef UNIT_TEST

/**
 * Initializes the setup for the program.
 *
 * This function sets up the serial communication with different baud rates.
 * It writes the `constants::gps::SetCfgNav5` array to the `Serial2` port.
 * Then it executes the `pin_control_task` and waits for 2000 milliseconds.
 * 
 * @return void
 */
void setup(){
    Serial.begin(9600);
    Serial2.begin(constants::gps::baud);
    Serial7.begin(constants::rockblock::baud);

    Serial2.write((unsigned char *)&constants::gps::SetCfgNav5, sizeof(constants::gps::SetCfgNav5));
    pin_control_task.execute();  
    delay(2000);
}
//Notes: This line of code is writing the contents of the SetCfgNav5 array from the constants::gps namespace to the Serial2 port. 
//The Serial2.write() function takes two arguments: a pointer to the data to be written ((unsigned char *)&constants::gps::SetCfgNav5) 
//and the size of the data in bytes (sizeof(constants::gps::SetCfgNav5)).

/**
 * Executes the main control loop.
 *
 * This function calls the `execute()` method of the `mcl` object, which
 * represents the main control loop. This loop is responsible for executing
 * the control tasks in the program.
 *
 * @throws None
 */
void loop(){
    mcl.execute();
}
//endif


