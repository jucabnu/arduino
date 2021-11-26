

#include <Servo.h> // importa a biblioteca do servo
 
Servo myservo;  // criando objeto servo
 
int potpin = 0;  // definindo variável para referenciar pot
int potVal;    // variavel com valor da leitura do pot
 
void setup() // método de configuração
{ 
  myservo.attach(9);  // usa o método attach para o servo no pino 9
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // lê o valor do pino analog (0 a 1023)
  val = map(val, 0, 1023, 0, 179);     // faz escala entre 0~1023 para 0~179 (graus)
  myservo.write(val);                  // usa método write para passar rotação ao servo
  delay(15);                           // define um delay de 15 milis
} 
