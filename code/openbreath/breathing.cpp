#include "include/breathing.h"

void BreathingEngine::Init()
{
    esc.Init();
}

bool BreathingEngine::RunPattern( PatternElement * pattern, size_t size )
{
    if(!esc.IsReady())
        return false;
    for( size_t i = 0; i < size; i++ )
    {
        esc.SetSpeed( pattern[i].speed );
        delay( pattern[i].time );
    }
    return true;
}

ESC & BreathingEngine::GetESC()
{
    return esc;
}
