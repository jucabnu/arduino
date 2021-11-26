
#include <Servo.h> 

Servo myservo;
int pos = 0;
int ldr = 0;
 
void setup() 
{ 
  myservo.attach(9);
  Serial.begin(9600);
  myservo.write(0);
    
} 
 
 
void loop(){ 
   
  
    int ldrValue = analogRead(ldr);
    Serial.print(ldrValue);
    Serial.print(" | ");
    Serial.println(pos);
    if(ldrValue < 100){
      if(pos <= 175){
        pos = pos + 5;
        myservo.write(pos);
        Serial.println("Não tem luz! Mexe o servo.");
      }else{
        pos = 0;
        myservo.write(pos);
        Serial.println("Chegou no limite! Volta.");
      }
    }else{
      while(analogRead(ldr) > 100){
        delay(1000);
        Serial.println("Tem luz!");
      }
      
    }
    delay(500);
    Serial.println("Repetição do loop.");
        

  }

  
  
