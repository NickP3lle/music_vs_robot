#include "independentfn.h"

// Return a random number between minValue and maxValue
u32 randomInt(u32 maxValue, u32 minValue) {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(minValue, maxValue);
  return distribution(generator);
}

// Test a function and print the result
void Test(std::string fname, bool (*fn)(void)) {
  std::cout << "Testing " << std::left << std::setw(30) << fname << " ... ";
  if (fn())
    std::cout << "\033[1;32mPASSED\033[0;97m\n";
  else
    std::cout << "\033[1;91mFAILED\033[0;97m\n";
}
