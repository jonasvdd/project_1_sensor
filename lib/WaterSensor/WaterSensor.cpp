#include "WaterSensor.h"

float WaterSensor::getNormalizedSensorValue() {
    return DigitalSensor::getSensorValue();
}