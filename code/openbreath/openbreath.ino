#include "Servo.h"

class ESC
{
public:
    //Controls brushless motor ESC
    ESC(uint16_t pin);

    //ESC copy constructor
    ESC( const ESC & esc );
   
    //Sends init_command to ESC and waits for init_wait
    //milliseconds. It also sets is_init to true. It
    //needs to be called before using any other 
    //functions that talk to the ESC in any way.
    void Init();

    //Set's the speed of the motor. Works in percentage
    //from 0% to 100%. Returns true if Init was called
    //before, false if otherweise.
    bool SetSpeed( uint16_t speed );

    //Handler for Servo::write()
    bool SetRawSpeed( uint16_t speed );

    //Sends stop_command to ESC. Returns true if Init 
    //was called before, false if otherweise.
    bool Stop();

    //Returns the value of is_init.
    bool IsReady();
    
private:
    uint16_t pin;
    Servo servo;
    static constexpr uint16_t 
        init_command    = 30,
        init_wait       = 3000,
        stop_command    = 10,
        max_speed       = 100,
        min_speed       = 0,
        max_raw_speed   = 180,
        min_raw_speed   = 63;
    bool is_init = false;    
};

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

#define ESC_PIN 9
#define BUTTON_PIN 8
#define MOTOR_SPEED 20

ESC esc(ESC_PIN);

void setup()
{ 
    esc.Init();
    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
   static bool should_run = false;
   bool input = digitalRead(BUTTON_PIN);
   if(should_run != input)
   {
	if(should_run)
	    esc.SetSpeed(MOTOR_SPEED);
	else
	    esc.SetSpeed(0);
	should_run = input;
   }
}
