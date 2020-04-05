#include "include/openbreath.h"

std::string Version::form_string()
{
    char ver[20] = {0};
    snprintf( 
        ver, 
        19, 
        "%u.%u %s, Built on: %u/%u/%u",
        version,
        subversion,
        decorator.c_str(),
        build_date.day,
        build_date.month,
        build_date.year
    );

    return std::string(ver);
}