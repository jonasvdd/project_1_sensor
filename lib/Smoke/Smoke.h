#ifndef PROJECT_1_SENSOR_SMOKE_H
#define PROJECT_1_SENSOR_SMOKE_H

#include "AnalogSensor.h"

#define SMOKE_THRESHOLD 100 // TODO 

class Smoke : public AnalogSensor {
private:
    bool smoke_present = false;
public:
    Smoke(uint8_t analogPin, uint8_t fieldID) : AnalogSensor(analogPin, fieldID) {}

    float getNormalizedSensorValue();

    bool getSmokePresent();
};


#endif //PROJECT_1_SENSOR_SMOKE_H
