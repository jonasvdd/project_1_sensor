// Jonas Van Der Donckt, Mattijs Lotens

#ifndef PROJECT_1_SENSOR_LDR_H
#define PROJECT_1_SENSOR_LDR_H

#include "AnalogSensor.h"

#define MAX_ANALOG_VALUE 1023.0
#define FIELD_NAME "field1"

class LDR : public AnalogSensor {
private:
    float getLux();
public:
    /**
     * Constructor
     */
    LDR(uint8_t analogPin, uint8_t fieldID) : AnalogSensor(analogPin, fieldID) {}

    float getNormalizedSensorValue();
};


#endif
