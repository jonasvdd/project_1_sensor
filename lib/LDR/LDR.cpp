// Created by jonas on 09/10/18.

#include "LDR.h"


float LDR::getLux() {
    //Serial.println("lux: ");
    //Serial.println(AnalogSensor::getSensorValue());
    return 250.0 * (0.005 *  AnalogSensor::getSensorValue()) - 50;
}

float LDR::getNormalizedSensorValue() {
    return this->getLux();
}
