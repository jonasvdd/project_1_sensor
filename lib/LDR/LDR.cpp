#include "LDR.h"


float LDR::getLux() {
    return 250.0 * (0.005 *  AnalogSensor::getSensorValue()) - 50;
}

float LDR::getNormalizedSensorValue() {
    return this->getLux();
}
