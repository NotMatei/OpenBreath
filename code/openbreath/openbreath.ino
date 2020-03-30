#include "include/esc.h"

ESC esc(D4);

void setup()
{
    Serial.begin( 9600 );
}

void loop()
{
    while( !Serial.available() );
    esc.Init();
    Serial.println("\nESC speed test");
    char input;
    for( int i = 60; i < 180; i += 2 )
    {
        Serial.print( "Speed will be set to " );
        Serial.println( i );
        esc.SetRawSpeed(i);
        Serial.println( "Changing speed in 5 seconds" );
        delay( 5000 );
    }
}
