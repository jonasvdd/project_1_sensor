#ifndef PROJECT_1_SENSOR_SENSOR_H
#define PROJECT_1_SENSOR_SENSOR_H

/**
 * Sensor interface
 */
class Sensor {
public:
    /**
     * @return A normalized value of the sensor interface
     */
    virtual float getNormalizedSensorValue() {};
};


#endif //PROJECT_1_SENSOR_SENSOR_H
