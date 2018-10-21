#ifndef PROJECT_1_SENSOR_SMOKE_H
#define PROJECT_1_SENSOR_SMOKE_H

#include "AnalogSensor.h"

#define SMOKE_THRESHOLD 100 // TODO 

/**
 * Representation of the smoke sensor,
 * Withholds a buzzer which will go off once the smoke sensor
 * surpasses a certain threshold. 
 */
class Smoke : public AnalogSensor {
private:
    bool smoke_present = false;
    uint8_t buzzerPin;
public:
    Smoke(uint8_t analogPin, uint8_t buzzerPin) : AnalogSensor(analogPin) {
        this->buzzerPin = buzzerPin;
        pinMode(this->buzzerPin, OUTPUT);
    }

    float getNormalizedSensorValue();
    bool isSmokePresent();
};


#endif //PROJECT_1_SENSOR_SMOKE_H
