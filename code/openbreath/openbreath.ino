#include "include/terminal.h"

void print( String msg )
{
    Serial.print(msg);
}

void on_return()
{
    String input = Terminal::GetBuffer();
    if(input == "And you can have commands")
    {
        Terminal::printf("\n\r********Like this one!********");
    }
}

void setup()
{
    Serial.begin( 115200 );
    Terminal::SetReturnCallback( &on_return );
    Terminal::SetOutputCallback( &print );
    while(!Serial.available());
    Terminal::Reset();
    while (1)
    {
        if(Serial.available())
        {
            Terminal::AddCharacter(Serial.read());
        }
    }
    
}

void loop()
{
}
