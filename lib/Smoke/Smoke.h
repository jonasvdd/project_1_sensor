#ifndef PROJECT_1_SENSOR_SMOKE_H
#define PROJECT_1_SENSOR_SMOKE_H

#include "AnalogSensor.h"

class Smoke : public AnalogSensor {
private:
    uint8_t field_id()
public:
    Smoke(uint8_t analogPin, uint8_t fieldID) : AnalogSensor(analogPin, fieldID) {}

    float getNormalizedSensorValue();
};


#endif //PROJECT_1_SENSOR_SMOKE_H
