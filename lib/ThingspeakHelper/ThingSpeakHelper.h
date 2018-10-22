#ifndef PROJECT_1_SENSOR_THINGSPEAKHELPER_H
#define PROJECT_1_SENSOR_THINGSPEAKHELPER_H

#include "SoftwareSerial.h"
#include "RGBLed.h"
#include "Arduino.h"
#include "sstream"
#include "string"

using namespace std;


/***********************************
 *          CONSTANTS
 **********************************/
#define ROOT_URL                "api.thingspeak.com"
#define PORT                    80
#define LED_UPDATE_TIME_MS      500

class ThingSpeakHelper {
private:
    String API_key;
    int countTruecommand = 0;
    SoftwareSerial *esp8266;
    RGBLed *rgbLed;

    /**
     * Sends a command to an ESP8266 Wifi module
     *
     * @param command The command which will be sent to the ESP8266
     * @param maxTime The maximum time
     * @param readReplay Withholds the expected response of the command
     */
    boolean sendCommand(String command, int maxTime, char readReplay[]);

public:
    /**
     * Constructor
     *
     * @param rgbLed will display the status of the thingspeak API
     * @param RX The RX pin of the micro controller
     * @param TX  The TX pin of the micro controller
     * @param API_key The API key of the thingspeak channel so we can write values to it
     * @param SSID The SSID of the network
     * @param PASS The password of the network
     */
    ThingSpeakHelper(RGBLed * rgbLed, uint8_t RX, uint8_t TX, String API_key, String SSID, String PASS);


    /**
     * Sends
     * @param fieldID
     * @param sensorValue
     */
    void sendSensorValue(String fieldString);
};

#endif //PROJECT_1_SENSOR_THINGSPEAKHELPER_H
