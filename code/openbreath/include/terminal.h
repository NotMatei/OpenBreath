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
        //The name of Command is the name used when checking
        //the command against user input. The callback
        //must be used with void functions with no parameters
        //(as defined by VoidCallback).
        Command::Command( String name, VoidCallback callback ):
            callback( callback ), name(name) {}
        
        //Command's copy constructor
        Command( const Command & command );

        //Returns true if this->name == command
        bool IsCommand( String command );

        //Runs the callback function defined in the
        //constructor. If it was set to nullptr, it will do
        //nothing.
        void Run();

    private:
        String name;
        VoidCallback callback   = nullptr;
    };

    class Controller
    {
    public:
        //"amounts" represents the amount of commands passed in 
        //the "commands" array. "default_callback" is the 
        //function to be called whenever the command parsed was
        //not found.
        Controller( size_t amount, Command * commands, VoidCallback default_command );

        //Frees command_buffer and children.
        ~Controller();

        //Adds character to "buffer". It calls ProcessComamnd
        //whenever any of the scape commands is detected
        //or the "buffer" has been filled.
        void AddCharacter( char c );

    private:
        //Checks the buffer against the commands from
        //command_buffer. Runs the command if a match was
        //found and runs default_command otherwise.
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