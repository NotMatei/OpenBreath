#include "include/esc.h"

ESC esc(9);

void setup()
{
    esc.Init();
    esc.SetSpeed(50);
}

void loop()
{}