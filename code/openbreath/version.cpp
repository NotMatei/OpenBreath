#include "include/openbreath.h"

String Version::form_string()
{
    char ver[20] = {0};
    snprintf( 
        ver, 
        19, 
        "%u.%u %s, Built on: %s",
        version,
        subversion,
        decorator.c_str(),
        build_date.c_str()
    );

    return String(ver);
}