#include "include/breathing.h"

Breathing::Pattern pattern( 5, 1500, 2, 1500 );
ESC esc( D4 );
Breathing::Engine engine( esc );
char input = 0;

void setup()
{
    Serial.begin( 9600 );
    while(!Serial.available());
    Serial.println("Initializing breathing engine");
    engine.Init();
    Serial.println("Breathing engine initialized");
}

void loop()
{

    engine.RunPattern( pattern );
}
