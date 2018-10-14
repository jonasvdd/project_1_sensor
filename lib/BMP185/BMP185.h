#ifndef PROJECT_1_SENSOR_BMP185_H
#define PROJECT_1_SENSOR_BMP185_H

#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_BMP085_U.h"
#include "Arduino.h"

// ANALOG 5 and analog 4

#define SEA_LEVEL_PRESSURE_HPA 1020 /*IN hPa*/

class BMP185 {
private:
    uint8_t altitudeID;
    uint8_t pressureID;
    uint8_t temperatureID;
    Adafruit_BMP085_Unified * bmp;
public:
    BMP185(uint8_t pressureID,uint8_t temperatureID,  uint8_t altitudeID);

    float getTemperature();
    float getPressure();
    float getAltitude();

    uint8_t getTempID();
    uint8_t getPressureID();
    uint8_t getAltitudeID();
};

#endif //PROJECT_1_SENSOR_BMP180_H
