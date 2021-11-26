
#include <Servo.h>
#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define echoPin 8
#define trigPin 12

Servo servo_ultra_sonico;
Servo motorDireita;
Servo motorEsquerda;
Ultrasonic ultrasonic(12,8);
int BUZZER = 10;

//variáveis para uso da função do LCD  
LiquidCrystal lcd(9, 11, 5, 4, 3, 2); // ligando o display no arduino  
int pinoPotenciometro = 0;       // controle do brilho do LCD  
long valorPotenciometro = 0;      // controle do brilho do LCD  
boolean dist = true;          // Variável para saber se é para exibir a distância ou não  
String lado = "";           //Variável para escrever qual o lado da medição  
String frase = "";           //Variável para escrever uma frase na parte de cima  
String frase2 = "";          //Variável para escrever uma frase na parte de baixo  
int valor = 0;             //Variável para colocar o valor da distancia   

// executado na inicialização do Arduino  
void setup(){  
  lcd.begin(16, 2); // inicia o LCD  
  Serial.begin(9600); // inicializa a comunicação serial para mostrar dados em um display LCD  
  escrever_LCD(dist = false, lado = "",valor = 0, frase = ">> CarAut v1 <<" , frase2 = "Iniciando..." );  
  delay(500);  
  //configurações do servos motores  
  servo_ultra_sonico.attach(13); // anexa o servo motor lógico ao físico no pino 13.  
  pinMode(trigPin, OUTPUT);    // define o pino triger como saída.  
  pinMode(echoPin, INPUT);    // define o pino echo como entrada.  
  pinMode(BUZZER,OUTPUT);     // define o pino do buzzer como saída.  
  servo_ultra_sonico.write(90);  // inicialmente servo do sensor à 90 graus  
  iniciar_Motor;  
  rotacao_Parado;              
  escrever_LCD(dist = false, lado = "",valor = 0, frase = "** Criado por **" , frase2 = "Jucabnu corp.");  
  delay(2000);               
  escrever_LCD(dist = false, lado = "",valor = 0, frase = "jucabnu.tumblr" , frase2 = ".com" );  
  delay(2000);  
}  

// função principal do Arduino  
void loop(){  
  escrever_LCD(dist = false, lado = "",valor = 0, frase = "Pensando..." , frase2 = ">> CarAut v1 <<");   

  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  

  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  

  //seta o pino 12 com pulso baixo novamente  
  digitalWrite(trigPin, LOW);  
  andar();   
}  

//função para unir outras funções para poder andar com o robô  
void andar(){  
  reposicionaServoSonar();  
  int distancia = lerSonar();  
  if (distancia > 25) {  
    rotacao_Frente();  
  }
  else{   
    posicionaCarroMelhorCaminho();  
    andar();  
  }   
}  

//função para ler o sensor ultrassônico  
int lerSonar(){  
  return ultrasonic.Ranging(CM);  
}  

//função para calcular a distancia do centro  
int calcularDistanciaCentro(){  
  servo_ultra_sonico.write(90);   
  int leituraDoSonar = lerSonar();  
  return leituraDoSonar;   
}  

//função para calcular a distancia da direita  
int calcularDistanciaDireita(){  
  servo_ultra_sonico.write(10);   
  int leituraDoSonar = lerSonar();  
  return leituraDoSonar;    
}  
//função para calcular a distancia da esquerda  
int calcularDistanciaEsquerda(){  
  servo_ultra_sonico.write(180);   
  int leituraDoSonar = lerSonar();  
  return leituraDoSonar;    
}  
//função para pegar as distancia lidas e calcular qual a melhor distancia  
char calculaMelhorDistancia(){  
  int esquerda = calcularDistanciaEsquerda();  
  int centro = calcularDistanciaCentro();  
  int direita = calcularDistanciaDireita();  
  reposicionaServoSonar();  
  int maiorDistancia = 0;  
  char melhorDistancia = '0';  
  if (centro > direita && centro > esquerda){  
    melhorDistancia = 'c';  
    maiorDistancia = centro;  
  }
  else if (direita > centro && direita > esquerda){  
    melhorDistancia = 'd';  
    maiorDistancia = direita;  
  }
  else if (esquerda > centro && esquerda > direita){  
    melhorDistancia = 'e';  
    maiorDistancia = esquerda;  
  }  
  if (maiorDistancia <= 25) {  
    rotacao_Re();  
    posicionaCarroMelhorCaminho();  
  }  
  reposicionaServoSonar();  
  return melhorDistancia;  
}  

