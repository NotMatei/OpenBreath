#include "include/openbreath.h"

OpenBreath::OpenBreath( void ):
    esc( OB_ESC_PIN ),
    engine( esc ),
    version(
        OB_MAJOR_VER,
        OB_MINOR_VER,
        OB_DECORATOR,
        OB_BUILD_DATE
    )
{}

void OpenBreath::Init()
{
    OB_TERMINAL_SERIAL.begin( OB_TERMINAL_BAUD_RATE );
    Terminal::SetReturnCallback( terminal_on_return );
    Terminal::SetOutputCallback( terminal_output );
    Terminal::Reset();
    #ifdef OB_WAIT_FOR_SERIAL
    while(!OB_TERMINAL_SERIAL.available());
    #endif
    #ifdef OB_PRINT_WELCOME
    Terminal::PrintWelcome( version );
    #endif
}

void OpenBreath::MainLoop()
{
    if(OB_TERMINAL_SERIAL.available())
    {
        Terminal::AddCharacter(OB_TERMINAL_SERIAL.read());
    }
}

void OpenBreath::TerminalPrint( const char * msg )
{
    OB_TERMINAL_SERIAL.println( msg );
}

void OpenBreath::ParseCommand( const char * msg )
{
    Terminal::log( "\n\r%s", msg );
}