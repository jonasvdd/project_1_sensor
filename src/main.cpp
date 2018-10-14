// Created by jonas on 25/09/18.

#include "Arduino.h"
#include "ThingSpeakHelper.h"
#include "LDR.h"
#include "BMP185.h"


// HW serial
#define _baudrate 9600

// LDR
#define LDR_PIN A0
#define LDR_ID 1

// BMP180
#define BMP_ALTITUDE_ID 4
#define BMP_PRESSURE_ID 3
#define BMP_TEMPERATURE_ID 2

// ESP 2866 WIFI
#define RX 10   // connect this ping to the TX pin of the esp8266
#define TX 11   // connect this ping to the RX pin of the esp8266

// API calls
const String WRITE_KEY = "R9Z4V5ONGV65YVFT";
const String SSID = "Y5070AP";
const String PASS = "ArduinoUno";

//
LDR * ldr;
BMP185 * bmp;
ThingSpeakHelper * apiHelper;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(_baudrate);

    // initialize the objects
    ldr = new LDR(LDR_PIN, uint8_t(LDR_ID));
    bmp = new BMP185(BMP_PRESSURE_ID, BMP_TEMPERATURE_ID, BMP_ALTITUDE_ID);
    apiHelper = new ThingSpeakHelper(RX, TX, WRITE_KEY, SSID, PASS);
}


void loop() {
    apiHelper->sendSensorValue(ldr->getFieldID(), String(ldr->getLux()));
    apiHelper->sendSensorValue(bmp->getTempID(),  String(bmp->getTemperature()));
    apiHelper->sendSensorValue(bmp->getPressureID(),  String(bmp->getPressure()));
    apiHelper->sendSensorValue(bmp->getAltitudeID(),  String(bmp->getAltitude()));
    delay(1000);
}