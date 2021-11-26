
int ldr = 0;
int led = 9;
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Verificando luz.");
}

void loop(){

  int ldrValue = analogRead(ldr);
  Serial.println(ldrValue);
  lcd.setCursor(0, 1);
  lcd.print("LDR: ");
  lcd.setCursor(5, 1);
  lcd.print(ldrValue);

  lcd.setCursor(9, 1);
  if(ldrValue < 50){
    lcd.print("| ON ");
    digitalWrite(led, HIGH);    
  }else{
    lcd.print("| OFF");
    digitalWrite(led, LOW);
    
  }

  delay(1000);  
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
