#ifndef PROJECT_1_SENSOR_DIGITALSENSOR_H
#define PROJECT_1_SENSOR_DIGITALSENSOR_H

#include "Arduino.h"
#include "Sensor.h"

/**
 * Representation of a digital sensor
 */
class DigitalSensor : public Sensor {
private:
    uint8_t pin;
protected:
    uint16_t getSensorValue();
public:
    /**
     * Constructor, creates an instance of a DigitalSensor
     * 
     * @param analogPin: The analog pin of the sensor
     * @param fieldID: The thingspeak field ID of the host
     */
    DigitalSensor(uint8_t digitalPin);

    /**
     * @return Abstract method which will be further specified
     * in derived classes
     */
    virtual float getNormalizedSensorValue() {};
};


#endif //PROJECT_1_SENSOR_DIGITALSENSOR_H
