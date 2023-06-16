#include "IRremote.h"
 
#define receiver 5 // IR receiver, Connect the Y pin of the Keyes IR sensor with the GPIO 26 of ESP32 
 
int device1 = 13; // gpio 13
int device2 = 12; // gpio 12
int device3 = 14; // gpio 14
int device4 = 27; // gpio 27
 
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
/*-----( Declare Variables )-----*/
 
 
 
void setup()   
{
  Serial.begin(115200);
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Start the receiver
 
  pinMode(device1, OUTPUT);
  pinMode(device2, OUTPUT);
  pinMode(device3, OUTPUT);
  pinMode(device4, OUTPUT);
   digitalWrite(device1, LOW);
   digitalWrite(device2, LOW);
   digitalWrite(device3, LOW);
   digitalWrite(device4, LOW);
 
 
}
 
 
void loop() 
{
  if (irrecv.decode(&results)) // have we received an IR signal?
 
  {
   Serial.println(results.value, HEX);  
 
    //translateIR(); 
      if (results.value==0xC00001)
      {   
        digitalWrite(device1, !digitalRead(device1));
           delay(200);
        }
       else if (results.value==0xC00002)
      {   
            digitalWrite(device2, !digitalRead(device2));
           delay(200);
        }
      else if (results.value==0xC00003)
      {   
        digitalWrite(device3, !digitalRead(device3));
           delay(200); 
        }
       else  if (results.value==0xC00004)
      {   
        digitalWrite(device4, !digitalRead(device4));
           delay(200); 
      }
      else if( results.value==0xC0005C){
        digitalWrite(device1, !digitalRead(device1));
        digitalWrite(device2, !digitalRead(device2));
        digitalWrite(device3, !digitalRead(device3));
        digitalWrite(device4, !digitalRead(device4));
        delay(200);
      }
      else  
      {   
           Serial.println("Wrong button pressed"); 
           delay(100);
        }
        
    irrecv.resume(); // receive the next value
  }  
}
