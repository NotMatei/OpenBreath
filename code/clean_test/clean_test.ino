#include <Servo.h>

Servo esc_signal;

const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;

void setup(){
  Serial.begin(9600);

  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  
  esc_signal.attach(9);
  esc_signal.write(30);
  delay(3000);
}

void loop(){  
  esc_signal.write(58);//Exhale speed
  delay(1875);//16 exhales per minute
  
  esc_signal.write(80); //inhale speed
  delay(1875);//16 inhales per minute
}
