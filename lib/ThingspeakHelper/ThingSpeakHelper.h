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

/**
 * Representation of a class with a sh*tload of helper
 * functions to bring a smile on your heart when working with
 * the ThingSpeak API.
 */
class ThingSpeakHelper {
private:
    String API_key;                 // The API write key
    String SSID;                    // Network SSID
    String PASS;                    // Network password
    int countTruecommand = 0;       // number of successfull consecutive commands executed
    SoftwareSerial *esp8266;        // Instance of a serial connection
    RGBLed *rgbLed;                 // To display status

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
     * Sends the field string to the corresponding thingspeak channel
     *
     * @param fieldString The string which can witthold sensor values for multiple
     *      fields. Hence less calls must be made and the application can be more
     *      efficient.
     */
    void sendSensorValue(String fieldString);
};

#endif //PROJECT_1_SENSOR_THINGSPEAKHELPER_H
