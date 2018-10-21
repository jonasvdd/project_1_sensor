#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB) {
    // assign the pins and set them to input
    this->pinA = pinA;
    this->pinB = pinB;

    pinMode(this->pinA, INPUT);
    pinMode(this->pinB, INPUT);

    this->aLastState = digitalRead(pinA);
    attachInterrupt(digitalPinToInterrupt(this->pinA), this->rotate, CHANGE);
    attachInterrupt(digitalPinToInterrupt(this->pinB), this->rotate, CHANGE);
}

void RotaryEncoder::rotate() {
    this->aState = digitalRead(this->pinA);

    if (this->aState != this->aLastState) {
        if (digitalRead(this->pinB) != this->aState) {
            this->counter++;
        } else if (this->counter > 0) {
            this->counter--;
        }
    }
    Serial.println("rotary counter: " + this->counter);
    this->aLastState = aState;
}

float RotaryEncoder::getNormalizedSensorValue() {
    return this->counter;
}


