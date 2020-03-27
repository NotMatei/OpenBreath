  /*
          Arduino Brushless Motor Control
       by Dejan, https://howtomechatronics.com
  */
  #include <Servo.h>
  Servo ESC;     // create servo object to control the ESC
  int potValue;  // value from the analog pin
  void setup() {
    // Attach the ESC on pin 9
    ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
    //ESC.write(30);
    delay(3000);
  }
  void loop() {
    ESC.write(116);    // Send the signal to the ESC
    delay(1000);
  }
