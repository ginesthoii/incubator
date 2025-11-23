#pragma once
void lcd_init();
void lcd_startupScreen();
void lcd_sensorError();
void lcd_overheatWarning(double temp);
void lcd_mainScreen(double temp, double hum);
void species_selectMenu();
