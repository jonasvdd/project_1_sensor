#ifndef PROJECT_1_SENSOR_DHTSENSOR_H
#define PROJECT_1_SENSOR_DHTSENSOR_H

#include "dht.h"
#include "Sensor.h"

class DHTSensor : public Sensor {
private:
    uint8_t pin;
    dht DHT;
public:
    DHTSensor(uint8_t pin){
        this->pin = pin;
    }

    float getHumidity(){
        this->DHT.read11(this->pin);
        return this->DHT.humidity;
    }

    float getNormalizedSensorValue() {
        return this->getHumidity();
    }
};


#endif //PROJECT_1_SENSOR_DHTSENSOR_H
