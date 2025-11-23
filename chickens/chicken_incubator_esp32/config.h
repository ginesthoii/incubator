#pragma once
#define MODE_CHICKEN 0
#define MODE_PYTHON  1

extern int SPECIES_MODE;
extern double TARGET_TEMP;
extern double TARGET_HUMIDITY;

#define CHICKEN_MAX_TEMP 38.5
#define PYTHON_MAX_TEMP  33.2

#define TURN_INTERVAL_MS (4UL * 3600UL * 1000UL)

void loadSpeciesProfile();
bool temperatureSafetyTrip(double t);
void species_selectMenu();
