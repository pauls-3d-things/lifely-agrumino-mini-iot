#include <Arduino.h>

#include "Agrumino.h"
#include "config.h"
#include "mini-iot-client.h"

Agrumino agrumino;
MiniIotClient miniIot("lifely01", MINI_IOT_SERVER, WIFI_SSID, WIFI_PASS);

void setup() {
  Serial.begin(115200);
  agrumino.setup();
}

void loop() {
  float c = agrumino.readTempC();
  float s = agrumino.readSoil();
  float sr = agrumino.readSoilRaw();
  float lx = agrumino.readLux();
  float bl = agrumino.readBatteryLevel();
  float bv = agrumino.readBatteryVoltage();

  String payload =
      String(c) + "," + String(s) + "," + String(sr) + "," + String(lx) + "," + String(bl) + "," + String(bv);

  miniIot.connectToWifi(); // this blocks until connected
  miniIot.appendWithTimestamp("data.csv", payload);
  Serial.println(payload);

  if (agrumino.isAttachedToUSB() && !agrumino.isLedOn()) {
    agrumino.turnLedOn();
  } else if (!agrumino.isAttachedToUSB() && agrumino.isLedOn()) {
    agrumino.turnLedOff();
  }

  agrumino.deepSleepSec(3600);
}