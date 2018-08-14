#include <Servo.h>

Servo servo;
Servo servo2;

int servoPin = 9;
int servoPin2 = 10;
int angle = 0;
int JSPin = 2;
int RyPin = A0;
int RxPin = A1;
int button;
int baseangle = 0;
int anlgval1;
int anlgval2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(JSPin,INPUT);
  pinMode(RyPin,INPUT);
  pinMode(RxPin,INPUT);
  servo.attach(servoPin); //analog pin 0
  servo2.attach(servoPin2);
  servo.write(90);
  servo2.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //servo.write(0);
  /*
  delay(1000);
  
  for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
  for(angle = 180; angle>=1; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(1000);
    */
    anlgval1 = analogRead(RyPin);
    anlgval2 = analogRead(RxPin);
    baseangle = map(anlgval1,0,1023,0,180);
    int deltatheta = baseangle-90;
    int theta2 = 90-deltatheta;
    servo.write(baseangle);
    servo2.write(theta2);
    button = digitalRead(JSPin);
  //end control the servo's speed
  Serial.print(button);
  Serial.print(" "); 
  Serial.print(baseangle);
  Serial.print(" ");
  Serial.println(anlgval1);
  
  
}
