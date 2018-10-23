#ifndef PROJECT_1_SENSOR_BMP185_H
#define PROJECT_1_SENSOR_BMP185_H

#include "Adafruit_BMP085_U.h"
#include "Sensor.h"

// ANALOG 5 and analog 4
#define SEA_LEVEL_PRESSURE_HPA 1020 /*IN hPa*/
// Todo: find an API which returns the sea level height of the corresponding location.

/**
 * Representation of the BMP185 and the BMP085 class.
 */
class BMP185 {
private:
    Adafruit_BMP085_Unified * bmp;
public:
    // constructor
    BMP185();

    // since a BMP withholds 3 (pressure, temperature and
    // altitude derived from those)
    // three Sensor objects will be created
    Sensor * altitudeSensor;
    Sensor * pressureSensor;
    Sensor * temperatureSensor;

    // getters
    float getTemperature();
    float getPressure();
    float getAltitude();
};

#endif //PROJECT_1_SENSOR_BMP180_H
