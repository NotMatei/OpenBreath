#include "include/breathing.h"

using namespace Breathing;

void Engine::Init()
{
    esc.Init();
}

bool Engine::RunPattern( PatternElement * pattern, size_t size )
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

ESC & Engine::GetESC()
{
    return esc;
}
