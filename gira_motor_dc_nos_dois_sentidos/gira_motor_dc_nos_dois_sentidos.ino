
int esquerda = 7;
int direita = 8;

void setup(){

  pinMode(esquerda, OUTPUT);
  pinMode(direita, OUTPUT);
  digitalWrite(esquerda, LOW);
  digitalWrite(direita, LOW);
}


void loop(){
 
  int tempo = 50;
  paraMotor();

  // gira para direita
  digitalWrite(esquerda, LOW);
  digitalWrite(direita, HIGH);
  delay(tempo);

  paraMotor();
  
  // gira para esquerda
  digitalWrite(esquerda, HIGH);
  digitalWrite(direita, LOW);
  delay(tempo);

}

void paraMotor(){
  digitalWrite(esquerda, LOW);
  digitalWrite(direita, LOW);
  delay(1000);
}
