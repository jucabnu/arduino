
const int button = 8;
const int pinLed = 13;

void setup(){

  pinMode(button, INPUT);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(pinLed, LOW);
  int state = 0;



}

void loop(){

  
    state = digitalRead(button);
    if(state == 1){
      digitalWrite(pinLed, HIGH);
    }else{
      digitalWrite(pinLed, LOW);
      
      Serial.println(state);
    }


  

}
