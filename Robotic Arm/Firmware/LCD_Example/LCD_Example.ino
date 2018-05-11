#include <LiquidCrystal.h>

//initilize the library by providing the number of pins to it
LiquidCrystal lcd(8,9,4,5,6,7);


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

  // set cursor position to start of first line on the LCD
  lcd.setCursor(0,0);
  // text to print
  lcd.print("   16x2,");
  // set cursor position to start of next line
  lcd.setCursor(0,1);
  lcd.print("   Display");
}

void loop() {
  // put your main code here, to run repeatedly:

}
