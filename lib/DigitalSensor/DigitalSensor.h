#ifndef PROJECT_1_SENSOR_DIGITALSENSOR_H
#define PROJECT_1_SENSOR_DIGITALSENSOR_H

#include "Arduino.h"

class DigitalSensor {
private:
    uint8_t pin;
    uint8_t fieldID;
protected:
    uint8_t getSensorValue();
public:
    DigitalSensor(uint8_t analogPin, uint8_t fieldID);

    uint8_t getFieldID();
    virtual float getNormalizedSensorValue() {};
};


#endif //PROJECT_1_SENSOR_DIGITALSENSOR_H
