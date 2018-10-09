///
// Created by jonas on 25/09/18.
//
#include "Arduino.h"
#include "ThingSpeak.h"
//#include "ESP8266WiFi.h"
//#include "ESP8266HTTPClient.h"
#include "SoftwareSerial.h"

// HW serial
#define _baudrate 9600

// LDR
#define LDRPin A0
#define RL 500     # 500/lux

// ESP 2866 WIFI
#define RX 10   // connect this ping to the TX pin of the esp8266
#define TX 11   // connect this ping to the RX pin of the esp8266

const String HOST = "api.thingspeak.com";
const int PORT = 80;
const String WRITE_KEY = "R9Z4V5ONGV65YVFT";

// API calls
const String LDR_CALL = "field1";

String GET = "GET /update?api_key=" + WRITE_KEY+ "&";
unsigned long myChannelNumber = 591215;
const String SSID = "Y5070AP";
const String PASS = "ArduinoUno";


int countTrueCommand;
int countTimeCommand;
boolean found = false;
uint8_t wifi_started = false;
int valSensor = 1;

SoftwareSerial esp8266(RX, TX);


// THE METHOS
void sendCommand(String command, int maxTime, char readReplay[]);
String getLux(void);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(_baudrate);
    esp8266.begin(115200);

    sendCommand("AT", 5, "OK");             // see if we get an OK response
    sendCommand("AT+CWMODE=1", 5, "OK");    // static mode
    sendCommand("AT+CWJAP=\"" + SSID + "\",\"" + PASS + "\"", 20, "OK");    // connect to acces point
}


// the loop function runs over and over again forever
void loop() {
    // retrieve the LUX
    String lux = String(getLux());
    Serial.print("Lux: " + lux);

    // send the lux command to the thingspeak API
    String getData = GET + LDR_CALL + "=" + lux;
    sendCommand("AT+CIPMUX=1", 5, "OK");
    sendCommand("AT+CIPSTART=0,\"TCP\",\"" + HOST + "\"," + String(PORT), 15, "OK");
    sendCommand("AT+CIPSEND=0," + String(getData.length() + 4), 10, ">");
    Serial.println(getData);
    esp8266.println(getData);delay(1000);countTrueCommand++;
    sendCommand("AT+CIPCLOSE=0", 10, "OK");
}

String getLux() {
    int LDRVal = analogRead(LDRPin);
    float lux = 1023.0 * 250.0 / LDRVal - 50.00;
    return String(lux);
}

void sendCommand(String command, int maxTime, char readReplay[]) {
    Serial.print(countTrueCommand);
    Serial.print(". at command => ");
    Serial.print(command);
    Serial.print(" ");
    while (countTimeCommand < (maxTime * 1)) {
        esp8266.println(command); //at+cipsend
        if (esp8266.find(readReplay))//ok
        {
            found = true;
            break;
        }

        countTimeCommand++;
    }

    if (found == true) {
        Serial.println("OK");
        countTrueCommand++;
        countTimeCommand = 0;
    }

    if (found == false) {
        Serial.println("Fail");
        countTrueCommand = 0;
        countTimeCommand = 0;
    }

    found = false;
}