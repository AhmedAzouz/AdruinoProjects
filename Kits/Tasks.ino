

void positions()
{
    Serial.print("Base : ");
    Serial.print(valBase);
    Serial.print("\t");
    Serial.print("Shou : ");
    Serial.print(valShoulder);
    Serial.print("\t");
    Serial.print("Elbow : ");
    Serial.print(valElbow);
    Serial.print("\t");
    Serial.print("Grip : ");
    Serial.println(valGripper);
}

void Home() //Call this fucntion when u want to set arm in home position
  {
    MyServo0.write(valGripper);   // Gripper
    delay(15);
    MyServo.write(valBase);   // base
    delay(30);
    MyServo2.write(valShoulder);  // shoulder
    delay(30);
    MyServo3.write(valElbow); // elbow
    delay(delayT);
  }
  
void Pickup() // This is fixed pick place.
  {
   MyServo.write(4);   // base
   delay(delayT);
  
   MyServo3.write(125); // elbow 
   MyServo2.write(95);  // shoulder
   delay(delayT);
   
   MyServo0.write(50);   // Gripper open wide
   delay(delayT);
   
   MyServo0.write(2);   // Gripper close
   delay(delayT);
  
   MyServo2.write(60);  // shoulder up little
   MyServo3.write(80);  // elbow up little
   delay(delayT);
   
   Serial.println("Object Pickeded");
  }
  
  void Drop() // This is fixed Drop place.
  { 
   MyServo.write(145);   // base
   delay(delayT);
   
   MyServo2.write(80);  // shoulder
   delay(15);
   
   MyServo3.write(115); // elbow
   delay(delayT);
  
   MyServo0.write(40);   // Gripper open wide
   delay(delayT);
  
   MyServo3.write(90);  // elbow up little
   delay(delayT);
   
   Serial.println(F("Object Dropped"));
   }
   
   void  Playback()
  {
        
    //      String phrase;
    //      phrase = String(phrase + ByteReceived); // convert the char input to stirng can be split    // Read each command pair 
    char* command = strtok(ByteReceived, "&");
    while (command != 0)
    {
        // Split the command in two values
        char* separator = strchr(command, ':');
        if (separator != 0)
        {
            // Actually split the string in 2: replace ':' with 0
            *separator = 0;
            int servoId = atoi(command);
            ++separator;
            int angle = atoi(separator);
    
            // Do something with servoId and angle
            
            if (servoId = 1)
            {
               MyServo.write(angle);
                delay(delayT);
            }
            else if (servoId = 2)
            {
               MyServo2.write(angle);
                delay(delayT);
            }
            else if (servoId = 3)
            {
              MyServo3.write(angle);
                delay(delayT);
            }
            
        }
        // Find the next command in input string
        command = strtok(0, "&");
    }
    
  }
