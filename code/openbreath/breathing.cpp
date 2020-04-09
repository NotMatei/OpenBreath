#include "include/breathing.h"

void BreathingEngine::Init()
{
    esc.Init();
}

bool BreathingEngine::RunPattern( PatternElement pattern[2] )
{
    if(!esc.IsReady())
        return false;
        
    esc.SetSpeed( pattern[0].speed );
    delay( pattern[0].time );    
    esc.SetSpeed( pattern[1].speed );
    delay( pattern[1].time );

    return true;
}

ESC & BreathingEngine::GetESC()
{
    return esc;
}
