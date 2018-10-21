#ifndef PROJECT_1_SENSOR_ANALOGSENSOR_H
#define PROJECT_1_SENSOR_ANALOGSENSOR_H

#include "Arduino.h"
#include "Sensor.h"

/**
 * Representation of an analog sensor with 1 pin
 */
class AnalogSensor : public Sensor  {
private:
    uint8_t pin;
protected:
    uint8_t getSensorValue();
public:
    /**
     * Constructor, creates an instance of an AnalogSensor
     * 
     * @param analogPin: The analog pin of the sensor
     */
    AnalogSensor(uint8_t analogPin);
    virtual float getNormalizedSensorValue() {};
};

#endif //PROJECT_1_SENSOR_ANALOGSENSOR_H
