#include "include/terminal.h"

char 
    Terminal::out_buffer[buffer_size]           = {0},
    Terminal::in_buffer[buffer_size]            = {0};
    
VoidCharStrCallback Terminal::input_callback     = nullptr;
VoidCharStrCallback Terminal::output_callback    = nullptr;

size_t Terminal::buffer_index                   = 0;

void Terminal::SetReturnCallback( VoidCharStrCallback callback )
{
    input_callback = callback;
}

void Terminal::RunReturnCallback()
{
    (*input_callback)(in_buffer);
}

void Terminal::AddCharacter( char c )
{
    if( buffer_index >= buffer_size - 2 || c == end_char || c == nl_char )
    {
        log("\n\r");
        RunReturnCallback();
        ResetInputBuffer();
    }
    else
    {
        if(c == back_char && buffer_index > 0)
        {
            buffer_index--;
            in_buffer[buffer_index] = 0;
            log("\r%s%s \033[1D", shell_s, in_buffer);
        }
        else
        {
            if(c == back_char)
                printf(" ");
            in_buffer[buffer_index] = c;
            log("%c", c);
            buffer_index++;
        }
    }
}

void Terminal::SetOutputCallback( VoidCharStrCallback callback )
{
    output_callback = callback;
}

String Terminal::GetBuffer()
{
    return in_buffer;
}

void Terminal::Reset()
{
    ResetInputBuffer();
    ResetOutputBuffer();
}

void Terminal::ResetInputBuffer()
{
    buffer_index = 0;
    memset( in_buffer, 0, buffer_size );
    log("%s", shell_s);
}

void Terminal::ResetOutputBuffer()
{
    memset( out_buffer, 0, buffer_size );
}

void Terminal::log( const char * format, ... )
{
    if(output_callback == nullptr)
        return;
        
    ResetOutputBuffer();

    va_list arg;
    va_start( arg, format );
    
    vsnprintf( out_buffer+1, buffer_size-2, format, arg );

    va_end(arg);

    (*output_callback)( out_buffer );
}

void Terminal::PrintWelcome( Version &version )
{
    log( 
        "\n\rOpenBreath %s"
        "\n\rCopyright (C) 2020 Matei Dima, Jose Ricardo Monegro" 
        "\n\rAll rights reserved."
        "\n\rLicensed under the X license\n", 
        version.c_string()
    );
}