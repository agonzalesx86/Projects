 /*********************************************************
 * Speed Control Program using a Potentiometer
 * Description: This program uses a potentiometer to control
 * the PWM signal sent to the motor.
 **********************************************************/

#define motorpin 6
#define directionpin 7
#define potpin 0

int motorvalue = 0;
int forward = 1;
int reverse = 0;
int potvalue = 0; //variable to store the pot value
int potmotorval;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorpin, OUTPUT);
  pinMode(potpin, INPUT);

  // Set motors to zero speed and in the forward direction
  digitalWrite(directionpin,forward);
  analogWrite(motorpin,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  potvalue = analogRead(potpin);
  potmotorval = map(potvalue,0,714,0,255);
  Serial.print(potvalue);
  Serial.print("  ");
  Serial.println(potmotorval);
  analogWrite(motorpin,potmotorval);
  
}
