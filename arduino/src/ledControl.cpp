#include "ledControl.h"
#include <Arduino.h>

void ledOn(int ledPin) {
    digitalWrite(ledPin, HIGH); // Turn the LED on
}

void ledOff(int ledPin) {
    digitalWrite(ledPin, LOW); // Turn the LED off
}

void blinkLED(int ledPin, int frequency) { // Make LED Blink
    if (frequency > 0) {
        int delayTime = 1000 / frequency; // Calculate the delay time based on the frequency
        ledOn(ledPin);
        delay(delayTime / 2);
        ledOff(ledPin);
        delay(delayTime / 2);
    }
}
