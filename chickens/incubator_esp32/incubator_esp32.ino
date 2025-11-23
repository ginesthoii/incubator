#include "config.h"
#include "sensors/sht31_sensor.h"
#include "control/heat_pid.h"
#include "control/humidity_control.h"
#include "actuators/servo_turner.h"
#include "ui/lcd_ui.h"

unsigned long lastTurnTime = 0;

void setup() {
  Serial.begin(115200);
  lcd_init();
  lcd_startupScreen();
  sensor_init();
  pid_init();
  humidity_init();
  turner_init();
  species_selectMenu();
  loadSpeciesProfile();
}

void loop() {
  double temp = sensor_readTemp();
  double hum  = sensor_readHumidity();

  if (isnan(temp) || isnan(hum)) {
    lcd_sensorError();
    heater_off();
    humidifier_off();
    delay(1000);
    return;
  }

  if (temperatureSafetyTrip(temp)) {
    heater_off();
    lcd_overheatWarning(temp);
    delay(1000);
    return;
  }

  double heaterOutput = pid_compute(temp);
  heater_apply(heaterOutput);
  humidity_apply(hum);

  if (SPECIES_MODE == MODE_CHICKEN) {
    unsigned long now = millis();
    if (now - lastTurnTime > TURN_INTERVAL_MS) {
      turner_rotateOnce();
      lastTurnTime = now;
    }
  }

  lcd_mainScreen(temp, hum);
  delay(1000);
}
