
/*
Info that will need to get worked out in the software:
- scheduling
- app control
- switching between manual control and automated timing

Need to being establishing the logic for switching between the two modes of operating.
1. manual mode (user requests a feed through an app or something). may need to use an analog input to keep it simple and get it going.
2. automated scheduling mode based on a schedule originally set by a user.

Make sure to set the pins and board first before deploying this code***
** Should not assume the motor will simply already be driven (simplest is to manually drive a HIGH output through the driving pin)

*/

#include "main.h"


/* constants */
const int buttonPin=D4;
const int motorpwmPin = D2;

/* calibrations and variables */
int buttonState; // an enumeration should be used eventually for this button state.
float motordutyCmd = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorpwmPin,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  requestMonitor();
  //digitalWrite(motorpwmPin,LOW);
  
}



/*========================================================*/
/********************FUNCTIONS*****************************/
/*========================================================*/

void requestMonitor(){
  int request = digitalRead(buttonPin);
  if(request==HIGH){
    digitalWrite(motorpwmPin,HIGH);
    delay(4000);
  }
  else{
    digitalWrite(motorpwmPin, LOW);
  }
}
