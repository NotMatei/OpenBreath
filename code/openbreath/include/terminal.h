#pragma once

#include "Arduino.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

typedef void (*VoidCallback)( void );
typedef void (*VoidStringCallback)( String );

class Terminal
{
public:
    static void SetReturnCallback( VoidCallback callback );
    static void RunReturnCallback();
    
    static void AddCharacter( char c );
    static void SetOutputCallback( VoidStringCallback callback );

    static String GetBuffer();
    static void Reset();
    static void ResetInputBuffer();
    static void ResetOutputBuffer();

    static void printf( const char * format, ... );

private:
    static constexpr size_t
        buffer_size             = 100;
    static constexpr char
        end_char                = '\r',
        nl_char                 = '\n',
        back_char               = 8;
    static constexpr char *
        shell_s                 = "$ ";

    static char 
        out_buffer[buffer_size],
        in_buffer[buffer_size];
    static VoidCallback input_callback;
    static VoidStringCallback output_callback;
    static size_t buffer_index;
};