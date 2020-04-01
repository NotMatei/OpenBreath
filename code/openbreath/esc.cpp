#include "include/esc.h"

ESC::ESC(uint16_t pin):
    pin(pin)
{
    servo.attach( pin );
}

ESC::ESC( const ESC & esc )
{
    pin = esc.pin;
    is_init = esc.is_init;
    servo = esc.servo;
}

void ESC::Init()
{
    servo.write( init_command );
    delay( init_wait );
    Stop();
    is_init = true;
}

bool ESC::SetSpeed( uint16_t speed )
{
    if(!is_init)
        return false;
    speed = map(speed, min_speed, max_speed, min_raw_speed, max_raw_speed);
    servo.write( speed );
    return true;
}

bool ESC::Stop()
{
    if(!is_init)
        return false;
    servo.write( stop_command );
    return true;
}

bool ESC::IsReady()
{
    return is_init;
}