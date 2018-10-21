#ifndef PROJECT_1_SENSOR_DHTSENSOR_H
#define PROJECT_1_SENSOR_DHTSENSOR_H

#include "dht.h"

class DHTSensor {
private:
    uint8_t field_id;
    uint8_t pin;
    dht DHT;
public:
    DHTSensor(uint8_t pin, uint8_t field_id){
        this->pin = pin;
        this->field_id = field_id;
    }

    float getHumidity(){
        int chk = this->DHT.read11(this->pin);
        return this->DHT.humidity;
    }

    uint8_t getFieldID(){
        return this->field_id;
    }
};


#endif //PROJECT_1_SENSOR_DHTSENSOR_H
