# Sensoring & interfacing project 1
## Platformio 

```$bash
platformio init -d /home/jonas/Documents/Ugent/master/1/SenI/Labo/project1/project_1_sensor --ide clion --board uno
```

```
platformio serialports list
/dev/ttyACM0
------------
Hardware ID: USB VID:PID=2341:0043 SER=55737313131351314231 LOCATION=2-1:1.0
Description: ttyACM0
```

## Used sensors

sensor | function | link
------|--------- | --------
`flame sensor` | vlam detectie
`buzzer` | alarm
`led` | kleurcode alarm
`watersensor` | waterdetectie in de potgrond van een plant
`vochtigheidsensor` | vochtigheid
`rotary encoder` | update snelheid
`LDR` | licht intensiteit
`Wifi module` | Thingspeak API
`Gas Sensor` | Co detection 

interesting links:

* https://github.com/esp8266/Arduino
> * https://www.aliexpress.com/item/ESP8266-remote-serial-Port-WIFI-wireless-module-through-walls-Wang-with-tracking-number/2040615889.html?spm=a2g0s.9042311.0.0.27424c4d6nsnyM
* http://wiki.seeedstudio.com/Grove-Gas_Sensor-MQ2/
* https://www.arduinolibraries.info/libraries/dht-sensor-library
* https://wiki.archlinux.org/index.php/Software_access_point
> * https://github.com/oblique/create_ap
* https://www.instructables.com/id/Introducing-PlatformIO-for-ESP8266/
* https://docs.platformio.org/en/latest/ide/clion.html
> Tells how to find libraries which you wan to use in your arduino projects
* https://medium.com/@cgrant/using-the-esp8266-wifi-module-with-arduino-uno-publishing-to-thingspeak-99fc77122e82 

### Installing libraries with platformio
```
╭  jonas   ~                                                             100%   | 20:21  
╰ platformio lib search thingSpeak
Found 2 libraries:

ThingSpeak
==========
#ID: 550
ThingSpeak Communication Library for Arduino, ESP8266 & EPS32

Keywords: communication
Compatible frameworks: Arduino
Compatible platforms: Atmel AVR, Atmel SAM, Espressif 32, Espressif 8266
Authors: MathWorks

ThingSpeak
==========
#ID: 4902
first versione of ThingSpeak IOT library (not tested)

Keywords: thingspeak
Compatible frameworks: mbed
Compatible platforms: Atmel SAM, Freescale Kinetis, Maxim Integrated MAX32, Nordic nRF51, Nordic nRF52, NXP LPC, Silicon Labs EFM32, ST STM32, Teensy, WIZNet W7500
Authors: Stefano Lai

╭  jonas   ~                                                             100%   | 20:21  
╰ platformio lib -g install 550   
Library Storage: /home/jonas/.platformio/lib
LibraryManager: Installing id=550
Downloading...
Unpacking  [####################################]  100%
ThingSpeak @ 1.3.3 has been successfully installed!

platformio lib -g install 31         
Library Storage: /home/jonas/.platformio/lib
LibraryManager: Installing id=31
Downloading...
Unpacking  [####################################]  100%
Adafruit Unified Sensor @ 1.0.2 has been successfully installed!

╰ platformio lib -g install 525 
Library Storage: /home/jonas/.platformio/lib
LibraryManager: Installing id=525
Downloading...
Unpacking  [####################################]  100%
Adafruit BMP085 Library @ 1.0.0 has been successfully installed!

latformio lib -g install 16  
Library Storage: /home/jonas/.platformio/lib
LibraryManager: Installing id=16
Downloading...
Unpacking  [####################################]  100%
Adafruit BMP085 Unified @ 1.0.0 has been successfully installed!


```

```asm
platformio lib -g install 1101         
Library Storage: /home/jonas/.platformio/lib
LibraryManager: Installing id=1101
Downloading...
Unpacking  [####################################]  100%
SerialESP8266wifi @ 0bf32ed60b has been successfully installed!
```

### Network hotspot
```bash
sudo create_ap wlp0s20u9 wlp8s0 Y5070AP ArduinoUno
WARN: Your adapter does not fully support AP virtual interface, enabling --no-virt
WARN: Realtek drivers usually have problems with WPA1, enabling -w 2
WARN: If AP doesn't work, please read: howto/realtek.md
Config dir: /tmp/create_ap.wlp0s20u9.conf.3sLqXw3o
PID: 25469
Network Manager found, set wlp0s20u9 as unmanaged device... DONE
Sharing Internet using method: nat
hostapd command-line interface: hostapd_cli -p /tmp/create_ap.wlp0s20u9.conf.3sLqXw3o/hostapd_ctrl
Configuration file: /tmp/create_ap.wlp0s20u9.conf.3sLqXw3o/hostapd.conf
Using interface wlp0s20u9 with hwaddr 74:da:38:db:5b:c2 and ssid "Y5070AP"
wlp0s20u9: interface state UNINITIALIZED->ENABLED
wlp0s20u9: AP-ENABLED 
wlp0s20u9: STA 18:f0:e4:04:a1:02 IEEE 802.11: authenticated
wlp0s20u9: STA 18:f0:e4:04:a1:02 IEEE 802.11: associated (aid 1)
wlp0s20u9: AP-STA-CONNECTED 18:f0:e4:04:a1:02
wlp0s20u9: STA 18:f0:e4:04:a1:02 RADIUS: starting accounting session FB5203553052A6BC
wlp0s20u9: STA 18:f0:e4:04:a1:02 WPA: pairwise key handshake completed (RSN)
```

