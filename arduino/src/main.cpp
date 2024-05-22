#include <Arduino.h>
#include "ledControl.h"

// put function declarations here:
int ledPin = 13;
String command;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    if (incomingByte == '\n') {
      if (command == "1") {
        ledOn(ledPin);
      } else if (command == "0") {
        ledOff(ledPin);
      }
      command = "";
    } else {
      command += incomingByte;
    }
  }
}