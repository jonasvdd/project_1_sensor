#include "Smoke.h"


/**
 * Retrieve the normalized sensor value,
 * Will fire up the buzzer once smoke is detected
 */
float Smoke::getNormalizedSensorValue() {
    float sensorVal = AnalogSensor::getSensorValue();
    this->smoke_present = sensorVal > SMOKE_THRESHOLD;
    if (this->smoke_present) {
        digitalWrite(this->buzzerPin, HIGH);
    }
    else {
        digitalWrite(this->buzzerPin, LOW);
    }
    return sensorVal;
}

bool Smoke::isSmokePresent(){
    return this->smoke_present;
}