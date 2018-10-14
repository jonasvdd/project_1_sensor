#ifndef PROJECT_1_SENSOR_WATERSENSOR_H
#define PROJECT_1_SENSOR_WATERSENSOR_H

#include "DigitalSensor.h"

class WaterSensor : public DigitalSensor {
public:
    WaterSensor(uint8_t analogPin, uint8_t fieldID) : DigitalSensor(analogPin, fieldID) {}

    float getNormalizedSensorValue();
};


#endif //PROJECT_1_SENSOR_WATERSENSOR_H
