#include "include/openbreath.h"

ESC OpenBreath::esc( OB_ESC_PIN );
BreathingEngine OpenBreath::engine( OpenBreath::esc );
bool OpenBreath::serial_connected = false;

void OpenBreath::Init()
{
    OB_TERMINAL_SERIAL.begin( OB_TERMINAL_BAUD_RATE );
    Terminal::SetReturnCallback( &ParseCommand );
    Terminal::SetOutputCallback( &TerminalPrint );
    #ifdef OB_WAIT_FOR_SERIAL
    for(uint8_t i = 0; i < OB_SERIAL_WAIT_TIME; i++)
    {
        if(OB_TERMINAL_SERIAL.available())
        {
            serial_connected = true;
            break;
        }
        delay(1);
    }
    #endif
    #ifdef OB_PRINT_WELCOME
    Terminal::PrintWelcome();
    #endif
    Terminal::Reset();
}

void OpenBreath::MainLoop()
{
    if( serial_connected )
    {
        if(OB_TERMINAL_SERIAL.available())
        {
            Terminal::AddCharacter(OB_TERMINAL_SERIAL.read());
        }
    }
    else
    {
        engine.RunPattern( OB_DEFAULT_PATTERN );
    }
}

void OpenBreath::TerminalPrint( const char * msg )
{
    OB_TERMINAL_SERIAL.print( msg );
}

void OpenBreath::ParseCommand( const char * msg )
{
    for(uint8_t i = 0; commands[i].command != NULL; i++)
    {
        if(strcmp(msg, commands[i].command) == 0)
            (*commands[i].callback)();
    }
}

void OpenBreath::PrintHelp()
{
    for(uint8_t i = 0; commands[i].command != NULL; i++)
    {
        Terminal::log("\r%s: %s\n", commands[i].command, commands[i].description);
    }
}