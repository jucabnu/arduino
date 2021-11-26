
#include <SoftwareSerial.h>;
#include <LiquidCrystal.h>;
LiquidCrystal lcd(12,11,5,4,3,2);
SoftwareSerial btCom(9, 10); // TX, RX

void setup() {
  btCom.begin(9600);
  btCom.println("Bluetooth iniciado");
  btCom.println("Aguardando comando");

  lcd.begin(16,2);
  lcd.print("Teste Bluetooth");  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("HC-05 by Jucabnu");  delay(3000);
  lcd.clear();
}

void loop() {

//  int BluetoothData; //dado vindo do celular

  String data;
  String dataTratada;
  
  if (btCom.available()){
    data = btCom.readString();
    dataTratada = data.substring(0, data.length()-2);
    
    btCom.println("Mensagem enviada");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Celular diz: ");
    lcd.setCursor(0,1);
    lcd.print(dataTratada); 
  }
  delay(100);
}
