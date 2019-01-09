
const int buttonPin = 2;
const int ledPin = 13;

int ledState = LOW;
int buttonState = LOW;
int lastButtonState = HIGH;
int reading;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(buttonPin);
  if (reading != lastButtonState){
    lastDebounceTime=millis();
    lastButtonState=reading;
  }

  if ((millis() - lastDebounceTime) > debounceDelay){
    if (buttonState != lastButtonState){
      buttonState = lastButtonState;
      if (buttonState == HIGH){
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }

}
