// ***********************************
// Robotic Arm Kit v1.0
// San3aHub.com by AhmedFarag
// ***********************************

#include <Servo.h>

Servo MyServo,MyServo2,MyServo3,MyServo0;
char ByteReceived ;
int MyPosition,MyPosition2,MyPosition3,MyPositionG;

int runCounter = 0;
int ledPin = A5;// set the default home servo positions 
int valGripper = 30;
int valBase = 70;
int valShoulder = 25;
int valElbow = 150;
int delayT = 350;

void setup()
{
 Serial.begin(9600); 
 
 MyServo.attach(6); // base  attach
 MyServo2.attach(9); //shoulder  attach
 MyServo3.attach(10); //Elbow attach
 MyServo0.attach(11); // Gripper  attach
 
 delay(15);
 MyServo.write(valBase);   // base
 delay(30);
 MyServo2.write(valShoulder);  // shoulder
 delay(30);
 MyServo3.write(valElbow); // elbow
 delay(300);
}
 
void loop()
{    
    while (Serial.available()>0)  { 
      
    ByteReceived = Serial.read();  
    
    switch (ByteReceived) {    
      
      // ************* Base
      case 'l':
      MyPosition = MyServo.read() + 2;    // L for move base left
      MyServo.write(MyPosition);      
      Serial.print("Base");
      Serial.print("\t");
      Serial.println(MyServo.read()); 
      delay(15);
      
      break;    
      
      case 'r':
      MyPosition = MyServo.read() - 2;    // R for move base right
      MyServo.write(MyPosition);
      
      Serial.print("Base");
      Serial.print("\t");
      Serial.println( MyServo.read()); 
      delay(15);
      
      break;
      
      // ************* Elbow
      case 'u':
      MyPosition2 = MyServo2.read() + 2;   // U for move Elbow up
      MyServo2.write(MyPosition2);      
      Serial.print("Elbow");
      Serial.print("\t");
      Serial.println(MyServo2.read()); 
      delay(15);
      
      break;      case 'd':
      MyPosition2 = MyServo2.read() - 2;   // D for move Elbow down
      MyServo2.write(MyPosition2);      
      Serial.print("Elbow");
      Serial.print("\t");
      Serial.println(MyServo2.read()); 
      delay(15);
      
      break;      // ************* Shoulder
      case 'w':
      MyPosition3 = MyServo3.read() + 2;  // W for move Shoulder down
      MyServo3.write(MyPosition3);      
      Serial.print("Shoulder");
      Serial.print("\t");
      Serial.println(MyServo3.read()); 
      delay(15);
      
      break;      case 's':
      MyPosition3 = MyServo3.read() - 2;  // S for move Shoulder up
      MyServo3.write(MyPosition3);      
      Serial.print("Shoulder");
      Serial.print("\t");
      Serial.println(MyServo3.read()); 
      delay(15);
      
      break;      // ************* Gripper
      case 'o':
      MyServo0.write(30);                // O to open Gripper
      Serial.print("Gripper Open");
      Serial.print("\t");
      Serial.println(MyServo0.read()); 
      delay(15);
      
      break;      case 'c':                          // C to open Gripper
      MyServo0.write(1);
      Serial.print("Gripper Close");
      Serial.print("\t");
      Serial.println(MyServo0.read()); 
      delay(15);
      
      break;      // ************* Default Dropped position (quick drop position)
      case 'q':
      
       digitalWrite(ledPin,HIGH); 
       Serial.println("Default Dropped activated!");  
       Pickup();
       Drop();
       Home();
       digitalWrite(ledPin,LOW);
      
      break;      
      // ************* Force Stop and go home position
      case 'h':
      
       Home();
       digitalWrite(ledPin,LOW);
      
      break; 

      // ************* print position
      case 'p':
      
       positions();
       digitalWrite(ledPin,LOW);
      break; 

      // ************* print position
      case 'z':
      
       Serial.println("Robotic Arm Ready!");
       break; 
      
      default:         
         Serial.println("default"); 
     break;
  }
    }
}
