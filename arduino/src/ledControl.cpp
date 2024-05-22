#include <Arduino.h>
#include "ledControl.h"

void ledOn(int ledPin) {
    digitalWrite(ledPin, HIGH);
}

void ledOff(int ledPin) {
    digitalWrite (ledPin, LOW);
}