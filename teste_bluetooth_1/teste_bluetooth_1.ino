#include <SoftwareSerial.h>
#include <LiquidCrystal.h>;
 
#define Reset 4
//#define LED 13
SoftwareSerial BTserial(2,3);
LiquidCrystal lcd(12,11,5,4,3,2);
 
int count=0;     // counter for buffer  array
String buffer; // buffer array for data recieve over serial port
 
void setup() {
  // initialize the digital pin as an output.
  //pinMode(LED, OUTPUT);
  pinMode(Reset, OUTPUT);
  Serial.begin(9600);
  BTserial.begin(9600);
  digitalWrite(Reset, LOW);
  // digitalWrite(LED, LOW);
  //pinMode(13, OUTPUT);
  //pinMode(12, OUTPUT);
  //pinMode(11, OUTPUT);
  lcd.begin(16,2);
  lcd.print("Teste com Bluetooth");
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print("HC-05 by Jucabnu");
  delay(3000);
  lcd.clear();
 
}
 
// the loop routine runs over and over again forever:
void loop() {
 
  readBT();
  count = 0;                       // set counter of while loop to zero
  buffer = "";  // clear all index of array with command NULL
  writeBT();
 
}
 
void readBT(){
 
  int i = 0;
  while (BTserial.available()) // if date from softwareserial Bt module
  {
    if(BTserial.available() > 0) // reading data into char array 
    {
      count++;
      char c = BTserial.read();
      if (c== '1'){
        lcd.setCursor(0,0);
        lcd.print("Digitou 1");
        delay(1000);
        lcd.clear();
      }
      if (c== '2'){
        lcd.setCursor(0,1);
        lcd.print("Digitou 2");
        delay(1000);
        lcd.clear();
      }
      if (c== '3'){
        lcd.setCursor(0,1);
        lcd.print("Limpou a tela");
        delay(1000);
        lcd.clear();
      };
    
      //if (c== '4') digitalWrite(13, LOW);
      //if (c== '5') digitalWrite(12, LOW);
      //if (c== '6') digitalWrite(11, LOW);
      
      buffer += c;
    }
  }
  Serial.print(buffer);
}
 
void writeBT(){
 
  if (Serial.available())  // if data on hardwareserial port PC or notebook
 
    BTserial.write(Serial.read());  // write it to the BT module
}
