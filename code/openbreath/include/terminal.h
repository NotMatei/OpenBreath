#pragma once

#include "Arduino.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define TERMINAL_DEBUG

namespace Terminal
{
    typedef void (*VoidCallback)( void );

    class Command
    {
    public:
        Command::Command( String name, VoidCallback callback ):
            callback( callback ), name(name) {}
        Command( const Command & command );

        bool IsCommand( String command );
        void Run();

    private:
        String name;
        VoidCallback callback   = nullptr;
    };

    class Controller
    {
    public:
        Controller( size_t amount, Command * commands, VoidCallback default_command );
        ~Controller();

        void AddCharacter( char c );

    private:
        void ProcessCommand();
        static constexpr size_t
            buffer_size             = 100;
        static constexpr char
            end_char                = '\r',
            nl_char                 = '\n';

        char buffer[buffer_size]    = {0};

        size_t
            buffer_index            = 0,
            command_list_size       = 0;

        Command ** command_buffer   = nullptr;

        VoidCallback 
            default_command         = nullptr;
        
        //Internal use only
        bool command_is_valid;
    };
}