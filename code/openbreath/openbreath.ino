#include "include/esc.h"

ESC esc(D4);

void setup()
{
    esc.Init();
    esc.SetSpeed(40);
}

void loop()
{}
