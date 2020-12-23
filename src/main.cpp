#include "MainControlLoop.hpp"

void setup(){
    MainControlLoop mcl = MainControlLoop();
    delay(2000);
    while(true){
        mcl.execute();
    }
}

void loop(){}