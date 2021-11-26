
#include<LiquidCrystal.h>;
LiquidCrystal lcd(12,11,5,4,3,2);
int tempPin = 0;
float tempC = 0;

void setup(){
  
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);
  lcd.print("JUCABNU");
  lcd.setCursor(0,1);
  lcd.print("Teste com LM35");
  delay(3000);  
  lcd.clear();
  
}

void loop(){

  tempC = (4.8 * analogRead(tempPin) * 100.0) / 1024.0;
  //tempC = analogRead(tempPin);
  Serial.println(tempC);
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.setCursor(0,1);
  lcd.print(tempC);
  lcd.setCursor(6,1);
  lcd.print("oC");
  delay(500);

}
