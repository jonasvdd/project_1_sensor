#include "AnalogSensor.h"


AnalogSensor::AnalogSensor(uint8_t analogPin) {
    this->pin = analogPin;
    pinMode(this->pin, INPUT);
}


uint16_t AnalogSensor::getSensorValue() {
    return uint16_t(analogRead(this->pin));
}