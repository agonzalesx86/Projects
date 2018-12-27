
/*
Info that will need to get worked out in the software:
- scheduling
- app control
- switching between manual control and automated timing

Need to being establishing the logic for switching between the two modes of operating.
1. manual mode (user requests a feed through an app or something). may need to use an analog input to keep it simple and get it going.
2. automated scheduling mode based on a schedule originally set by a user.

First version:
- user input from an analog HIGH from a physical tactile button which will be the trigger. Some implementation to prevent toggle will be needed as well.
note: will need to define states as well.

*/

#include "main.h"


/* constants */
const int buttonPin=1;
const int motorpwmPin = 2;

/* calibrations and variables */
int buttonState;
float motorpwmRR = 1; // deg/sec
float motorpwmFR = 1; // deg/sec
float motordutyCmd = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorpwmPin,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  requestMonitor();
  if(buttonState==HIGH){
    feed();
  }
}



/*========================================================*/
/********************FUNCTIONS*****************************/
/*========================================================*/


void feed_basic(){
  // might need to implement a ramp up function when turning on the motor or a rate limiter.
  analogWrite(motorpwmPin,HIGH);
}

void feed(){
  motordutyCmd = final_lmting(motorpwmRR,);
  t1 = millis();
}

float final_lmting(rr,x1,t1){
  t2 = millis()
  x_fnl = rr*(t2-t1) + x1;  
  return x_fnl
}

void requestMonitor(){
  digitalRead(buttonPin);
}
