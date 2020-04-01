#pragma once

#include "Arduino.h"

#include "esc.h"

namespace Breathing
{
    class Pattern
    {
    public:
        //speed_x:  Speed to be maintained during x time (in ESC speed percentage 0% - 100%)
        //time_x:   x time (in milliseconds) 
        Pattern( uint16_t speed_a, uint16_t time_a, uint16_t speed_b, uint16_t time_b ):
            speed_a(speed_a), 
            time_a(time_a), 
            speed_b(speed_b), 
            time_b(time_b){};

        //Patter's copy constructor        
        Pattern( const Pattern & patter );        
        
        uint16_t
            speed_a =0,
            time_a  =0,
            speed_b =0,
            time_b  =0;
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
        bool RunPattern( Pattern & pattern );
        
    private:
        ESC esc;    
    };
}