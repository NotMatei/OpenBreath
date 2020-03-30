#include "include/esc.h"

ESC::ESC(uint16_t pin):
    pin(pin)
{
    servo.attach( pin );
}

void ESC::Init()
{
    servo.write( init_value );
    delay( init_wait );
    Stop();
}

void ESC::SetSpeed( uint16_t speed )
{
    speed = map(speed, min_speed, max_speed, min_raw_speed, max_raw_speed);
    servo.write( speed );
}

void ESC::Stop()
{
    servo.write( stop_command );
}