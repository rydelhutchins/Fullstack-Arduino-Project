#include "ledControl.h"
#include <Arduino.h>

void ledOn(int ledPin) {
    digitalWrite(ledPin, HIGH); // LED on
}

void ledOff(int ledPin) {
    digitalWrite(ledPin, LOW); // LED off
}

void blinkLED(int ledPin, int frequency) { // LED Blink -- work in progress
    if (frequency > 0) {
        int delayTime = 1000 / frequency;
        ledOn(ledPin);
        delay(delayTime / 2);
        ledOff(ledPin);
        delay(delayTime / 2);
    }
}
