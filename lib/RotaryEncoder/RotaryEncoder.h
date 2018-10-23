#ifndef PROJECT_1_SENSOR_ROTARYENCODER_H
#define PROJECT_1_SENSOR_ROTARYENCODER_H

#include "Sensor.h"
#include "Arduino.h"

/**
 * Representation of the rotary encoder
 */
class RotaryEncoder : public Sensor{
private:
public:
    /**
     * Creates an instance of the rotary encode
     *
     * @param pinA The first square wave signal pin of the encoder
     * @param pinB The second squar wavef signal pin of the encoder
     */
    RotaryEncoder(uint8_t pinA, uint8_t pinB);
    float getNormalizedSensorValue();
};

void rotate_();

#endif //PROJECT_1_SENSOR_ROTARYENCODER_H
