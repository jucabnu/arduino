
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
 
void imprime(int pos){

    Serial.print(analogRead(ldr));
    Serial.print(" | ");
    Serial.println(pos);
  
} 
 
void loop(){ 
   
   for(pos = 0; pos < 180; pos++){
    myservo.write(pos);
    delay(15);
    imprime(pos);
    while(analogRead(ldr) > 100){
      digitalWrite(13, HIGH);
      delay(1000);
      Serial.println("Tem luz.");

    }
          digitalWrite(13, LOW);
  } 
  for(pos = 180; pos>=1; pos--){                                
    myservo.write(pos);
    delay(15);
    imprime(pos);
    while(analogRead(ldr) > 100){
            digitalWrite(13, HIGH);
      delay(1000);
      Serial.println("Tem luz.");

    }
          digitalWrite(13, LOW);
  }  
    
    
  }

  
  
