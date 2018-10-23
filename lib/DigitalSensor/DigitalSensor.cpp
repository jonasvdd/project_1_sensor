#include "DigitalSensor.h"


DigitalSensor::DigitalSensor(uint8_t digitalPin) {
    this->pin = digitalPin;
    pinMode(this->pin, INPUT);
}


uint16_t DigitalSensor::getSensorValue() {
    return uint16_t(digitalRead(this->pin));
}