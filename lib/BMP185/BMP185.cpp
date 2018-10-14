// Created by jonas on 09/10/18.

#include "BMP185.h"

/**
 * Constructor
 * @param pressureID The id of the pressure field
 * @param temperatureID The id of the temperature field
 * @param altitudeID The id of the altitude field
 */
BMP185::BMP185(uint8_t pressureID, uint8_t temperatureID, uint8_t altitudeID) {
    this->pressureID = pressureID;
    this->altitudeID = altitudeID;
    this->temperatureID = temperatureID;
    this->bmp = new Adafruit_BMP085_Unified(10085);

    if(!this->bmp->begin())
    {
        /* There was a problem detecting the BMP085 ... check your connections */
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

/**
 * @return The air pressure in hPa
 */
float BMP185::getPressure(){
    /* Get a new sensor event */
    sensors_event_t event;
    bmp->getEvent(&event);

    /* Display the results (barometric pressure is measure in hPa) */
    if (event.pressure) {
        /* Display atmospheric pressue in hPa */
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

uint8_t BMP185::getTempID(){
    return this->temperatureID;
}

uint8_t BMP185::getPressureID(){
    return this->pressureID;
}

uint8_t BMP185::getAltitudeID(){
    return this->altitudeID;
}







