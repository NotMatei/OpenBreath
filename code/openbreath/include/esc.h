#pragma once

#include "Arduino.h"
#include "Servo.h"

class ESC
{
public:
    ESC(uint16_t pin);
   
    void Init();

    void SetSpeed( uint16_t speed );

    void Stop();
    
private:
    uint16_t pin;
    Servo servo;
    static constexpr uint16_t 
        init_command    = 30,
        init_wait       = 3000,
        stop_command    = 10,
        max_speed       = 100,
        min_speed       = 0,
        max_raw_speed   = 180,
        min_raw_speed   = 63;
};