#include "include/terminal.h"

using namespace Terminal;

Command::Command( const Command & command )
{
    name        = command.name;
    callback    = command.callback;
}

bool Command::IsCommand( String command )
{
#ifdef TERMINAL_DEBUG
    Serial.print("command: [");
    Serial.print(command);
    Serial.println("]");
    Serial.print("name: [");
    Serial.print(name);
    Serial.println("]");
#endif
    return command == name;
}

void Command::Run()
{
    if(callback != nullptr)
        (*callback)();
}

Controller::Controller( size_t amount, Command * commands, VoidCallback default_command ):
    command_list_size(amount), default_command(default_command)
{
    command_buffer = (Command **)calloc( 1, sizeof(Command*) * amount );
    for( size_t i = 0; i < amount; i++ )
        command_buffer[i] = new Command(commands[i]);
}

void Controller::AddCharacter( char c )
{
    if( buffer_index >= buffer_size - 2 || c == end_char || c == nl_char )
    {
        ProcessCommand();
        buffer_index = 0;
    }
    else
    {
        buffer[buffer_index] = c;
        buffer_index++;
    }
}

void Controller::ProcessCommand()
{
    for( size_t i = 0; i < command_list_size; i++ )
    {
        if(command_buffer[i]->IsCommand( buffer ))
        {
            command_buffer[i]->Run();
            return;
        }
    }
    if( default_command != nullptr)
    {
        (*default_command)();
    }
    memset(buffer, 0, buffer_size);
}