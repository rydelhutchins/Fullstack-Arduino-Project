#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>

// Declare your WiFi credentials
extern const char* ssid;
extern const char* password;

// Declare the function to connect to WiFi
void connectToWiFi();

#endif // WIFI_H
