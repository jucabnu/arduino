#include <Servo.h>  //incluir a biblioteca de servo

Servo myservo;  //Inclusao do servo

int n = 0;  //Entradas seriais
int pos = 0;  //Posição zero para o servop

void setup(){
  Serial.begin(9600);  //Ativando a porta serial
  myservo.attach(8);  //Pino do servo+arduino
  myservo.write(0);  //Servo setado com valor zero
  Serial.flush();  //Limpando a memoria do serial
  Serial.println("Digite: \n 2-90 \n 3-180 \n 4-02");  //criação de um cabeçalho no serial
}

void loop(){
  if(Serial.available()>0){  //Teste se porta serial esta recebendo dados
    n = Serial.read();  //leitura de dados
    Serial.print("Valor lido: ");  
    Serial.println(n);  //Printa o valor teclado

    if(n==50){  //girar 90
    myservo.write(90);
    delay(500);
    }

    if(n==51){  //girar 180
    myservo.write(180);
    delay(500);
    }

    if(n==52){  //volta pra 0
    myservo.write(-180);
    delay(500);
    }
  }
  
  Serial.flush();
}
