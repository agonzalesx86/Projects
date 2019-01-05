#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <WebSocketsServer.h>

// SSID and Password for WiFi Router
const char* ssid = "MySpectrumWiFib4-2G";
const char* password = "mellowbike771";

ESP8266WebServer server(80);
WebSocketServer webSocket(81); // create a websocket server on port 81

void handleRoot();
void handleLED();
void handleNotFound();
void handlePWM1();

// Pin definitions for MCU control
// Note: These definitions should be later moved to a header file for ease of use.
// Note: Certain digital I/O's should/cannot be used for control and are reserved.
const int led = 4;
const int power_pin = 1;
const int pwm_pin_1 = 1;
const int pwm_pin_2 = 1;

/*============================================ SETUP ============================================*/
// Setup block for the WiFi connection
// Include a handler function to blink LED once WiFi conenction is attempted/stays on once connected
void setup(void){
  Serial.begin(115200);
  startWebSocket();

  WiFi.begin(ssid, password);
  Serial.println("");

  // Setting the pin modes
  pinMode(led,OUTPUT);
  pinMode(power_pin,OUTPUT);
  pinMode(pwm_pin_1,OUTPUT);
  pinMode(pwm_pin_2,OUTPUT);
  
  // Begin with all pins off  
  digitalWrite(led,LOW);
  digitalWrite(power_pin,LOW);
  digitalWrite(pwm_pin_1,LOW);
  digitalWrite(pwm_pin_2,LOW);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Toggle the LEDs on
  digitalWrite(led,HIGH);
  delay(2000);

  server.on("/",HTTP_GET,handleRoot);
  server.on("/LED",HTTP_POST,handleLED);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

// Loop block for repeatedly executed code
void loop(void){
  server.handleClient();
}

/*====================================== HTTP HANDLER FUNCTIONS ======================================*/

// Defining the handling function to pass on to the server on function above once the ESP is connected to WiFi.
// Include the html control interface below to be able to control the peripherals.
void handleRoot(){
  server.send(200,"text/html","<!----------------------MAIN TITLE----------------------->\n<!--Generic Control Interface-->\n<html>\n<head>\n  <title> Generic Control Interface </title>\n</head>\n\n<body>\n  <div>\n    <h1>Generic Control Interface</h1>\n    <p><i>Description: This interface was created to be able to control various I/O using the ESP8266 over WiFi.</i></p>\n  </div>\n\n<div>\n  <h2>Control Set 1 (On/Off)</h2>\n  <form action = \"/LED\" method = \"POST\">\n    <input type=\"submit\" value=\"LED Control\">\n  </form>\n</div>\n\n\n</body>\n\n<!--Reserved for generic data recieved by ESP-->\n</html>");
}

void handleLED() {                          // If a POST request is made to URI /LED
  digitalWrite(led,!digitalRead(led));      // Change the state of the LED
  server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

// Handling function if a page other than the above pages is attempted to access.
void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}


void handlePWM1(){
  analogWrite(pwm_pin_1,duty_val);
  server.sendHeader("Location","/");
  server.send(303);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) { // When a WebSocket message is received
  switch (type) {
    case WStype_DISCONNECTED:             // if the websocket is disconnected
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {              // if a new websocket connection is established
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
        rainbow = false;                  // Turn rainbow off when a new connection is established
      }
      break;
    case WStype_TEXT:                     // if new text data is received
      Serial.printf("[%u] get Text: %s\n", num, payload);
      if (payload[0] == '#') {            // we get RGB data
        uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);   // decode rgb data
        int r = ((rgb >> 20) & 0x3FF);                     // 10 bits per color, so R: bits 20-29
        int g = ((rgb >> 10) & 0x3FF);                     // G: bits 10-19
        int b =          rgb & 0x3FF;                      // B: bits  0-9

        analogWrite(LED_RED,   r);                         // write it to the LED output pins
        analogWrite(LED_GREEN, g);
        analogWrite(LED_BLUE,  b);
      } else if (payload[0] == 'R') {                      // the browser sends an R when the rainbow effect is enabled
        rainbow = true;
      } else if (payload[0] == 'N') {                      // the browser sends an N when the rainbow effect is disabled
        rainbow = false;
      }
      break;
  }
} 


/*========================================== SETUP FUNCTIONS ==========================================*/

void startWebSocket() { // Start a WebSocket server
  webSocket.begin();                          // start the websocket server
  webSocket.onEvent(webSocketEvent);          // if there's an incomming websocket message, go to function 'webSocketEvent'
  Serial.println("WebSocket server started.");
}

