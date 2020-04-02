#pragma once

#include "Arduino.h"

#include "esc.h"

namespace Breathing
{
    struct PatternElement
    {
        uint8_t speed;
        int time;
    };

    class Engine
    {
    public:
        //Class in charge of executing breathing
        //petterns via an ESC.
        Engine( ESC & esc ):
            esc(esc){};
        
        //Initializes the ESC
        void Init(); 

        //Runs the pattern described in "pattern":
        //  It sets the speed to speed_a first, and remains there for time_a
        //  milliseconds. It then moves on to speed_b, where it remains there
        //  for time_b milliseconds.
        bool RunPattern( PatternElement * pattern, size_t size );

        ESC & GetESC();
        
    private:
        ESC esc;    
    };
}