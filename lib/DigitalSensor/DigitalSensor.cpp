#include "DigitalSensor.h"


DigitalSensor::DigitalSensor(uint8_t digitalPin) {
    this->pin = digitalPin;
    pinMode(this->pin, INPUT);
}


uint8_t DigitalSensor::getSensorValue() {
    return uint8_t(digitalRead(this->pin));
}