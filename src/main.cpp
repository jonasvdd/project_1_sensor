///
// Created by jonas on 25/09/18.
//
#include "Arduino.h"
#include "ThingSpeak.h"
#include "SoftwareSerial.h"

// HW serial
#define _baudrate 9600



// LDR
#define LDRPin A0
#define RL 500     # 500/lux

// Temp
#define TDPIN 3
#define TAPIN A1

// ESP 2866 WIFI
#define RX 10
#define TX 11
SoftwareSerial esp8266(RX, TX);
#define SSID "Y5070AP"
#define PASS "ArduinoUno"
#define HOST "api.thingspeak.com"
#define PORT 80
#define WRITE_KEY  "R9Z4V5ONGV65YVFT"

// API calls
#define LDR_CALL "field1"

String GET = "GET /update?api_key=" + String(WRITE_KEY) + "&";

int countTrueCommand;
int countTimeCommand;
boolean found = false;
int valSensor = 1;

void sendCommand(String command, int maxTime, char readReplay[]) {
    Serial.print(countTrueCommand);
    Serial.print(". at command => ");
    Serial.print(command);
    Serial.print(" ");
    while (countTimeCommand < (maxTime * 1)) {
        esp8266.println(command);//at+cipsend
        if (esp8266.find(readReplay))//ok
        {
            found = true;
            break;
        }

        countTimeCommand++;
    }

    if (found == true) {
        Serial.println("OYI");
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

void setup() {
    Serial.begin(_baudrate);
    esp8266.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(TDPIN, INPUT);
    sendCommand("AT", 5, "OK");
    sendCommand("AT+CWMODE=1", 5, "OK");
    sendCommand("AT+CWJAP=\"" + String(SSID) + "\",\"" + String(PASS) + "\"", 20, "OK");
}

float getLux() {
    int LDRVal = analogRead(LDRPin);
    float lux = 1023.0 * 250.0 / LDRVal - 50.00;
    return lux;
}

float getHumidity() {
#TODO
    return 0;
}

float getTemperature() {
#TODO //convert to °C
    float tmpV = analogRead (TAPIN) * (5.0 / 1023.0); //returns voltage
    return tmpV;
}

// the loop function runs over and over again forever
void loop() {
    // retrieve the LUX
    String lux = String(getLux());
    Serial.print("Lux: " + lux);

    // send the lux command to the thingspeak API
    String getData = GET + String(LDR_CALL) + "=" + lux;
    sendCommand("AT+CIPMUX=1", 5, "OK");
    sendCommand("AT+CIPSTART=0,\"TCP\",\"" + String(HOST) + "\"," + String(PORT), 15, "OK");
    sendCommand("AT+CIPSEND=0," + String(getData.length() + lux.length()), 10, ">");
    esp8266.println(getData);
    delay(1500);
    countTrueCommand++;
    sendCommand("AT+CIPCLOSE=0", 10, "OK");
}