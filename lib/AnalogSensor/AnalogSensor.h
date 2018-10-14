#ifndef PROJECT_1_SENSOR_ANALOGSENSOR_H
#define PROJECT_1_SENSOR_ANALOGSENSOR_H

#include "Arduino.h"

class AnalogSensor {
private:
    uint8_t pin;
    uint8_t fieldID;

    uint8_t getSensorValue();
public:
    AnalogSensor(uint8_t analogPin, uint8_t fieldID);

    uint8_t getFieldID();
    virtual float getNormalizedSensorValue();
};


#endif //PROJECT_1_SENSOR_ANALOGSENSOR_H
