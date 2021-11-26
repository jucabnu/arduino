
#include <SoftwareSerial.h>;
#include <LiquidCrystal.h>;

LiquidCrystal lcd(12,11,5,4,3,2);

SoftwareSerial btCom(9, 10); // TX, RX
int BluetoothData; //dado vindo do celular

void setup() {
  btCom.begin(9600);
  btCom.println("Bluetooth On please press 1 or 0 ..");
  lcd.begin(16,2);
  lcd.print("Teste Bluetooth");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("HC-05 by Jucabnu");
  delay(3000);
  lcd.clear();
  
}

void loop() {
  
   if (btCom.available()){
     BluetoothData = btCom.read();
   if(BluetoothData=='1'){
     lcd.setCursor(0,0);
     lcd.print("pressionou 1");
     delay(5000);
     lcd.clear();
     btCom.println("LED  On D13 ON ! ");
   }
  if (BluetoothData=='0'){
     lcd.setCursor(0,0);
     lcd.print("pressionou 0");
     delay(5000);
     lcd.clear();
     btCom.println("LED  On D13 OFF ! ");
  }
}
delay(100);
}
