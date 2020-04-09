#include "include/breathing.h"

void BreathingEngine::Init()
{
    esc.Init();
}

bool BreathingEngine::RunPattern( const Pattern &pattern )
{
    if(!esc.IsReady())
        return false;
    
    esc.SetSpeed( pattern.speed_a );
    delay( pattern.time_a );
    esc.SetSpeed( pattern.speed_b );
    delay( pattern.time_b );

    return true;
}

ESC & BreathingEngine::GetESC()
{
    return esc;
}
