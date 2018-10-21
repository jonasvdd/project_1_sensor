#ifndef PROJECT_1_SENSOR_SMOKE_H
#define PROJECT_1_SENSOR_SMOKE_H

#include "AnalogSensor.h"

#define SMOKE_THRESHOLD 100 // TODO 

class Smoke : public AnalogSensor {
private:
    bool smoke_present = false;

    uint8_t buzzerPin;
public:
    Smoke(uint8_t analogPin, uint8_t buzzerPin, uint8_t fieldID) : AnalogSensor(analogPin, fieldID) {
        this->buzzerPin = buzzerPin;
    }

    float getNormalizedSensorValue();

    bool getSmokePresent();
};


#endif //PROJECT_1_SENSOR_SMOKE_H
