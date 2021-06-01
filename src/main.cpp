#include "MainControlLoop.hpp"
#include "Control Tasks/PinControlTask.hpp"

MainControlLoop mcl;
PinControlTask pin_control_task;

void setup(){
    //delay for 2 hours
    //delay(7200000);
    pin_control_task.execute();
    delay(2000);
    
}

void loop(){
    mcl.execute();
}



