
#include <SoftwareSerial.h>;
#include <LiquidCrystal.h>;
#include <Servo.h>;
SoftwareSerial btCom(9, 10); // TX, RX
LiquidCrystal lcd(12,11,5,4,3,2);
Servo servo;

void setup() {
  btCom.begin(9600);
  btCom.println("Bluetooth iniciado");
  btCom.println("Aguardando comando");

  lcd.begin(16,2);
  lcd.print("Teste Bluetooth");  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("HC-05 by Jucabnu");  delay(3000);
  lcd.clear();
  
  servo.attach(6);
}

void loop() {

//  int BluetoothData; //dado vindo do celular

  String data;
  String dataT;
  
  if (btCom.available()){
    data = btCom.readString();
    dataT = data.substring(0, data.length()-2);
    
    if(dataT == "left"){
      servo.write(175);
    }else if(dataT == "right"){
      servo.write(5);
    }else{
      servo.write(90);
    }
    
    
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
