#ifndef PROJECT_1_SENSOR_ANALOGSENSOR_H
#define PROJECT_1_SENSOR_ANALOGSENSOR_H

#include "Arduino.h"
#include "Sensor.h"

/**
 * Representation of an analog sensor with 1 pin,
 * Implements the Sensor interface.
 */
class AnalogSensor : public Sensor  {
private:
    uint8_t pin;
protected:
    uint16_t getSensorValue();
public:
    /**
     * Constructor, creates an instance of an AnalogSensor
     *
     * @param analogPin: The analog pin of the sensor
     */
    AnalogSensor(uint8_t analogPin);

    /**
     * Abstract method which returns the Sensor value,
     * Will be implemented in the subclasses
     */
    virtual float getNormalizedSensorValue() {};
};

#endif //PROJECT_1_SENSOR_ANALOGSENSOR_H
