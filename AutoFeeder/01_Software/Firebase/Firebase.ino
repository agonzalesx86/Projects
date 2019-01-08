#define FIREBASE_HOST "https://autofeeder-79572.firebaseio.com/"
#define FIREBASE_AUTH "qb1DXBORTRWc7YtZWV5SW0pDxi1NoEUaFKgErDRk"

#define WIFI_SSID ""
#define WIFI_PASSWORD ""
# define LED 2 // change this to the correct pin.

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  digitalWrite(LED,0);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.setInt("LEDStatus",0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Firebase.getInt("LEDStatus")){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }

// Check for errors
  if(Firebase.failed()){
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return; 
  }
  delay(1000);
}
