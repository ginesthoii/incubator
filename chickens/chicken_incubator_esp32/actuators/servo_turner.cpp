#include "servo_turner.h"
#include <ESP32Servo.h>

#define SERVO_PIN 18

Servo turner;

void turner_init() { turner.attach(SERVO_PIN); turner.write(0); }

void turner_rotateOnce() {
  for (int angle = 0; angle <= 45; angle++) { turner.write(angle); delay(20); }
  delay(3000);
  for (int angle = 45; angle >= 0; angle--) { turner.write(angle); delay(20); }
}
