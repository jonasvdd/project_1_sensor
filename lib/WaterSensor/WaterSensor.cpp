#include "WaterSensor.h"

float WaterSensor::getNormalizedSensorValue() {
    Serial.println("watersensor, normalized value");
    return DigitalSensor::getSensorValue();
}