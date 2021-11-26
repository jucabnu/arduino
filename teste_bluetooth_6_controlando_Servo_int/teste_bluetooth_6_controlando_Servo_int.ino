
#include <SoftwareSerial.h>;
#include <LiquidCrystal.h>;
#include <Servo.h>;
SoftwareSerial btCom(9, 10); // TX, RX
LiquidCrystal lcd(12,11,5,4,3,2);
Servo servo;

int pos = 90;

void setup() {
  btCom.begin(9600);
  btCom.println("Bluetooth iniciado");
  btCom.println("Aguardando comando");
  
  Serial.begin(9600);

  lcd.begin(16,2);
  lcd.print("Teste Bluetooth");  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("HC-05 by Jucabnu");  delay(3000);
  
  servo.attach(6);
  servo.write(90);
}

void loop() {


  
  if (btCom.available()){
    pos = btCom.read();
    // dataT = data.substring(0, data.length()-2);
    
    servo.write(pos);
    btCom.println(pos);
    Serial.println(pos);
    
    /*
    btCom.println("Mensagem enviada");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Celular diz: ");
    lcd.setCursor(0,1);
    lcd.print(dataTratada); 
    */
  }
  delay(100);
}
