#include "ThingSpeakHelper.h"


/***********************************
 *          CONSTRUCTOR
 **********************************/
ThingSpeakHelper::ThingSpeakHelper(RGBLed *rgbLed, uint8_t RX, uint8_t TX, String API_key, String SSID, String PASS) {
    this->rgbLed = rgbLed;
    this->API_key = API_key;
    this->SSID = SSID;
    this->PASS = PASS;
    this->esp8266 = new SoftwareSerial(RX, TX);
    this->rgbLed->blink(Color(100, 100, 100), 300);
    esp8266->begin(9600);
    sendCommand("AT", 5, "OK");                         // see if we get an OK response
    sendCommand("AT+CWMODE=1", 5, "OK");                // static mode
    boolean connected = sendCommand("AT+CWJAP=\"" + SSID + "\",\"" + PASS + "\"", 15, "OK");
    while (!connected) {
        this->rgbLed->blink(Color(100, 10, 0),400);       // ORANGE
        Serial.println("Trying to connect ...");
        sendCommand("AT+CWJAP=\"" + SSID + "\",\"" + PASS + "\"", 5, "OK");    // connect to access point
    }
}


/***********************************
 *          PRIVATE METHODS
 **********************************/
boolean ThingSpeakHelper::sendCommand(String command, int maxTime, char readReplay[]) {
    Serial.print(this->countTruecommand);
    Serial.print(".\tcommand: " + command);
    boolean found = false;
    int countTimeCommand = 0;
    while (countTimeCommand < (maxTime * 1)) {
        this->esp8266->println(command);                //at+cipsend
        if (this->esp8266->find(readReplay))            //ok
        {
            found = true;
            break;
        }
        countTimeCommand++;
    }

    if (found) {
        Serial.println(" OK");
        this->countTruecommand++;
        this->rgbLed->blink(Color(0, 50, 0), 30);           // GREEN --> OK
        return true;
    } else {
        Serial.println(" Fail");
        this->countTruecommand = 0;
        this->rgbLed->blink(Color(100, 0, 0), 200);           // RED --> OK
        return false;
    }
}


/***********************************
 *          PUBLIC METHODS
 **********************************/
void ThingSpeakHelper::sendSensorValue(String fieldString) {
    sendCommand("AT+CIPMUX=1", 5, "OK");
    if (sendCommand("AT+CIPSTART=0,\"TCP\",\"" + String(ROOT_URL) + "\"," + String(PORT), 5, "OK")){
        String getData = "GET /update?api_key=" + this->API_key;
        getData += fieldString;

        String command = "AT+CIPSEND=0,";
        command +=  String(getData.length() + 4);
        sendCommand(command, 10, ">");

        // String getData = "GET /update?api_key=" + this->API_key + "&field" + String(fieldID) + "=" + sensorValue;
        esp8266->println(getData);
        Serial.println(getData);
        this->countTruecommand++;
        sendCommand("AT+CIPCLOSE=0", 10, "OK");
    } else {
        Serial.println("Could not make an TCP connection with thingspeak, sorry bro!!");
        sendCommand("AT+CWJAP=\"" + this->SSID + "\",\"" + this->PASS + "\"", 15, "OK");    // connect to access point
    }
}
