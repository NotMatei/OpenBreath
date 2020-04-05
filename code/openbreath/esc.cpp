#include "include/esc.h"

ESC::ESC(uint16_t pin):
    pin(pin)
{}

ESC::ESC( const ESC & esc )
{
    pin = esc.pin;
    is_init = esc.is_init;
    servo = esc.servo;
}

void ESC::Init()
{
    if(is_init)
        servo.detach();
    
    servo.attach( pin );
    servo.write( init_command );
    delay( init_wait );
    Stop();
    
    is_init = true;
}

bool ESC::SetSpeed( uint16_t speed )
{
    return SetRawSpeed(
        map(speed, min_speed, max_speed, min_raw_speed, max_raw_speed)
    );
}
bool ESC::SetRawSpeed( uint16_t speed )
{
    if(!is_init)
        return false;
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