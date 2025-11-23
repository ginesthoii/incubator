#include "config.h"

int SPECIES_MODE = MODE_CHICKEN;
double TARGET_TEMP = 37.5;
double TARGET_HUMIDITY = 50.0;

void loadSpeciesProfile() {
  if (SPECIES_MODE == MODE_CHICKEN) {
    TARGET_TEMP = 37.5;
    TARGET_HUMIDITY = 50;
  } else {
    TARGET_TEMP = 32.0;
    TARGET_HUMIDITY = 98;
  }
}

bool temperatureSafetyTrip(double t) {
  if (SPECIES_MODE == MODE_CHICKEN)
    return (t > CHICKEN_MAX_TEMP);
  return (t > PYTHON_MAX_TEMP);
}
