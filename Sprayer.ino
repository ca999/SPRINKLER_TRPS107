#include<SoftwareSerial.h>
#include<Servo.h>
Servo myservo;
char ch,command;
int pos=0;
SoftwareSerial BT(0,1);
String string;


void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  

}

void loop()
{
 /* if(Serial.available())
  {
    ch=Serial.read();
    if(ch=='m')
    {
      myservo.attach(9);
      Serial.println("On");
      for(pos=0;pos<=180;pos+=1)
      {
        myservo.write(pos);
        delay(15);
      }
      for(pos=180;pos>=0;pos-=1)
      {
        myservo.write(pos);
        delay(15);
      }
      myservo.detach();

      
    }
    else
    {
      myservo.detach();
     Serial.println("Done");
    }
    
  }*/
   if (Serial.available() > 0) 
    {string = "";}
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
      
      if(command == ':')
      {
        break;
      }
      
      else
      {
        string += command;
      }
      
      delay(1);
    }
    if(string == "TO")
    {
      myservo.attach(9);
      Serial.println("On");
      for(pos=0;pos<=180;pos+=1)
      {
        myservo.write(pos);
        delay(15);
      }
      for(pos=180;pos>=0;pos-=1)
      {
        myservo.write(pos);
        delay(15);
      }
      myservo.detach();
    }
    if(string=="TF")
    {
       myservo.detach();
     Serial.println("Done");
      
    }


}
