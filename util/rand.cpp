#include "rand.h"
// Return a random number between minValue and maxValue
u32 random_int(u32 maxValue, u32 minValue) {
  return (rand() % (maxValue - minValue + 1)) + minValue;
}
