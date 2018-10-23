#ifndef PROJECT_1_SENSOR_DHTSENSOR_H
#define PROJECT_1_SENSOR_DHTSENSOR_H

#include "dht.h"
#include "Sensor.h"

/**
 * Representation of the humidity sensor part from a DHT sensor
 */
class DHTSensor : public Sensor {
private:
    uint8_t pin;
    dht DHT;
public:
    // Constructor
    DHTSensor(uint8_t pin){
        this->pin = pin;
    }

    /**
     * @return The relative humidity
     */
    float getHumidity(){
        this->DHT.read11(this->pin);
        return this->DHT.humidity;
    }

    /**
     * @return Concrete implementation of the abstract method
     */
    float getNormalizedSensorValue() {
        return this->getHumidity();
    }
};


#endif //PROJECT_1_SENSOR_DHTSENSOR_H
