#include <ShiftLCD.h>

const byte dataPin  = 2;    // SR Data from Arduino pin 10
const byte clockPin = 4;    // SR Clock from Arduino pin 11

ShiftLCD srlcd(dataPin, clockPin, 3);

void setup()
{
  // Turn on backlight (if used)
  srlcd.backlightOn();
  
  // Print a message to the LCD.
  srlcd.print("HELLO, WORLD!");
}

void loop()
{
}
