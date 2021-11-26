#include<SoftwareSerial.h>;
#include<Servo.h>;

Servo servo;
SoftwareSerial btCom(10,11);

void setup(){
  
  Serial.begin(9600);
  btCom.begin(9600);
  servo.attach(9);


}

void loop(){

  String comando;
  if(btCom.available()){
    btCom.print("Aguardando comando:");
    comando = btCom.readString();
    Serial.println(comando);
    
    if(comando == "left"){
      servo.write(5);
    }
    if(comando == "center"){
      servo.write(90);
    }
    if(comando == "right"){
      servo.write(175);
    }
    delay(500);
  
  
  }
  delay(100);


}
