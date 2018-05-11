 /******************************************************************************************
 * Speed Control Program using a Potentiometer
 * Description: This program uses a potentiometer to control
 * the PWM signal sent to the motor. This code will be used for educational purposes or for
 * testing the functionality of hardware.
 ********************************************************************************************/

#define motorpin 6
#define directionpin 7
#define potpin 0
#define encoderpin 1

int motorvalue = 0;
int forward = 1;
int reverse = 0;
int potvalue = 0; //variable to store the pot value
int potmotorval;
int encoderval;
int encoder;
float gain = 0.3;
int potcontrolval;
float error;
int motorinput;
int count = 0;
int encoderval_initial;
int motordirection;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorpin, OUTPUT);
  pinMode(potpin, INPUT);
  pinMode(encoderpin, INPUT);

  // Set motors to zero speed and in the forward direction
  digitalWrite(directionpin,forward);
  analogWrite(motorpin,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  potvalue = analogRead(potpin);
  encoder = analogRead(encoderpin); 
  encoderval = map(encoder,0,709,0,360);
  //encoderval_last = encoderval;
  
  if(count<1){
  encoderval_initial = encoderval;
  count = 1;
  }
  
  potmotorval = map(potvalue,0,714,0,255); // For speed control using the potentiometer
  potcontrolval = map(potvalue,0,714,0,360) + encoderval_initial;
  
  error = potcontrolval - encoderval;

  if(error>1){
    motordirection = 1;
  }
  else{
    motordirection = 0;
  }

  // Multiplying the error by the gain
  motorinput = gain*error; 

  // Saturation prevention to prevent the system from going unstable.
  if(abs(motorinput) > 90 ){
    motorinput = 0;
    Serial.print("%The motorinput has saturated!!!");
  }
  
  Serial.print(potcontrolval);
  Serial.print("  ");
  Serial.print(encoderval);
  Serial.print("  ");
  Serial.print(error);
  Serial.print("  ");
  Serial.println(motordirection);
  //Serial.print(motorinput);
  //Serial.print("  ");
  
  analogWrite(motorpin,potmotorval);
  //digitalWrite(directionpin,motordirection);
  
}
