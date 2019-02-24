#include <Servo.h>   //servo library

Servo myservo;       //servo object
int previousAngle = 0;

const int potPin = A3; //sensor pin

void setup() {
  myservo.attach(9);  //data pin of the servo
  pinMode(potPin, INPUT); //sensor pin as an input
}

void loop() {
  int val = analogRead(potPin);
  int angle = map(val, 0, 1023, 0, 180);

  if(angle>previousAngle)
  {
    for(int i=previousAngle; i<=angle; i++)
    {
      myservo.write(i); //turn servo by 1 degrees
      delay(10);        //delay for smoothness
    }
  }

  if(angle<previousAngle)
  {
    for(int i=previousAngle; i>=angle; i--)
    {
      myservo.write(i); //turn servo by 1 degrees
      delay(10);        //delay for smoothness
    }
  }

  previousAngle = angle;
}
