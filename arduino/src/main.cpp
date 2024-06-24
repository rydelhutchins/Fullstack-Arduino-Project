#include <Arduino.h>
#include "ledControl.h"

const int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600); // 9600 baud
}

void loop() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        if (command == "on") {
            ledOn(ledPin); // Turn the LED on
        } else if (command == "off") {
            ledOff(ledPin); // Turn the LED off
        } else if (command.startsWith("blink")) {
            int frequency = command.substring(5).toInt();
            blinkLED(ledPin, frequency);
        }
    }
}

void blinkLED(int frequency) {
    if (frequency > 0) {
        int delayTime = 1000 / frequency; // Calculate the delay time based on the frequency
        ledOn(ledPin);
        delay(delayTime / 2);
        ledOff(delayTime / 2);
    }
}
