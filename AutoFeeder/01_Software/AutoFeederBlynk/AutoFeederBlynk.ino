/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/
/* REFER TO THE I/O MAP INCLUDED IN THIS FOLDER */

/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WidgetRTC.h>
#include <TimeLib.h>

/* WiFi Setup */
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b59a512b48d5439b95c4a469a8a3b0bd";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MySpectrumWiFib4-2G";
char pass[] = "";

/* Initial Setup and declarations */
WidgetRTC rtc;
int motorPin = 1;
int motorRunTime = 3000; // in milliseconds
int num_feeds = 10;
int manReq = 0;
int autoReq = 0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // Begin synchronizing time
  rtc.begin();

  // Add features here later to initialize any display values on the UI
  //Blynk.virtualWrite(
  //Blynk.virtualWrite(V1, val);
  Blynk.virtualWrite(V1,num_feeds);
}


BLYNK_WRITE(V0){
  int manReq = 1;
}

void feedRoutine(){
  digitalWrite(motorPin,HIGH);
  delay(motorRunTime);
  digitalWrite(motorPin,LOW);
  num_feeds = num_feeds-1;
  Blynk.virtualWrite(V1,num_feeds);
}

void requestMonitor(){
  if(manReq == 1 || autoReq == 1){
    feedRoutine();
    manReq = 0;
    autoReq = 0;
  }
}

void loop()
{
  Blynk.run();
  requestMonitor();
}
