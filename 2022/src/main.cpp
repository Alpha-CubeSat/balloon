
#include "MainControlLoop.hpp"
#include "Control Tasks/PinControlTask.hpp"

MainControlLoop mcl;
PinControlTask pin_control_task;

//ifndef UNIT_TEST
void setup(){
    Serial.begin(9600);
    Serial2.begin(constants::gps::baud);
    Serial4.begin(constants::rockblock::baud);

    Serial2.write((unsigned char *)&constants::gps::SetCfgNav5, sizeof(constants::gps::SetCfgNav5));
    pin_control_task.execute();  
    delay(2000);
}

void loop(){
    mcl.execute();
}
//endif


