
const int buttonPin = A13;
const int buttonPin_2 = A14;
const int ledPin = 4;
const int powerPin = 2;
const int lightPin = 3;

int ledState = LOW;
int lightState = LOW;
int buttonState = LOW;
int buttonState_2 = LOW;
int lastButtonState = HIGH;
int lastButtonState_2 = HIGH;
int reading;
int reading_2;

long lastDebounceTime = 0;
long lastDebounceTime_2 = 0;
long debounceDelay = 50;
long debounceDelay_2 = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  pinMode(buttonPin_2,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(powerPin,OUTPUT);
  pinMode(lightPin,OUTPUT);
  digitalWrite(powerPin,HIGH); //weird logic but this is needed to default the relay off.

}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(buttonPin);
  reading_2 = digitalRead(buttonPin_2);
  
  if (reading != lastButtonState){
    lastDebounceTime=millis();
    lastButtonState=reading;
  }

  if (reading_2 != lastButtonState_2){
    lastDebounceTime_2=millis();
    lastButtonState_2=reading_2;
  }

  if ((millis() - lastDebounceTime) > debounceDelay){
    if (buttonState != lastButtonState){
      buttonState = lastButtonState;
      if (buttonState == HIGH){
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        digitalWrite(powerPin, ledState);
      }
    }
  }

  if ((millis() - lastDebounceTime_2) > debounceDelay_2){
    if (buttonState_2 != lastButtonState_2){
      buttonState_2 = lastButtonState_2;
      if (buttonState_2 == HIGH){
        lightState = !lightState;
        digitalWrite(lightPin,lightState);
      }
    }
  }

}
