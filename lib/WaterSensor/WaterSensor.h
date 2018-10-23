#ifndef PROJECT_1_SENSOR_WATERSENSOR_H
#define PROJECT_1_SENSOR_WATERSENSOR_H

#include "DigitalSensor.h"

/**
 * Representation of a water sensor
 */
class WaterSensor : public DigitalSensor {
public:
    /**
     * Creates an instance of a water sensor
     *
     * @param digitalPin The digital pin of the water sensor
     */
    WaterSensor(uint8_t digitalPin) : DigitalSensor(digitalPin) {}

    /**
     * @return The normalized sensor value, an overidden method from the
     *  super class.
     */
    float getNormalizedSensorValue();
};


#endif //PROJECT_1_SENSOR_WATERSENSOR_H
