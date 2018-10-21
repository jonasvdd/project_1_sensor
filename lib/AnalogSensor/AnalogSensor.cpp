#include "AnalogSensor.h"


AnalogSensor::AnalogSensor(uint8_t analogPin) {
    this->pin = analogPin;
    pinMode(this->pin, INPUT);
}


uint8_t AnalogSensor::getSensorValue() {
    return uint8_t(analogRead(this->pin));
}