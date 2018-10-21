// Created by jonas on 13/10/18.

#include "Smoke.h"

float Smoke::getNormalizedSensorValue() {
    float sensorVal = AnalogSensor::getSensorValue();

    if (sensorVal > SMOKE_THRESHOLD){
        this->smoke_present = true;
    } else {
        this->smoke_present = false;
    }
    return sensorVal;
}

bool Smoke::getSmokePresent(){
    return this->smoke_present;
}