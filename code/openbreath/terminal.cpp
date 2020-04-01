#include "include/terminal.h"

static char 
    Terminal::out_buffer[buffer_size]               = {0},
    Terminal::in_buffer[buffer_size]                = {0};
    
static VoidCallback Terminal::input_callback        = nullptr;
static VoidStringCallback Terminal::output_callback = nullptr;

static size_t Terminal::buffer_index                = 0;

void Terminal::SetReturnCallback( VoidCallback callback )
{
    input_callback = callback;
}

void Terminal::RunReturnCallback()
{
    (*input_callback)();
}

void Terminal::AddCharacter( char c )
{
    if( buffer_index >= buffer_size - 2 || c == end_char || c == nl_char )
    {
        RunReturnCallback();
        ResetInputBuffer();
    }
    else
    {
        if(c == back_char && buffer_index > 0)
        {
            buffer_index--;
            in_buffer[buffer_index] = 0;
            printf("\r%s%s \033[1D", shell_s, in_buffer);
        }
        else
        {
            if(c == back_char)
                printf(" ");
            in_buffer[buffer_index] = c;
            printf("%c", c);
            buffer_index++;
        }
    }
}

void Terminal::SetOutputCallback( VoidStringCallback callback )
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
    printf("\n\r%s", shell_s);
}

void Terminal::ResetOutputBuffer()
{
    memset( out_buffer, 0, buffer_size );
}

void Terminal::printf( const char * format, ... )
{
    if(output_callback == nullptr)
        return;
        
    ResetOutputBuffer();

    va_list arg;
    va_start( arg, format );

    vsnprintf( out_buffer, buffer_size-1, format, arg );

    va_end(arg);

    (*output_callback)( out_buffer );
}