// função para colocar o carrinho na melhor distancia, ou seja girar ele para a melhor distancia  
void posicionaCarroMelhorCaminho(){  
  char melhorDist = calculaMelhorDistancia();      
  if (melhorDist == 'c'){  
    escrever_LCD(dist = false, lado = "",valor = 0, frase = "Melhor Distancia....: " , frase2 = "Frente" );   
    andar();  
  }
  else if (melhorDist == 'd'){  
    escrever_LCD(dist = false, lado = "",valor = 0, frase = "Melhor Distancia....: " , frase2 = "Direita" );   
    rotacao_Direita();  
    rotacao_Direita();  
  }
  else if (melhorDist == 'e'){  
    escrever_LCD(dist = false, lado = "",valor = 0, frase = "Melhor Distancia....: " , frase2 = "Esquerta" );   
    rotacao_Esquerda();  
    rotacao_Esquerda();  
  }
  else{  
    rotacao_Re();  
  }  
  reposicionaServoSonar();  
}  

//função para deixar o sensor "olho" do robô no centro  
void reposicionaServoSonar(){  
  servo_ultra_sonico.write(90);  
}  

//função para escrever no LCD   
void escrever_LCD(boolean dist, String lado, int valor, String frase, String frase2 )  
{  
  lcd.clear();  
  valorPotenciometro = analogRead(pinoPotenciometro); // brilho do lcd  
  if (dist == true ) {   
    lcd.setCursor(0,0);  
    lcd.print("Distancia ");  
    lcd.print(lado+" : ");  
    lcd.setCursor(0,1);  
    lcd.print(valor);  
  }  
  if (dist == false){  
    lcd.setCursor(0,0);  
    lcd.print(frase);  
    lcd.setCursor(0,1);  
    lcd.print(frase2);  
  }  
}  

// função que faz o carro (servo motor) parar   
void rotacao_Parado()  
{  
  motorDireita.detach();       // para os motores  
  motorEsquerda.detach();  
}  

// função que faz o carro (servo motor) andar para frente   
void rotacao_Frente()  
{  
  escrever_LCD(dist = false, lado = "",valor = 0, frase = "Indo para:" , frase2 = "Frente");   
  iniciar_Motor();          // usa a função inicia motor  
  motorDireita.write(0);       // motor da direita gira para frente  
  motorEsquerda.write(180);      // motor da esquerda gira para a frente  
  delay(600);  
  rotacao_Parado();  
}  

// função que faz o carro (servo motor) andar para traz   
void rotacao_Re()  
{  
  tone(10,300,300);   
  escrever_LCD(dist = false, lado = "",valor = 0, frase = "Indo para:" , frase2 = "Tras");   
  tone(10,300,300);   
  iniciar_Motor();           //praticamente a mesma coisa que a função a cima  
  tone(10,300,300);   
  motorDireita.write(180);  
  motorEsquerda.write(0);  
  delay(600);  
  tone(10,300,300);   
  rotacao_Parado();  
}  

// função que faz o carro (servo motor) vira a direita  
void rotacao_Direita()  
{  
  escrever_LCD(dist = false, lado = "",valor = 0, frase = "Virando para:" , frase2 = "Direita");   
  iniciar_Motor();  
  motorDireita.write(180);  
  motorEsquerda.write(180);  
  delay(250);  
  rotacao_Parado();  
}  

// função que faz o carro (servo motor) vira a esquerda  
void rotacao_Esquerda()  
{  
  escrever_LCD(dist = false, lado = "",valor = 0, frase = "Virando para:" , frase2 = "Esquerda");   
  iniciar_Motor();  
  motorDireita.write(0);  
  motorEsquerda.write(0);  
  delay(250);  
  rotacao_Parado();  
}  

//função para iniciar os motores   
void iniciar_Motor()  
{  
  motorDireita.attach(7);  
  motorEsquerda.attach(6);  
}  

