// Created by jonas on 25/09/18.

#include "Arduino.h"
#include "ThingSpeakHelper.h"
#include "LDR.h"
#include "BMP185.h"
#include "Smoke.h"
#include "WaterSensor.h"
#include "DHTSensor.h"

// HW serial
#define _baudrate 9600

// LDR
#define LDR_PIN A0
#define LDR_ID 1

// BMP180
#define BMP_ALTITUDE_ID 4
#define BMP_PRESSURE_ID 3
#define BMP_TEMPERATURE_ID 2

// SMOKE SENSOR
#define SMOKE_PIN   A2
#define SMOKE_ID    5

// WATER SENSOR
#define WATERSENSOR_PIN 12
#define WATERSENSOR_ID 6

// DHT SENSOR
#define DHT_PIN 8
#define DHT_ID 7

// ROTARY ENCODER
#define ROTARY_PIN 3

// BUZZER
#define BUZZER_PIN 13

// ESP 2866 WIFI
#define RX 10   // connect this ping to the TX pin of the esp8266
#define TX 11   // connect this ping to the RX pin of the esp8266

// API calls
const String WRITE_KEY = "R9Z4V5ONGV65YVFT";
const String SSID = "Y5070AP";
const String PASS = "ArduinoUno";

// The sensors
LDR * ldr;
BMP185 * bmp;
ThingSpeakHelper * apiHelper;
Smoke * smoke;
WaterSensor * waterSensor;
DHTSensor * dhtSensor;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(_baudrate);

    // initialize the objects
    ldr = new LDR(LDR_PIN, uint8_t(LDR_ID));
    bmp = new BMP185(BMP_PRESSURE_ID, BMP_TEMPERATURE_ID, BMP_ALTITUDE_ID);
    apiHelper = new ThingSpeakHelper(RX, TX, WRITE_KEY, SSID, PASS);
    smoke = new Smoke(SMOKE_PIN, BUZZER_PIN, SMOKE_ID);
    waterSensor = new WaterSensor(WATERSENSOR_PIN, WATERSENSOR_ID);
    dhtSensor = new DHTSensor(DHT_PIN, DHT_ID);
}


void loop() {
    apiHelper->sendSensorValue(ldr->getFieldID(), String(ldr->getNormalizedSensorValue()));
    apiHelper->sendSensorValue(smoke->getFieldID(), String(smoke->getNormalizedSensorValue()));
    apiHelper->sendSensorValue(waterSensor->getFieldID(), String(waterSensor->getNormalizedSensorValue()));
    apiHelper->sendSensorValue(bmp->getTempID(),  String(bmp->getTemperature()));
    apiHelper->sendSensorValue(bmp->getPressureID(),  String(bmp->getPressure()));
    apiHelper->sendSensorValue(bmp->getAltitudeID(),  String(bmp->getAltitude()));
    apiHelper->sendSensorValue(dhtSensor->getFieldID(), String(dhtSensor->getHumidity()));
}