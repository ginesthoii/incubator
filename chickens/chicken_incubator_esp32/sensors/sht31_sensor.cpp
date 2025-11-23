#include "sht31_sensor.h"
#include <SHT31.h>

SHT31 sht;

void sensor_init() { sht.begin(0x44); }
double sensor_readTemp() { return sht.readTemperature(); }
double sensor_readHumidity() { return sht.readHumidity(); }
