#pragma once

#include "Arduino.h"

#include "esc.h"

struct PatternElement
{
    uint8_t speed;
    int time;
};

class BreathingEngine
{
public:
    //Class in charge of executing breathing
    //petterns via an ESC.
    BreathingEngine( ESC & esc ):
        esc(esc){};
    
    //Initializes the ESC
    void Init(); 

    //Runs the pattern described in "pattern":
    //  It sets the speed to speed_a first, and remains there for time_a
    //  milliseconds. It then moves on to speed_b, where it remains there
    //  for time_b milliseconds.
    bool RunPattern( PatternElement pattern[2] );

    ESC & GetESC();
    
private:
    ESC esc;    
};