#pragma once

#include "Arduino.h"
#include "Servo.h"

class ESC
{
public:
    ESC(int pin);
   
    void Init();
    void SetSpeed( int speed );
    void SetRawSpeed( int speed );
    
private:
    int pin;
    Servo servo;
    static constexpr int 
        increase_delay = 200,
        increase_value = 2,
        init_value = 30,
        init_wait = 3000,
        init_speed = 0;
};