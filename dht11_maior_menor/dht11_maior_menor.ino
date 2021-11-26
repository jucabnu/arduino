
#include <dht.h>
#define dht_dpin A0 //analog 0
#include<LiquidCrystal.h>;
LiquidCrystal lcd(12,11,5,4,3,2);
dht DHT;

float maiorH;
float menorH;
float maiorT;
float menorT;

void setup(){
  Serial.begin(9600);
  delay(1000);
  DHT.read11(dht_dpin);
  menorH = DHT.humidity;
  maiorH = DHT.humidity;
  menorT = DHT.temperature;
  maiorT = DHT.temperature;
  lcd.begin(16, 2);
  lcd.print("JUCABNU _ DHT11");
  delay(3000);
  lcd.clear();
}

void loop(){

  DHT.read11(dht_dpin);
  float temp = DHT.temperature;
  float humi = DHT.humidity;
  if(temp < menorT){
    menorT = temp;
  }
  if(temp > maiorT){
    maiorT = temp;
  }
  if(humi < menorH){
    menorH = humi;
  }
  if(humi > maiorH){
    maiorH = humi;
  }
  mostrar(humi, temp);
  mostrarMaior();
  mostrarMenor();
}

void mostrarMaior(){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("     MINIMA    ");
  lcd.setCursor(0, 1);
  lcd.print("________________");
  delay(1500);  
  lcd.clear();
  lcd.setCursor(0, 0);  
  lcd.print("Umid. / Temp."); 
  lcd.setCursor(0, 1);
  lcd.print(menorH);
  lcd.setCursor(5, 1);
  lcd.print("%");
  lcd.setCursor(7, 1);
  lcd.print(menorT);
  lcd.setCursor(13, 1);
  lcd.print("oC");
  delay(2000);

}

void mostrarMenor(){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("     MAXIMA     ");
  lcd.setCursor(0, 1);
  lcd.print("________________");
  delay(1500);  
  lcd.clear();
  lcd.setCursor(0, 0);  
  lcd.print("Umid. / Temp."); 
  lcd.setCursor(0, 1);
  lcd.print(maiorH);
  lcd.setCursor(5, 1);
  lcd.print("%");
  lcd.setCursor(7, 1);
  lcd.print(maiorT);
  lcd.setCursor(13, 1);
  lcd.print("oC");
  delay(2000);

}

void mostrar(float humi, float temp){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" LEITURA ATUAL  ");
  lcd.setCursor(0, 1);
  lcd.print("________________");
  delay(1500);  
  lcd.clear();
  lcd.setCursor(0, 0);  
  lcd.print("Umid. / Temp."); 
  lcd.setCursor(0, 1);
  lcd.print(humi);
  lcd.setCursor(5, 1);
  lcd.print("%");
  lcd.setCursor(7, 1);
  lcd.print(temp);
  lcd.setCursor(13, 1);
  lcd.print("oC");
  delay(3000);
}




