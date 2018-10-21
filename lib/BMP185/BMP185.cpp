#include "BMP185.h"

/**
 * Constructor
 *
 * @param pressureID The id of the pressure field
 * @param temperatureID The id of the temperature field
 * @param altitudeID The id of the altitude field
 */
BMP185::BMP185() {
    this->bmp = new Adafruit_BMP085_Unified(10085);

    class AltitudeSensor : public Sensor{
    private:
        BMP185 * bmp185;
    public:
        AltitudeSensor(BMP185 * bmp185){
            this->bmp185 = bmp185;
        }
        float getNormalizedSensorValue (){
            return this->bmp185->getAltitude();
        }
    };

    class PressureSensor : public Sensor{
    private:
        BMP185 * bmp185;
    public:
        PressureSensor(BMP185 * bmp185){
            this->bmp185 = bmp185;
        }

        float getNormalizedSensorValue (){
            return this->bmp185->getPressure();
        }
    };

    class TemperatureSensor: public Sensor{
    private:
        BMP185 * bmp185;
    public:
        TemperatureSensor(BMP185 * bmp185){
            this->bmp185 = bmp185;
        }
        float getNormalizedSensorValue (){
            return this->bmp185->getTemperature();
        }
    };


    this->altitudeSensor = new AltitudeSensor(this);
    this->pressureSensor = new PressureSensor(this);
    this->temperatureSensor = new TemperatureSensor(this);

    if(!this->bmp->begin()) {
        Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
    }
}

float BMP185::getTemperature(){
    /* Get a new sensor event */
    sensors_event_t event;
    bmp->getEvent(&event);

    if (event.temperature){
        float temperature;
        this->bmp->getTemperature(&temperature);
        return temperature;
    } else {
        Serial.println("Sensor error!");
    }
}

float BMP185::getPressure(){
    /* Get a new sensor event */
    sensors_event_t event;
    bmp->getEvent(&event);

    /* Display the results (barometric pressure is measure in hPa) */
    if (event.pressure) {
        /* Display atmospheric pressue in kPa */
        float pressurehPa = event.pressure * .1;
        return pressurehPa;
    }
    else {
        Serial.println("Sensor error!");
    }
}

float BMP185::getAltitude(){
    /* Get a new sensor event */
    sensors_event_t event;
    bmp->getEvent(&event);

    if (event.pressure){
        float temperature;
        this->bmp->getTemperature(&temperature);
        float altitude = this->bmp->pressureToAltitude(SEA_LEVEL_PRESSURE_HPA, event.pressure, temperature);
        return altitude;
    } else {
        Serial.println("Sensor error!");
    }
}


Sensor * BMP185::getAltitudeSensor(){
    return this->altitudeSensor;
}

Sensor * BMP185::getPressureSensor(){
    return this->pressureSensor;
}

Sensor *  BMP185::getTemperatureSensor(){
    this->temperatureSensor;
}