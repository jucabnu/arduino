const int alarme = 8;
const int grampo = 0;
int estado = 0;

void setup(){
  pinMode(alarme, OUTPUT);
  //pinMode(grampo, INPUT);
  Serial.begin(9600);
}

void loop(){

    //estado = digitalRead(grampo);
    estado = analogRead(grampo);
    //delay(1000);
    Serial.println(estado);
    
    if(estado == 1023){
      digitalWrite(alarme, HIGH);
    }else{
      digitalWrite(alarme, LOW);
    }



}

