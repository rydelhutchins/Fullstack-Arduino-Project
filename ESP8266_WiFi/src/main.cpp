#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "wifi.h"

ESP8266WebServer server(80);

void handleRoot() {
  String message = "LED Control";
  if (server.hasArg("state")) {
    String state = server.arg("state");
    Serial.println(state); // Send the state to Arduino
    message += "\nLED state: " + state;
  }
  server.send(200, "text/plain", message);
}

void setup() {
  Serial.begin(9600); // Communication with Arduino
  connectToWiFi(); // Connect to WiFi

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
