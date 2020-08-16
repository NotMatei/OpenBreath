#include "esc.h"

#define ESC_PIN 9
#define BUTTON_PIN 8
#define MOTOR_SPEED 20

ESC esc(ESC_PIN);

void setup()
{ 
    esc.Init();
    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
   static bool should_run = false;
   bool input = digitalRead(BUTTON_PIN);
   if(should_run != input)
   {
	if(should_run)
	    esc.SetSpeed(MOTOR_SPEED);
	else
	    esc.SetSpeed(0);
	should_run = input;
   }
}
