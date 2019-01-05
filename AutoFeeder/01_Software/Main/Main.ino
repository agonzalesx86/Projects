
/*
Info that will need to get worked out in the software:
- scheduling
- app control
- switching between manual control and automated timing

Need to being establishing the logic for switching between the two modes of operating.
1. manual mode (user requests a feed through an app or something). may need to use an analog input to keep it simple and get it going.
2. automated scheduling mode based on a schedule originally set by a user.

Make sure to set the pins and board first before deploying this code***

*/

#include "main.h"


/* constants */
const int buttonPin=1;
const int motorpwmPin = 2;

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
}



/*========================================================*/
/********************FUNCTIONS*****************************/
/*========================================================*/

void requestMonitor(){
  int request = digitalRead(buttonPin);
  if(request==HIGH){
    analogWrite(motorpwmPin,50);
  }
  else{
    digitalWrite(motorpwmPin,0);
  }
}
