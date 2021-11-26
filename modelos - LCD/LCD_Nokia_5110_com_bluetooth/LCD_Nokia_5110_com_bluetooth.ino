
//      SCK  - Pin 8
//      MOSI - Pin 9
//      DC   - Pin 10
//      RST  - Pin 11
//      CS   - Pin 12

#include <LCD5110_Basic.h>;
#include <SoftwareSerial.h>;

LCD5110 lcd(8,9,10,11,12);
SoftwareSerial btCom(6,7); // tx, rx
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void setup(){
  lcd.InitLCD();
  btCom.begin(9600);
  
  // len 14
  lcd.setFont(SmallFont);
  lcd.print("LCD NOKIA 5110", LEFT, 0);
  delay(1000);
  lcd.print("+ Bluetooth", LEFT, 8);
  delay(1000);
  lcd.print("by @jucabnu", RIGHT, 16);
  delay(1000);
  lcd.print("21/04/2014", CENTER, 32);
  delay(2000);
  lcd.clrScr();  
  
}

void loop(){

  String msg;
  lcd.setFont(SmallFont);  
  lcd.print("Msg via BT:", LEFT, 0);
 if(btCom.available()){
 msg = btCom.readString();
 lcd.print(msg, LEFT, 8);
 
 } 
  
}
  
  /*
  lcd.setFont(SmallFont);

//    lcd.clrScr();
    lcd.print("Juliano",LEFT,0);
    lcd.print("Henrique",RIGHT,8);
    lcd.print("Santos",CENTER,16);
    lcd.print("Vieira",LEFT,24);
    lcd.print("Teste",RIGHT,32);
    lcd.print("Hello Word",CENTER,40);
    delay(3000);
    lcd.clrScr();
    
    lcd.setFont(MediumNumbers);
    for(int i = 0; i < 100;i++){
      delay(100);
      lcd.clrScr();
      lcd.printNumI(i,CENTER,16);
    }
    
    lcd.clrScr();
    
    lcd.setFont(BigNumbers);
    for(int i = 0; i < 100;i++){
      delay(100);
      lcd.clrScr();
      lcd.printNumI(i,CENTER,8);
    }

        lcd.clrScr();

  
*/
  
  /*
  for (int i=0; i<=10000; i++)
  {
    lcd.setFont(MediumNumbers);
    lcd.printNumF(float(i)/3, 2, RIGHT, 0);
    lcd.setFont(BigNumbers);
    lcd.printNumI(i, RIGHT, 24);
  }
  
  lcd.setFont(SmallFont);
  lcd.print("|            |", CENTER, 16);
  delay(500);
  for (int i=0; i<12; i++)
  {
    lcd.print("\\", 6+(i*6), 16);
    delay(500);
  }
  lcd.clrScr();
  */
  
