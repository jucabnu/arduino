#include <Servo.h> 
 
Servo servoR;
Servo servoL;
int left = 0;
int right = 0;

void setup() 
{ 
  servoR.attach(9);
  servoL.attach(10);
} 
 
void loop() 
{   
} 

void vaiParaFrente(int voltas){
  
  for(int i = 0; i <= voltas; i++){
    servoD.write(i);
    servoL.write(i);
  }  
}

void giroCopletoParaFrenteRL(){
  for(int i = 0; i <= 360; i++){
    servoR.write(i);
    servoL.write(i);
    delay(400);
  }
}

void vaiParaTras(){
  for(int i = 360; i >= 0; i--){
    servoD.write(i);
    servoL.write(i);
  }
}

void viraParaDireita(){ // +/- 90 graus

  int l = 0;
  int r = 90;

  while(l < 90 && r > 0){    
    servoR.write(l);
    l++;
    servoL.write(r);
    r--;    
  }
}

void viraParaEsquerda(){ // +/- 90 graus

}


//  val = map(val, 0, 1023, 0, 179);
