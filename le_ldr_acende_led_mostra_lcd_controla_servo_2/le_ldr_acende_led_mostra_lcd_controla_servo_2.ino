
int ldr = 0;
int led = 8;
#include<LiquidCrystal.h>;
#include<Servo.h>;
Servo servo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  servo.attach(9);
  lcd.begin(16, 2);
  lcd.print("Verificando luz.");
  servo.write(0);
}

void loop(){

  int ldrValue = analogRead(ldr);
  Serial.println(ldrValue);
  servo.write(map(ldrValue, 0, 1023, 0, 180));
  lcd.setCursor(0, 1);
  lcd.print("LDR: ");
  lcd.setCursor(5, 1);
  lcd.print(ldrValue);

  lcd.setCursor(9, 1);
  if(ldrValue < 50){
    lcd.print("| ON ");
    digitalWrite(led, HIGH);    
    //servo.write(180);
    //delay(400);
  }else{
    lcd.print("| OFF");
    digitalWrite(led, LOW);
    //servo.write(0);
    //delay(400);
  }

  delay(1000);  
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
