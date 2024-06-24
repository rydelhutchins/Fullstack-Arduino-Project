#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "wifi.h"

ESP8266WebServer server(9898); // port 9898

// http://{8266_ip}:9898/<command>

void handleRoot() {
    server.send(200, "text/plain", "You've reached the ESP8266 server. Woohoo ~ !");
}

void handleLEDOn() {
    Serial.println("on");
    server.send(200, "text/plain", "LED is ON");
}

void handleLEDOff() {
    Serial.println("off");
    server.send(200, "text/plain", "LED is OFF");
}

void handleLEDBlink() {
    if (server.hasArg("freq")) {
        String freq = server.arg("freq");
        Serial.println("blink" + freq);
        server.send(200, "text/plain", "LED is blinking at " + freq + " Hz");
    } else {
        server.send(400, "text/plain", "Missing frequency parameter");
    }
}

void setup() {
    Serial.begin(9600);
    connectToWiFi();

    server.on("/", handleRoot);
    server.on("/on", handleLEDOn);
    server.on("/off", handleLEDOff);
    server.on("/blink", handleLEDBlink);
    server.begin();
}

void loop() {
    server.handleClient(); // Handle incoming client requests
}
