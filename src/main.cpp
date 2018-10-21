#include "Arduino.h"
#include "ThingSpeakHelper.h"
#include "LDR.h"
#include "BMP185.h"
#include "Smoke.h"
#include "WaterSensor.h"
#include "DHTSensor.h"
#include "Sensor.h"
#include "map"

using namespace std;

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
ThingSpeakHelper *apiHelper;

std::map<int, Sensor> sensorDict;

void setup() {
    Serial.begin(_baudrate);

    // create the thingspeak helper
    apiHelper = new ThingSpeakHelper(RX, TX, WRITE_KEY, SSID, PASS);

    // initialize the sensor dict
    BMP185 * bmp = new BMP185();
    sensorDict[BMP_PRESSURE_ID] = * bmp->getPressureSensor();
    sensorDict[BMP_ALTITUDE_ID] = * bmp->getAltitudeSensor();
    sensorDict[BMP_TEMPERATURE_ID] = * bmp->getTemperatureSensor();
    sensorDict[LDR_ID] = * new LDR(LDR_PIN);
    sensorDict[SMOKE_ID] = * new Smoke(SMOKE_PIN, BUZZER_PIN);
    sensorDict[WATERSENSOR_ID] = * new WaterSensor(WATERSENSOR_PIN);
    sensorDict[DHT_ID] = * new DHTSensor(DHT_PIN);
}


void loop() {
    String datastring = "";
    for (pair<int, Sensor> element : sensorDict) {
        datastring +="&field" +  String(element.first) + "=" + String(element.second.getNormalizedSensorValue());
    }
    Serial.println(datastring);
}