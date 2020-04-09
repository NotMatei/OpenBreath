#pragma once

#include "Arduino.h"

#include "stdio.h"
#include "stdlib.h"

#include "params.h"

#include "terminal.h"
#include "callbacks.h"
#include "breathing.h"
#include "patterns.h"
#include "esc.h"

struct Command
{
    const char * command;
    const char * description;
    VoidCallback callback;
};


class OpenBreath
{
public:
    static void Init();
    static void MainLoop( void );

    static ESC esc;
    static BreathingEngine engine;

private:
    static void TerminalPrint( const char * msg );
    static void ParseCommand( const char * msg );

    static void PrintHelp( void );
    static void ReleaseTerminal( void );
    static void Hook( void );
    static void DefaultPatternInfo( void );
    static void StopMotor( void );

    static bool run_motor;


    static Command commands[];
};