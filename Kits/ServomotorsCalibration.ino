#include <Servo.h> 

Servo base, shoulder, elbow, claw ;  // creates 4 "servo objects"
 void setup() 
{ 
  Serial.begin(9600);
  base.attach(6);  // attaches the servo on pin 6 to the base object
  shoulder.attach(9);  // attaches the servo on pin 9 to the shoulder object
  elbow.attach(10);  // attaches the servo on pin 10 to the elbow object
  claw.attach(11);  // attaches the servo on pin 11 to the claw object
} 
 void loop() 
{ 
  elbow.write(90); // sets the servo position according to the value(degrees)
  base.write(90); // does the same
  shoulder.write(90); // and again
  claw.write(25); // yes you've guessed it
  delay(300); // doesn't constantly update the servos which can fry them
} 
