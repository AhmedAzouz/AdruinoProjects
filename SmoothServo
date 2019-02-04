#include <Servo.h>

Servo myservo;       //servo object

void setup() {
  myservo.attach(9);  //data pin of the servo
}

void loop() {

  motor_move(myservo,160);
}

void motor_move(Servo &theServo, int NewAngle, int TimeDelay)
{
  int PreAngle = theServo.read();   // read Current angle 'PreAngle'
  
  for(PreAngle = 0; PreAngle <= NewAngle; PreAngle += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    theServo.write(NewAngle);         // tell servo to go to position in variable 'pos' 
    delay(TimeDelay);                    // waits ms for the servo to reach the position 
  } 
}

int myMultiplyFunction(int x, int y){
  int result;
  result = x * y;
  return result;
}
