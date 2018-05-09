#include <Servo.h>

Servo servo1;

int servopin 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(servopin,OUTPUT);
  servo1.attach(14); //analog pin 0
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
