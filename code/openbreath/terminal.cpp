#include "include/terminal.h"

char 
    Terminal::out_buffer[buffer_size]           = {0},
    Terminal::in_buffer[buffer_size]            = {0};
    
VoidCharStrCallback Terminal::input_callback     = NULL;
VoidCharStrCallback Terminal::output_callback    = NULL;

size_t Terminal::buffer_index                   = 0;

void Terminal::SetReturnCallback( VoidCharStrCallback callback )
{
    input_callback = callback;
}

void Terminal::RunReturnCallback()
{
    if( input_callback == NULL )
        return;
    (*input_callback)(in_buffer);
}

void Terminal::AddCharacter( char c )
{
    if( buffer_index >= buffer_size - 2 || c == nl_char )
    {
        log("\n\r");
        RunReturnCallback();
        Reset();
    }
    else
    {
        if( c == back_char && buffer_index > 0 )
        {
            buffer_index--;
            in_buffer[buffer_index] = 0;
            log("\r%s%s \b", shell_s, in_buffer);
        }
        else
        {
            if( c == back_char )
                printf(" ");
            if( c >= 32 && c <= 126 )
            {
                in_buffer[buffer_index] = c;
                buffer_index++;
                log("%c", c);
            }
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
    if(output_callback == NULL)
        return;
        
    ResetOutputBuffer();

    va_list arg;
    va_start( arg, format );
    
    vsnprintf( out_buffer, buffer_size-1, format, arg );

    va_end(arg);

    (*output_callback)( out_buffer );
}

void Terminal::PrintWelcome()
{
    log( 
        "\n\rOpenBreath v%u.%u%s Built on: %s",
        OB_MAJOR_VER,
        OB_MINOR_VER,
        OB_DECORATOR,
        OB_BUILD_DATE
    );
    log( "\n\rCopyright (C) 2020 Matei Dima, Jose Ricardo Monegro" );
    log( "\n\rAll rights reserved." );
    log( "\n\rThis program is licensed under the BSD-style license found in the" );
    log( "LICENSE file in provided alongside it.\n" );
}