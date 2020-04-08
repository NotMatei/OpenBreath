#pragma once

#include "Arduino.h"

#include "stdio.h"
#include "stdlib.h"

#include "params.h"

#include "utils.h"
#include "version.h"
#include "terminal.h"
#include "breathing.h"
#include "esc.h"

class OpenBreath
{
public:
    OpenBreath( void );

    void Init();
    void MainLoop( void );

    struct Command
    {
        const char * command;
        VoidCallback callback;
    };

private:
    static void TerminalPrint( const char * msg );
    static void ParseCommand( const char * msg );

    ESC esc;
    BreathingEngine engine;

    Version version;
    
    static constexpr VoidCharStrCallback 
        terminal_on_return  = &ParseCommand,
        terminal_output     = &TerminalPrint;
};