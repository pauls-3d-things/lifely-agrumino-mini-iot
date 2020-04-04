#include <Arduino.h>

#include "Agrumino.h"

Agrumino agrumino;

void setup() {
  Serial.begin(115200);
  agrumino.setup();
}

void loop() {
  Serial.println("--------------------------------");
  Serial.print("Temp: ");
  Serial.print(agrumino.readTempC());
  Serial.println("C");

  Serial.print("Soil: ");
  Serial.print(agrumino.readSoil());
  Serial.print("%, raw: ");
  Serial.println(agrumino.readSoilRaw());

  Serial.print("Lux: ");
  Serial.print(agrumino.readLux());
  Serial.println("lx");

  Serial.print("Battery: ");
  Serial.print(agrumino.readBatteryLevel());
  Serial.print("%, ");
  Serial.print(agrumino.readBatteryVoltage());
  Serial.println("V");

  if (agrumino.isAttachedToUSB() && !agrumino.isLedOn()) {
    agrumino.turnLedOn();
  } else if (agrumino.isLedOn()) {
    agrumino.turnLedOff();
  }

  delay(1000);
}