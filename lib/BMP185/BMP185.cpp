#include "BMP185.h"

/**
 * Constructor
 */
BMP185::BMP185() {
    // initialize the BMP
    this->bmp = new Adafruit_BMP085_Unified(10085);

    // create derived class for each type of sensor
    class AltitudeSensor : public Sensor{
    private:
        BMP185 * bmp185;
    public:
        AltitudeSensor(BMP185 * bmp185) : bmp185(bmp185) {}
        float getNormalizedSensorValue (){
            return this->bmp185->getAltitude();
        }
    };

    class PressureSensor : public Sensor{
    private:
        BMP185 * bmp185;
    public:
        PressureSensor(BMP185 * bmp185) : bmp185(bmp185) {}
        float getNormalizedSensorValue (){
            return this->bmp185->getPressure();
        }
    };

    class TemperatureSensor: public Sensor{
    private:
        BMP185 * bmp185;
    public:
        TemperatureSensor(BMP185 * bmp185) : bmp185(bmp185) {}
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

/**
 * @return The temperature in Celcius
 */
float BMP185::getTemperature(){
    // Get a new sensor event
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

/**
 * @return The air pressure in Hpa
 */
float BMP185::getPressure(){
    // Get a new sensor event
    sensors_event_t event;
    bmp->getEvent(&event);

    if (event.pressure) {
        // Display atmospheric pressue in kPa
        float pressurehPa = event.pressure * .1;
        return pressurehPa;
    }
    else {
        Serial.println("Sensor error!");
    }
}

/**
 * @return The altitude in meter
 */
float BMP185::getAltitude(){
    // Get a new sensor event
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
