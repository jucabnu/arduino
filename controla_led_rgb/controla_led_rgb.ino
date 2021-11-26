
int r1 = 2;
int g1 = 3;
int b1 = 4;
int r2 = 5;
int g2 = 6;
int b2 = 7;

int tempo1 = 100;
int tempo2 = 10;

void setup(){
  pinMode(r1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(b2, OUTPUT);
    
}

void loop(){

  digitalWrite(r1, HIGH);
  digitalWrite(g2, HIGH);
  delay(tempo1);
  digitalWrite(r1, LOW);
  digitalWrite(g2, LOW);
  delay(tempo2);
  digitalWrite(g1, HIGH);
  digitalWrite(b2, HIGH);
  delay(tempo1);
  digitalWrite(g1, LOW);
  digitalWrite(b2, LOW);
  delay(tempo2);
  digitalWrite(b1, HIGH);
  digitalWrite(r2, HIGH);
  delay(tempo1);
  digitalWrite(b1, LOW);
  digitalWrite(r2, LOW);
  delay(tempo2);  
}
