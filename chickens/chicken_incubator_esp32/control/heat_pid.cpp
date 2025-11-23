#include "heat_pid.h"
#include "../config.h"
#include <PID_v1.h>
#include <Arduino.h>

#define HEATER_PIN 14

double tempInput, tempOutput;
double tempSetpoint;

double Kp = 2.0, Ki = 5.0, Kd = 1.0;

PID tempPID(&tempInput, &tempOutput, &tempSetpoint, Kp, Ki, Kd, DIRECT);

void pid_init() {
  pinMode(HEATER_PIN, OUTPUT);
  heater_off();
  tempSetpoint = TARGET_TEMP;
  tempPID.SetMode(AUTOMATIC);
  tempPID.SetOutputLimits(0, 255);
}

double pid_compute(double currentTemp) {
  tempInput = currentTemp;
  tempSetpoint = TARGET_TEMP;
  tempPID.Compute();
  return tempOutput;
}

void heater_apply(double value) { analogWrite(HEATER_PIN, (int)value); }
void heater_off() { digitalWrite(HEATER_PIN, LOW); }
