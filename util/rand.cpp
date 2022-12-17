#include "rand.h"

// Return a random number between minValue and maxValue
int random_int(int maxValue, int minValue) {
  return (rand() % (maxValue + 1)) + minValue;
}
