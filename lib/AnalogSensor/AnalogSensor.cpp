#include "AnalogSensor.h"


AnalogSensor::AnalogSensor(uint8_t analogPin, uint8_t fieldID) {
    this->pin = analogPin;
    this->fieldID = fieldID;

    pinMode(this->pin, INPUT);
}


uint8_t AnalogSensor::getSensorValue() {
    return uint8_t(analogRead(this->pin));
}

uint8_t AnalogSensor::getFieldID() {
    return this->fieldID;
}