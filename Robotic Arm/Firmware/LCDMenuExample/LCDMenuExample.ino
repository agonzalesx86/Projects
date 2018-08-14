#include <LiquidCrystal.h>
//LiquidCrystal lcd(); //specify the pins for te LCD display

int menusize = 10;
String menu[] = {
  "Menu",                 //0
  "Menu>LED",             //1
  "Menu>LED>OFF",         //2
  "Menu>LED>ON",          //3
  "Menu>LED>FADE",        //4
  "Menu>LED>BLINK",       //5
  "Menu>LCDLIGHT",        //6
  "Menu>NOTHING1",        //7
  "Menu>NOTHING2",        //8
  "Menu>NOTHING3",        //9
}

int t;
byte pressedButton, currentPosParent, possiblePos[20], possiblePosCount, possiblePosScroll = 0;
String parent = "";

int brightness;
int LCDtoggle = 0;
int fadeamount = 5;
unsigned long time = (millis() / 10);
int ledMode = 0;

void updateMenu(){
  possiblePosCount ==0;
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
