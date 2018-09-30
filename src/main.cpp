///
// Created by jonas on 25/09/18.
//
#include "Arduino.h"
#include "ThingSpeak"
//#include "ThingSpeak.h"
//#include "DHT.h"

//#include "SPI.h"
//#include "Ethernet.h"
// #include "esp8266.c"

#include "SoftwareSerial.h"

// HW serial
#define _baudrate 9600

// SW serial
#define _rxpin 2
#define _txpin 3

SoftwareSerial debug(_rxpin, _txpin); // RX, TX

// IoT information
#define SSID "Y5070AP"
#define PASS "ArduinoUno";
#define IP "192.168.12.1"

// GET /update?key=[THINGSPEAK_KEY]&field1=[data 1]&field2=[data 2]...;
String GET = "GET /update?key=[ThingSpeak_(Write)API_KEY]"; // todo thingspeak write API key

const char* writeAPIKey = "YourWriteAPI";

void setup() {
    Serial.begin( _baudrate );
//    debug.begin( _baudrate );
//
//    sendDebug("AT");
//    delay(5000);
//    if(Serial.find("OK"))
//    {
//        debug.println("RECEIVED: OK\nData ready to sent!");
//        connectWiFi();
//    }
    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    Serial.println("Switch on");
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    Serial.println("Switch off");
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(100);                       // wait for a second
}