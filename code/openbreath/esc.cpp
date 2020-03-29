#include "include/esc.h"

ESC::ESC(int pin):
    pin(pin)
{
    servo.attach( pin );
}

void ESC::Init()
{
    servo.write( init_value );
    delay( init_wait );
    SetSpeed( init_speed );
}

void ESC::SetSpeed( int speed )
{
    speed = map(speed, 0, 100, 0, 180);
    for(int i = 0; i < speed; i += increase_value)
    {
        SetRawSpeed( i );
        delay( increase_delay );
    }
    SetRawSpeed( speed );
}

void ESC::SetRawSpeed( int speed )
{
    servo.write( speed );
}