#include "ThingSpeakHelper.h"
// todo led library

/***********************************
 *          CONSTRUCTOR
 **********************************/
ThingSpeakHelper::ThingSpeakHelper(uint8_t RX, uint8_t TX, String API_key, String SSID, String PASS) {
    // todo include led.h
    this->API_key = API_key;

    this->esp8266 = new SoftwareSerial(RX, TX);
    esp8266->begin(9600);
    sendCommand("AT", 5, "OK");             // see if we get an OK response
    sendCommand("AT+CWMODE=1", 5, "OK");    // static mode
    boolean connected = sendCommand("AT+CWJAP=\"" + SSID + "\",\"" + PASS + "\"", 20, "OK");
    while (!connected){
        // todo: blink the RGB LED orange
        Serial.println("Trying to connect ...");
        connected = sendCommand("AT+CWJAP=\"" + SSID + "\",\"" + PASS + "\"", 20, "OK");    // connect to access point
    }
}


/***********************************
 *          PRIVATE METHODS
 **********************************/
boolean ThingSpeakHelper::sendCommand(String command, int maxTime, char readReplay[]) {
    Serial.print(this->countTruecommand);
    boolean found = false;
    int countTimeCommand = 0;
    while (this->countTimeCommand < (maxTime * 1)) {
        this->esp8266->println(command); //at+cipsend
        if (this->esp8266->find(readReplay))//ok
        {
            found = true;
            break;
        }
        this->countTimeCommand++;
    }

    Serial.print(".\tcommand: " + command);
    if (found) {
        Serial.println(" OK");
        this->countTruecommand++;
        // blink led green
        return false;
    } else {
        Serial.println(" Fail");
        this->countTruecommand = 0;
        // blink led orange
        return true;
    }
}


/***********************************
 *          PUBLIC METHODS
 **********************************/
void ThingSpeakHelper::sendSensorValue(String fieldString) {
    // String getData = "GET /update?api_key=" + this->API_key + "&field" + String(fieldID) + "=" + sensorValue;
    String getData = "GET /update?api_key=" + this->API_key + fieldString;
    sendCommand("AT+CIPMUX=1", 5, "OK");
    sendCommand("AT+CIPSTART=0,\"TCP\",\"" + String(ROOT_URL) + "\"," + String(PORT), 5, "OK");
    sendCommand("AT+CIPSEND=0," + String(getData.length() + 4), 10, ">");
    esp8266->println(getData);
    Serial.println("request: " + getData);
    this->countTruecommand++;
    sendCommand("AT+CIPCLOSE=0", 10, "OK");
}
