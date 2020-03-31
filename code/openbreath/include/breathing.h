#pragma once

#include "Arduino.h"

#include "esc.h"

namespace Breathing
{
    class Pattern
    {
    public:
        Pattern( uint16_t speed_a, uint16_t time_a, uint16_t speed_b, uint16_t time_b ):
            speed_a(speed_a), time_a(time_a), speed_b(speed_b), time_b(time_b){};
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
        Engine( ESC & esc ):
            esc(esc){};
        void Init(); 
        bool RunPattern( Pattern & pattern );
    private:
        ESC esc;    
    };
}