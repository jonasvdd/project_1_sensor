#include "RotaryEncoder.h"

uint8_t pinA;
uint8_t pinB;
uint8_t counter = 0;
uint8_t aState;
uint8_t aLastState;

RotaryEncoder::RotaryEncoder(uint8_t pina, uint8_t pinb) {
    // assign the pins and set them to input
    pinA = pina;
    pinB = pinb;

    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);

    aLastState = digitalRead(pinA);
    attachInterrupt(digitalPinToInterrupt(pinA), rotate_, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pinB), rotate_, CHANGE);
}

void rotate_() {
    aState = digitalRead(pinA);

    if (aState != aLastState) {
        if (digitalRead(pinB) != aState) {
            counter++;
        } else if (counter > 0) {
            counter--;
        }
        Serial.print("rotary counter: ");
        Serial.println(counter);
    }
    aLastState = aState;
}

float RotaryEncoder::getNormalizedSensorValue() {
    return counter;
}


