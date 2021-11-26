//Programa : Sensor de umidade e temperatura DHT11
//Autor : Arduino e Cia

#include <dht.h>
#define dht_dpin A0 //Pino DATA do Sensor ligado na porta Analogica A1
#include<LiquidCrystal.h>;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT; //Inicializa o sensor

void setup()
{
  Serial.begin(9600);
  delay(1000);//Aguarda 1 seg antes de acessar as informações do sensor
  lcd.begin(16, 2);
}

void loop()
{
  DHT.read11(dht_dpin); //Lê as informações do sensor

    lcd.setCursor(0, 0);
    lcd.print("Umid. / Temp."); 
    lcd.setCursor(0, 1);
    lcd.print(DHT.humidity);
    lcd.setCursor(5, 1);
    lcd.print("%");
    lcd.setCursor(7, 1);
    lcd.print(DHT.temperature);
    lcd.setCursor(13, 1);
    lcd.print("oC");
    
    
    Serial.print("Umidade = ");
    Serial.print(DHT.humidity);
    Serial.print(" %  ");
    Serial.print("Temperatura = ");
    Serial.print(DHT.temperature); 
    Serial.println(" Celsius  ");
  delay(2000);  //Não diminuir muito este valor. O ideal é a leitura a cada 2 segundos
}
