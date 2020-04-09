#include "include/openbreath.h"

ESC OpenBreath::esc( OB_ESC_PIN );
BreathingEngine OpenBreath::engine( OpenBreath::esc );
bool OpenBreath::run_motor = true;
char input_char = 0;

void OpenBreath::Init()
{
    OB_TERMINAL_SERIAL.begin( OB_TERMINAL_BAUD_RATE );
    engine.Init();
    Terminal::SetReturnCallback( &ParseCommand );
    Terminal::SetOutputCallback( &TerminalPrint );
    #ifdef OB_WAIT_FOR_SERIAL
    while(!OB_TERMINAL_SERIAL.available()>0);
    #endif
    #ifdef OB_PRINT_WELCOME
    Terminal::PrintWelcome();
    #endif
}

void OpenBreath::MainLoop()
{
    if(OB_TERMINAL_SERIAL.available())
    {
        input_char = OB_TERMINAL_SERIAL.read();
        if(input_char == OB_HOOK_CHAR && run_motor)
            OpenBreath::Hook();
        Terminal::AddCharacter(input_char);
    }
    else if( run_motor )
    {
        Terminal::log("\n\rRunning %s pattern", OB_DEFAULT_PATTERN.name );
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

void OpenBreath::ReleaseTerminal()
{
    Terminal::log("Terminal will now be released. OpenBreath will now resume with default pattern.\n");
    run_motor = true;
}

void OpenBreath::Hook()
{
    if( !run_motor )
    {
        Terminal::log("Terminal already hooked\n");
    }
    else
    {
        run_motor = false;
        StopMotor();
        Terminal::PrintWelcome();
        Terminal::Reset();
    }
}

void OpenBreath::DefaultPatternInfo()
{
    Terminal::log(
        "Name: %s\n\rCycle A: Speed %d%%, Time: %d\n\rCycle B: Speed %d%%, Time: %d\n",
        OB_DEFAULT_PATTERN.name,
        OB_DEFAULT_PATTERN.speed_a,
        OB_DEFAULT_PATTERN.time_a,
        OB_DEFAULT_PATTERN.speed_b,
        OB_DEFAULT_PATTERN.time_b
    );
}

void OpenBreath::StopMotor()
{
    Terminal::log( "Stopping motor...\n" );
    engine.GetESC().Stop();
}

void OpenBreath::SetMotorSpeed()
{
    Terminal::log("Motor speed: ");
    Terminal::SetReturnCallback( &SetMotorSpeed );
}

void OpenBreath::SetMotorSpeed( const char * msg )
{
    uint8_t speed = atoi(msg);
    engine.GetESC().SetSpeed(speed > 100 ? 100 : speed);

    Terminal::log("Setting motor speed to %u%%\n", speed);
    Terminal::SetReturnCallback( &ParseCommand );
}