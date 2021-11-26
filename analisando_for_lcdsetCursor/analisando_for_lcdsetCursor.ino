
#include<LiquidCrystal.h>;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  
  lcd.begin(16, 2);

}

void loop(){

  lcd.setCursor(0,0);
  lcd.print("ANALISANDO");
  
  for(int i = 0; i < 16; i++){
    lcd.setCursor(i,1);
    lcd.print("|");
    delay(500);
  }
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Análise completa");
  lcd.setCursor(0,1);
  lcd.print("Temperatura: ");
  lcd.setCursor(13,1);
  lcd.print("25");
  delay(5000);
  


}
