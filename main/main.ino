// I/O
#include "KY040rotary.h"
#include <NeoPixelBrightnessBus.h>
#include <SoftwareSerial.h>

// Custom
#include "CONSTANTS.h"

// DF Player mini / MP3
#include "DFRobotDFPlayerMini.h"

// OTA
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// Remote debug over WiFi
#include "RemoteDebug.h"        //https://github.com/JoaoLopesF/RemoteDebug

RemoteDebug Debug;
// #define STASSID "Nippelboard"
// #define STAPSK  "nippel2020"

const char* ssid = STASSID;
const char* password = STAPSK;

// init the Rotary Button
KY040 Rotary(14, 12, 13); // D5, D6, D7 (CLK, DT, SW)

// Uses Pin 21, aka GPIO3
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(NUM_LEDS);

// Init MP3 Player
SoftwareSerial mp3Serial(5, 4); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// The sound Map defines, which soundmap should be used and which files are used in there
int selectedFolder;

void setup() {
  // open the serial port
  Serial.begin(115200);
  Serial.println("Starting...");

  selectedFolder = 1;

  setupWifi();
  setupRotary();
  setupLED();
  setupMP3();
  
  showColor(255,0,255);
}

void loop() {
  loopWifi();
  loopRotary();
  loopButtons();
}