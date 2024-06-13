#ifndef PIN_CONTROL_TASK_HPP_ //Checks if identifier has been defined
#define PIN_CONTROL_TASK_HPP_ //Defines a macro. Can be used later in the code to replace the text PIN_CONTROL_TASK_HPP_ with empty string ''.

#include "sfr.hpp"

class PinControlTask{ 
    public:
        PinControlTask();
        void execute();       
};

#endif