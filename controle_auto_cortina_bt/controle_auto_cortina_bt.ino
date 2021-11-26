#include<SoftwareSerial.h>;

SoftwareSerial btCom(9,10); // TX, RX
int rele = 11;

void setup(){
  btCom.begin(9600);
  btCom.println("Comunicação bluetooth iniciada.");
  btCom.println("Aguardando comando...");
  pinMode(rele, OUTPUT);
  rele = LOW;
}

void loop(){

  String data;

  if(btCom.available()){
    btCom.print("Envie 'abrir' para abrir:");
    data = btCom.readString().substring(0, btCom.readString().length()-2);
    
    if(data == "abrir"){
      delay(100);
      digitalWrite(rele, HIGH);
      btCom.println("Aguarde...");
      delay(100);
      btCom.println("Cortina abrindo...");
      delay(2000);
      digitalWrite(rele, LOW);
    }  
  }
  delay(100);
}
