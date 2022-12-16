#include "rand.h"

int random_int(int maxValue)
{
  // Return a random number between 0 and maxValue
  return rand() % (maxValue + 1);
}
