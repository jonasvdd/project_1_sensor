#include "DigitalSensor.h"


DigitalSensor::DigitalSensor(uint8_t analogPin, uint8_t fieldID) {
    this->pin = analogPin;
    this->fieldID = fieldID;

    pinMode(this->pin, INPUT);
}


uint8_t DigitalSensor::getSensorValue() {
    return uint8_t (digitalRead(this->pin));
}