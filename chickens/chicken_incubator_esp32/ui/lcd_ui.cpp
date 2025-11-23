#include "lcd_ui.h"
#include <LiquidCrystal_I2C.h>
#include "../config.h"
#include <Arduino.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define BTN_UP   32
#define BTN_DOWN 33
#define BTN_OK   25

void lcd_init() { lcd.init(); lcd.backlight(); }

void lcd_startupScreen() {
  lcd.clear();
  lcd.setCursor(2,0); lcd.print("INCUBATOR");
  lcd.setCursor(1,1); lcd.print("ESP32 SYSTEM");
  delay(1200);
}

void lcd_sensorError() {
  lcd.clear();
  lcd.print("Sensor Error");
}

void lcd_overheatWarning(double temp) {
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("OVERHEAT!");
  lcd.setCursor(0,1); lcd.print(temp); lcd.print(" C");
}

void lcd_mainScreen(double temp, double hum) {
  lcd.clear();
  lcd.setCursor(0,0); lcd.print(temp); lcd.print("C  "); lcd.print(hum); lcd.print("%");
  lcd.setCursor(0,1); lcd.print("Set:"); lcd.print(TARGET_TEMP);
  lcd.print(" H:"); lcd.print(TARGET_HUMIDITY);
}

void species_selectMenu() {
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Select Mode:");

  while (true) {
    lcd.setCursor(0,1);
    if (SPECIES_MODE == MODE_CHICKEN) lcd.print("Chicken     ");
    else lcd.print("BallPython  ");

    if (!digitalRead(BTN_UP))   { SPECIES_MODE = MODE_CHICKEN; delay(200); }
    if (!digitalRead(BTN_DOWN)) { SPECIES_MODE = MODE_PYTHON;  delay(200); }
    if (!digitalRead(BTN_OK))   { delay(200); break; }
  }
}
