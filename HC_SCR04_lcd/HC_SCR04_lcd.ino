#define trigPin 7 //Pino 12 envia o pulso para gerar o echo  
#define echoPin 8 //Pino 13 recebe o pulso do echo  
#include <LiquidCrystal.h>;
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()  
{  
  lcd.begin(16,2);
   Serial.begin(9600); //inicia a porta serial  
   pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)  
   pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)  
   // pinMode(4, OUTPUT); // define o pino 12 como saida (envia)  
   lcd.print("JUCABNU");
   lcd.setCursor(0,1);
   lcd.print("TESTE ULTRASSOM");
   delay(3000);
   lcd.clear();
}  
   
void loop()  
{  

    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);  

  //pulseInt lê o tempo entre a chamada e o pino entrar em high  
    long duration = pulseIn(echoPin,HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
    long distancia = duration /29 / 2 ;  
   
    Serial.print("Distancia em CM: ");  
    lcd.setCursor(0,0);
    lcd.print("Distancia em CM");
    Serial.println(distancia);  
    lcd.setCursor(0,1);
    lcd.print(distancia);
    /*
    if (distancia < 5)
    { 
      digitalWrite(4,  HIGH);
      tone(8,440);
      delay(50);
      noTone(8);
      delay(50);
    }
    else
       if (distancia < 10)
       {
         digitalWrite(4,  HIGH);
         tone(8,440);
         delay(100);
         noTone(8);
         delay(100);
       }
    digitalWrite(4, LOW);
    */
    delay(100); //espera 1 segundo para fazer a leitura novamente  
    lcd.print("                ");
}  
