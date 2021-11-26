
#include<LiquidCrystal.h>;
LiquidCrystal lcd(12,11,5,4,3,2);
int esquerda = 7;
int direita = 8;


void setup(){

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("JUCABNU");
  lcd.setCursor(0,1);
  lcd.print("Teste motor DC");
  delay(2000);
  lcd.clear();
  
  pinMode(esquerda, OUTPUT);
  pinMode(direita, OUTPUT);
  digitalWrite(esquerda, LOW);
  digitalWrite(direita, LOW);
}


void loop(){
 
  int tempo = 1000;
  paraMotor();

  // gira para direita
  digitalWrite(esquerda, LOW);
  digitalWrite(direita, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Sentido: ");
  lcd.setCursor(0,1);
  lcd.print(">>>> Direita");
  delay(tempo);

  paraMotor();
  
  // gira para esquerda
  digitalWrite(esquerda, HIGH);
  digitalWrite(direita, LOW);
  lcd.setCursor(0,0);
  lcd.print("Sentido: ");
  lcd.setCursor(0,1);
  lcd.print("<<<< Esquerda");
  delay(tempo);

}

void paraMotor(){
  
  digitalWrite(esquerda, LOW);
  digitalWrite(direita, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sentido: ");
  lcd.setCursor(0,1);
  lcd.print("< Parado >");
  delay(1000);
}
