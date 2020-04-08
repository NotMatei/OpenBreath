#pragma once

#include "Arduino.h"

#include "version.h"
#include "params.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

typedef void (*VoidCallback)( void );
typedef void (*VoidCharStrCallback)( const char * );

class Terminal
{
public:
    static void SetReturnCallback( VoidCharStrCallback callback );
    static void RunReturnCallback();
    
    static void AddCharacter( char c );
    static void SetOutputCallback( VoidCharStrCallback callback );

    static String GetBuffer();

    static void Reset();
    static void ResetInputBuffer();
    static void ResetOutputBuffer();

    static void log( const char * format, ... );

    static void PrintWelcome( Version & version);

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
    
    static VoidCharStrCallback 
        input_callback,
        output_callback;
        
    static size_t buffer_index;
};