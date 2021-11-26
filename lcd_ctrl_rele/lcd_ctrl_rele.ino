
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldr = 0;
int ldrValue;
int rele = 8;

void setup() {
  
  lcd.begin(16, 2);
  lcd.print("jucabnu _teste");
  
  pinMode(rele, OUTPUT);
  // Serial.begin(9600);
  
}

void loop() {
  // lcd.print(millis()/1000);

  ldrValue = analogRead(ldr);
  // int valor = map(ldrValue, 0, 1023, 0, 255);
  lcd.setCursor(0, 1);
  lcd.print("Valor pot: ");
  lcd.setCursor(11,1);
  lcd.print(ldrValue);
  
  if(ldrValue < 50){
    digitalWrite(rele, LOW);
  }else{
    digitalWrite(rele, HIGH);
  }
    
//   analogWrite(led, valor);
  delay(500);
  
  
  // map(value, fromLow, fromHigh, toLow, toHigh)
  
  
  
}

