#pragma once
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#define u32 unsigned int

// Function to generate a random number between 0 and the max value passed in
u32 randomInt(u32 maxValue, u32 minValue = 0);

void Test(std::string fn_name, bool (*fn)(void));
