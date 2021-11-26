
#include<LiquidCrystal.h>;
#include<Servo.h>;
#include<SoftwareSerial.h>;

int trigPin = 6;
int echoPin = 10;
int alarme = 13;

SoftwareSerial btCom(0,0); // TX, RX interface módulo bluetooth

Servo servoCabeca;
Servo servoDireita;
Servo servoEsquerda;
LiquidCrystal lcd(12,11,5,4,3,2);

long distDireita;
long distEsquerda;
long distFrente;

int tempoParaAndar = 1000; // 10 segundos
int tempoParaVirar = 1000; // 2 segundos

boolean debugging = true;
boolean simulador = true;
boolean controleManual = false;

void setup(){

  // inicia comunicação serial bluetooth RS232
  btCom.begin(9600); 

  // inicia comunicação serial máquina se debugging()
  if(debugging){
    Serial.begin(9600);
  }

  // inicia os pinos do sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alarme, OUTPUT);

  // inicia as distâncias
  distDireita = 0;
  distEsquerda = 0;
  distFrente = 0;

  // inicia o servo da cabeça
  servoCabeca.attach(9);
  servoCabeca.write(90);

  // inicia o lcd
  lcd.begin(16,2);
  lcd.print("ROBO AUTONOMO V3");
  lcd.setCursor(0,1);
  lcd.print("by Jucabnu :)");
  delay(3000);
  lcd.clear();
}

// *********** controle de direção ***********

// dois motores rodando para frente
void andarParaFrente(){
  imprime("Indo para frente...","",0);
  if(!simulador){
    servoDireita.attach(7);
    servoEsquerda.attach(8);
    servoDireita.write(180);
    servoEsquerda.write(0);
  }
  delay(tempoParaAndar);
  parado();
}

// dois motores rodando para tras
void andarParaTras(){
  imprime("Voltando...","",0);
  if(!simulador){
    servoDireita.attach(7);
    servoEsquerda.attach(8);
    servoDireita.write(0);
    servoEsquerda.write(180);
  }
  delay(tempoParaAndar);
  parado();
}

// motor da esquerda gira para frente
// enquanto motor da direita girar para tras
void virarParaDireita(){
  imprime("Virando para","direita...",0);
  if(!simulador){
    servoDireita.attach(7);
    servoEsquerda.attach(8);
    servoDireita.write(180);
    servoEsquerda.write(180);
  }
  delay(tempoParaVirar);
  parado();
}

// motor da direita gira para frente
// enquanto motor da esquerda girar para tras
void virarParaEsquerda(){
  imprime("Virando para","esquerda...",0);
  if(!simulador){
    servoDireita.attach(7);
    servoEsquerda.attach(8);
    servoDireita.write(0);
    servoEsquerda.write(0); 
  }
  delay(tempoParaVirar);
  parado();
}

// destaca os dois motores para que fiquem parados
void parado(){
  if(!simulador){
    servoDireita.detach();
    servoEsquerda.detach();  
  }
  imprime("Parado...","",0);
}

// *********** controle da cabeça ***********
// *********** controle autonomia ***********

void mapeamento(){

  imprime("Iniciando teste...","",0);

  // obter distância à direita (180 graus)
  servoCabeca.write(180);
  distDireita = leDistancia();
  delay(500);

  // obter distância à esquerda (0 graus)
  servoCabeca.write(0);
  distEsquerda = leDistancia();
  delay(500);

  // voltar para centro (90 graus)
  servoCabeca.write(90);
  imprime("Distancias obtidas","",0);
  delay(500);

}

// le distancia quando a cabeca está posicionada
int leDistancia(){  
  int dis = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  dis = pulseIn(echoPin, HIGH) / 29 / 2;
  delay(100);
  return dis;

  // pulseInt lê o tempo entre a chamada e o pino entrar em high  
  // calculo é baseado em s = v.t, lembrando que o tempo vem dobrado  
  // porque é o tempo de ida e volta do ultrassom 
}

// verifica qual distancia é melhor e direciona o carro
void direcionamento(){

  if(distDireita > distEsquerda){
    imprime("Melhor opcao:","Direita >>>",0);
    if(!simulador){
      virarParaDireita();
    }
  }
  else{
    imprime("Melhor opcao:","<<< Esquerda",0);
    if(!simulador){
      virarParaEsquerda();
    }
  }
}

// dipara alarme no pino 13
void avisoSonoro(){
  digitalWrite(alarme, HIGH);
  tone(8,440);
  delay(50);
  noTone(8);
  delay(50);
}

// metodo para escrever no display LCD
void imprime(String linha0, String linha1, int tempo){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(linha0);
  delay(500);
  lcd.setCursor(0,1);
  lcd.print(linha1);
  delay(tempo);  
  if(debugging){
    imprimeSerial(linha0, linha1);
  }
}

void imprimeSerial(String linha0, String linha1){
  Serial.print(linha0);
  Serial.print(" ");
  Serial.println(linha1);
}

void imprimeDistancia(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia em cm:");
  lcd.setCursor(1,1);
  lcd.print(leDistancia());
}

void loop(){

  // controle manual via bluetooth (reaproveita métodos)

  if(ControleManual){

    // falta implementar os métodos que leem a btCom e invocam os métodos
    // de direção andarParaFrente(), andarParaTras(), virarParaDireita(), 
    // virarParaEsquerda() e parado(). Criar um método para mudar de controle
    // manual para autonomo.
    
  }
  else{

    // controle autonomo, via sensor de distancia

    imprime("Mapeamento", "inicial...", 0);
    mapeamento();
    imprime("Direcionando...","", 0);
    direcionamento();
    while(leDistancia() > 20){
      andarParaFrente();
      parado();
    }
    delay(500);
  }  

}




