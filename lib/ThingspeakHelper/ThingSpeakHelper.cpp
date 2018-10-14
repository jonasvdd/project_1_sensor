#include "ThingSpeakHelper.h"

/***********************************
 *          CONSTRUCTOR
 **********************************/
ThingSpeakHelper::ThingSpeakHelper(uint8_t RX, uint8_t TX, String API_key, String SSID, String PASS) {
    this->API_key = API_key;

    this->esp8266 = new SoftwareSerial(RX, TX);
    esp8266->begin(115200);

    sendCommand("AT", 5, "OK");             // see if we get an OK response
    sendCommand("AT+CWMODE=1", 5, "OK");    // static mode
    sendCommand("AT+CWJAP=\"" + SSID + "\",\"" + PASS + "\"", 20, "OK");    // connect to access point
}


/***********************************
 *          PRIVATE METHODS
 **********************************/
void ThingSpeakHelper::sendCommand(String command, int maxTime, char readReplay[]) {
    Serial.print(this->countTruecommand);
    boolean found = false;
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
        this->countTimeCommand = 0;
    } else {
        Serial.println(" Fail");
        this->countTruecommand = 0;
        this->countTimeCommand = 0;
    }
}


/***********************************
 *          PUBLIC METHODS
 **********************************/
void ThingSpeakHelper::sendSensorValue(uint8_t fieldID, String sensorValue) {
    String getData = "GET /update?api_key=" + this->API_key + "&field" + String(fieldID) + "=" + sensorValue;
    Serial.println(getData);
    sendCommand("AT+CIPMUX=1", 5, "OK");
    sendCommand("AT+CIPSTART=0,\"TCP\",\"" + String(ROOT_URL) + "\"," + String(PORT), 15, "OK");
    sendCommand("AT+CIPSEND=0," + String(getData.length() + 10), 10, ">");
    esp8266->println(getData);
    delay(1000);
    this->countTruecommand++;
    sendCommand("AT+CIPCLOSE=5", 10, "OK");
}
