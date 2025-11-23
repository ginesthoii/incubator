#pragma once
void pid_init();
double pid_compute(double currentTemp);
void heater_apply(double value);
void heater_off();
