#include "include/breathing.h"

using namespace Breathing;

Pattern::Pattern( const Pattern & pattern )
{
    speed_a = pattern.speed_a;
    time_a  = pattern.time_a;
    speed_b = pattern.speed_b;
    time_b  = pattern.time_b;
}

void Engine::Init()
{
    if(!esc.IsReady())
    {
        esc.Init();
    }
}

bool Engine::RunPattern( Pattern & pattern )
{
    if(!esc.IsReady())
        return false;
    esc.SetSpeed( pattern.speed_a );
    delay( pattern.time_a );
    esc.SetSpeed( pattern.speed_b );
    delay( pattern.time_b );
    return true;
}
