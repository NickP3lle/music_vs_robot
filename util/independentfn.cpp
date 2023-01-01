#include "independentfn.h"

// Return a random number between minValue and maxValue
u32 randomInt(u32 maxValue, u32 minValue) {
  if (maxValue < minValue)
    return 0;
  return (rand() % (maxValue - minValue + 1)) + minValue;
}

// Test a function and print the result
void Test(std::string fname, bool (*fn)(void)) {
  std::cout << "Testing " << std::left << std::setw(30) << fname << " ... ";
  if (fn())
    std::cout << "PASSED" << std::endl;
  else
    std::cout << "FAILED" << std::endl;
}
