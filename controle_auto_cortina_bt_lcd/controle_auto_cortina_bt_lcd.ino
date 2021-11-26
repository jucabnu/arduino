#include<SoftwareSerial.h>;
#include<LiquidCrystal.h>;

SoftwareSerial btCom(9,10); // TX, RX
LiquidCrystal lcd(12,11,5,4,3,2);
int rele = 8;

void setup(){
  btCom.begin(9600);
  btCom.println("Comunicação Bluetooth iniciada.");
  btCom.println("Aguardando comando...");
  
  lcd.begin(16,2);
  lcd.print("Teste Relay + BT");
  lcd.setCursor(0,1);
  lcd.print("by Jucabnu");
  pinMode(rele, OUTPUT);
  rele = LOW;
  delay(3000);
}

void printLcd(String texto, int coluna, int linha){
  lcd.setCursor(coluna, linha);
  lcd.print(texto);
  delay(100);
}

void loop(){

  String data;

  if(btCom.available()){
    btCom.print("Envie 'abrir' para abrir:");
    printLcd("Aguardando",0,0);
    printLcd("comando",0,1);
    
    data = btCom.readString().substring(0, btCom.readString().length()-2);
    
    if(data == "abrir"){
      delay(100);
      digitalWrite(rele, HIGH);
      btCom.println("Aguarde...");
      printLcd("Aguarde...",0,0);
      delay(100);
      btCom.println("Cortina abrindo...");
      printLcd("Cortina abrindo.",0,1);
      delay(2000);
      digitalWrite(rele, LOW);
    }  
  }
  delay(100);
}
