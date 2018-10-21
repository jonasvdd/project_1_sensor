#ifndef PROJECT_1_SENSOR_BMP185_H
#define PROJECT_1_SENSOR_BMP185_H

#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_BMP085_U.h"
#include "Arduino.h"
#include "Sensor.h"

// ANALOG 5 and analog 4

#define SEA_LEVEL_PRESSURE_HPA 1020 /*IN hPa*/
// Todo: find an API which returns the sea level height of the corresponding location.

class BMP185 {
private:
    Sensor * altitudeSensor;
    Sensor * pressureSensor;
    Sensor * temperatureSensor;
    Adafruit_BMP085_Unified * bmp;
public:
    BMP185();

    float getTemperature();
    float getPressure();
    float getAltitude();

    Sensor * getAltitudeSensor();
    Sensor * getPressureSensor();
    Sensor * getTemperatureSensor();
};

#endif //PROJECT_1_SENSOR_BMP180_H
