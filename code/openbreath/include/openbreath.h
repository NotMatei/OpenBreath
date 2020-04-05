#pragma once

#include "Arduino.h"

#include <iostream>

#include "stdio.h"
#include "stdlib.h"

#include "utils.h"

class Version
{
private:
    std::string form_string( void );
public:
    Version( uint version, uint subversion, std::string decorator, Date build_date ):
        version(version), 
        subversion(subversion), 
        decorator(decorator), 
        build_date(build_date),
        str(form_string()),
        c_str( str.c_str() )
    {}

    operator std::string()
    {
        return str;
    }

    operator char *()
    {
        return (char *)c_str;
    }

private:
    const uint
        version,
        subversion;
    const std::string
        decorator,
        str;
    const char *
        c_str;
    Date build_date;
};
