#include "include/terminal.h"
#include "include/breathing.h"

#define ESC_PIN 9

ESC esc(ESC_PIN);
Breathing::Engine engine(esc);

Breathing::PatternElement TestPattern[2] = {
    {
        .speed  = 5,
        .time   = 1000
    },
    {
        .speed  = 2,
        .time   = 1000
    },
};

void print( String msg )
{
    Serial.print(msg);
}

void on_return()
{
    String input = Terminal::GetBuffer();
    if( input == "test speed" )
    {
        Terminal::printf("Running test pattern...\n\r");
        engine.RunPattern( TestPattern, 2 );
        engine.GetESC().Stop();
        Terminal::printf("Done running test pattern\n\r");
    }
    else if( input == "stop motor" )
    {
        Terminal::printf("Stopping motor...\n\r");
        engine.GetESC().Stop();
        delay(3000);
        Terminal::printf("Motor stopped\n\r");
    }
    else if( input == "run motor" )
    {
        Terminal::printf("Setting motor speed to 10%\n\r");
        engine.GetESC().SetSpeed(10);
    }
}

void setup()
{
    Serial.begin( 115200 );
    Terminal::SetReturnCallback( &on_return );
    Terminal::SetOutputCallback( &print );
    //Let's try to leave ESC::Init() at the setup
    Terminal::printf("Initialzing ESC...\n\r");
    engine.Init();
    Terminal::printf("Done initializing ESC\n\r");
    while(!Serial.available());
    Terminal::Reset();
}

void loop()
{
    if(Serial.available())
    {
        Terminal::AddCharacter(Serial.read());
    }
}
