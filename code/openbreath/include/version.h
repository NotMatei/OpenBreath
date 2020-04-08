#pragma once

#include "utils.h"

class Version
{
private:
    String form_string( void );
public:
    Version( unsigned int version, unsigned int subversion, String decorator, String build_date ):
        version(version), 
        subversion(subversion), 
        decorator(decorator),
        build_date(build_date),
        str( form_string() ),
        c_str( str.c_str() )
    {}
    
    String string()
    {
        return str;
    }

    const char * c_string()
    {
        return c_str;
    }

private:
    const unsigned int
        version,
        subversion;
    const String
        decorator,
        build_date,
        str;
    const char *
        c_str;
};