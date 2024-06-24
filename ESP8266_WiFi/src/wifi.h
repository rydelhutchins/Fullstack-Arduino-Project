#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>

extern const char* ssid;
extern const char* password;

void connectToWiFi();

#endif
