#ifndef PROJECT_1_SENSOR_LDR_H
#define PROJECT_1_SENSOR_LDR_H

#include "AnalogSensor.h"

#define MAX_ANALOG_VALUE 1023.0
#define FIELD_NAME "field1"

/**
 * Representation of a Light Dependent Resistor
 */
class LDR : public AnalogSensor {
private:
    float getLux();
public:
    /**
     * Creates an instance of an LDR
     *
     * @param analogPin The anlog signal pin from the LDR module
     */
    LDR(uint8_t analogPin) : AnalogSensor(analogPin) {}

    float getNormalizedSensorValue();
};


#endif
