#pragma once

#include "Arduino.h"

#include "params.h"
#include "callbacks.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>

class Terminal
{
public:
    static void SetReturnCallback( VoidCharStrCallback callback );
    static void RunReturnCallback();
    
    static void AddCharacter( char c );
    static void SetOutputCallback( VoidCharStrCallback callback );

    static String GetBuffer();

    static void Reset( void );
    static void ResetInputBuffer( void );
    static void ResetOutputBuffer( void );

    static void log( const char * format, ... );

    static void PrintWelcome( void );

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