#include "humidity_control.h"
#include "../config.h"
#include <Arduino.h>

#define HUMID_PIN 27

void humidity_init() { pinMode(HUMID_PIN, OUTPUT); humidifier_off(); }

void humidity_apply(double currentHumidity) {
  if (currentHumidity < TARGET_HUMIDITY - 2) digitalWrite(HUMID_PIN, HIGH);
  else if (currentHumidity > TARGET_HUMIDITY + 2) digitalWrite(HUMID_PIN, LOW);
}

void humidifier_off() { digitalWrite(HUMID_PIN, LOW); }
