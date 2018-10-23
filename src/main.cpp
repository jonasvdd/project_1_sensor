#include "Arduino.h"
#include "ThingSpeakHelper.h"
#include "LDR.h"
#include "BMP185.h"
#include "Smoke.h"
#include "WaterSensor.h"
#include "DHTSensor.h"
#include "Sensor.h"
#include "RotaryEncoder.h"
#include "map"
#include "sstream"
#include "RGBLed.h"

// for easier life
using namespace std;

// HW serial
#define _baudrate 9600

/*******************************
 *         SENSORS
 ******************************/
// LDR
#define LDR_PIN             A0
#define LDR_ID              1

// BMP180
#define BMP_ALTITUDE_ID     4
#define BMP_PRESSURE_ID     3
#define BMP_TEMPERATURE_ID  2

// SMOKE SENSOR
#define SMOKE_PIN           A2
#define SMOKE_ID            5

// WATER SENSOR
#define WATERSENSOR_PIN     13
#define WATERSENSOR_ID      6

// DHT SENSOR
#define DHT_PIN             8
#define DHT_ID              7

// ROTARY ENCODER
#define ROTARY_PIN_A        2
#define ROTARY_PIN_B        3
#define UPDATE_FACTOR_MS    50

/*******************************
 *         ACTUATORS
 ******************************/
// BUZZER
#define BUZZER_PIN          12

// RGB LED
#define RED_PIN             9
#define BLUE_PIN            10
#define GREEN_PIN           11

// ESP 2866 WIFI
#define RX                  6   // connect this ping to the TX pin of the esp8266
#define TX                  7   // connect this ping to the RX pin of the esp8266

// API calls
const String WRITE_KEY = "R9Z4V5ONGV65YVFT";
const String SSID = "Y5070AP";
const String PASS = "ArduinoUno";

// some global variables
ThingSpeakHelper *apiHelper;
RotaryEncoder *rotaryEncoder;
RGBLed *rgbLed;
// dictionary which will store all our sensors whom will monitor data and send to the Thingspeak API
std::map<int, Sensor *> sensorDict;

void setup() {
    // initialize the baud rate
    Serial.begin(_baudrate);

    // initialize the rotary encoder and RGB LED and thingspeak helper
    rotaryEncoder = new RotaryEncoder(ROTARY_PIN_A, ROTARY_PIN_B);
    rgbLed = new RGBLed(CATHODE, RED_PIN, GREEN_PIN, BLUE_PIN);
    apiHelper = new ThingSpeakHelper(rgbLed, RX, TX, WRITE_KEY, SSID, PASS);

    // initialize the BMP and the sensor dict
    auto *bmp = new BMP185();
    sensorDict[BMP_PRESSURE_ID] = bmp->pressureSensor;
    sensorDict[BMP_ALTITUDE_ID] = bmp->altitudeSensor;
    sensorDict[BMP_TEMPERATURE_ID] = bmp->temperatureSensor;
    sensorDict[LDR_ID] = new LDR(LDR_PIN);
    sensorDict[SMOKE_ID] = new Smoke(SMOKE_PIN, BUZZER_PIN);
    sensorDict[WATERSENSOR_ID] = new WaterSensor(WATERSENSOR_PIN);
    sensorDict[DHT_ID] = new DHTSensor(DHT_PIN);
}

void loop() {
    String datastring = "";
    for (pair<int, Sensor *> element : sensorDict) {
        datastring += "&field" + String(element.first) + "=" + String(element.second->getNormalizedSensorValue());
    }
    apiHelper->sendSensorValue(datastring);

    // delay the update loop
    uint32_t delayTime = int32_t(rotaryEncoder->getNormalizedSensorValue()) * uint32_t(UPDATE_FACTOR_MS);
    Serial.print("waiting for ");
    Serial.print(delayTime);
    Serial.println(" ms!");
    delay(delayTime);
}

