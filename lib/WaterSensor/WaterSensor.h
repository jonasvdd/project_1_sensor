#ifndef PROJECT_1_SENSOR_WATERSENSOR_H
#define PROJECT_1_SENSOR_WATERSENSOR_H

#include "DigitalSensor.h"

// Representation of a water sensor
class WaterSensor : public DigitalSensor {
public:
    WaterSensor(uint8_t analogPin) : DigitalSensor(analogPin) {}
    float getNormalizedSensorValue();
};


#endif //PROJECT_1_SENSOR_WATERSENSOR_H
