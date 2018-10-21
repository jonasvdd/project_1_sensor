#ifndef PROJECT_1_SENSOR_ROTARYENCODER_H
#define PROJECT_1_SENSOR_ROTARYENCODER_H

#include "Sensor.h"
#include "Arduino.h"

/**
 * Representation of the rotary encoder
 */
class RotaryEncoder : public Sensor{
private:
    uint8_t pinA;
    uint8_t pinB;
    uint8_t counter = 0;
    uint8_t aState;
    uint8_t aLastState;
public:
    RotaryEncoder(uint8_t pinA, uint8_t pinB);

    float getNormalizedSensorValue();
    void rotate();
};


#endif //PROJECT_1_SENSOR_ROTARYENCODER_H
