
#include<LiquidCrystal.h>;
LiquidCrystal lcd(12,11,5,4,3,2);
int tempPin = 0;
//float tempC = 0;
//float menor;
//float maior;

int tempC = 0;
int menor;
int maior;

void setup(){
  
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);
  lcd.print("JUCABNU");
  lcd.setCursor(0,1);
  lcd.print("Teste com LM35");
  delay(3000);  
  lcd.clear();
  
  tempC = (4.8 * analogRead(tempPin) * 100.0) / 1024.0;
  maior = tempC;
  menor = tempC;
  
}

void imprimir(){

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(6,0);
  lcd.print(tempC);
  lcd.setCursor(0,1);
  lcd.print("Max:");
  lcd.setCursor(5,1);
  lcd.print(maior);
  lcd.setCursor(8,1);
  lcd.print("Min:");
  lcd.setCursor(13,1);
  lcd.print(menor);
  //lcd.clear();


}

void loop(){


  tempC = (4.8 * analogRead(tempPin) * 100.0) / 1024.0;  
  // tempC = analogRead(tempPin);
  Serial.println(tempC);
  if(tempC > maior){
    maior = tempC;
  }
  if(tempC < menor){
    menor = tempC;
  }
  imprimir();
  delay(500);

}


