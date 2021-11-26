
int pinoLido = 4;
int pinoAlarme = 5;
int estado = HIGH;
int quantasVezes = 0;

void setup(){
  pinMode(pinoLido, INPUT);
  pinMode(pinoAlarme, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  estado = digitalRead(pinoLido);
  if(estado == LOW){
    digitalWrite(pinoAlarme, HIGH);
    Serial.print("Apertou ");
    Serial.println(quantasVezes);
    quantasVezes++;
  }else{
    digitalWrite(pinoAlarme, LOW);
  }
  
  delay(100);
  
  
  
}
