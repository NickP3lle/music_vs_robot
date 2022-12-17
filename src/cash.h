#include "include.h"
#pragma once

<<<<<<< HEAD
// #ifndef CASH_H
// #define CASH_H
class Cash {
private:
  static Cash *instance;
  u32 total;
  Cash();

public:
  static Cash *getInstance();
  void add(u32 amount);
  bool sub(u32 amount); // returns false if not enough cash
  u32 getTotal();
>>>>>>> 7d25560f2e8b4b6d0050ebd0058e5350f41596e6
};
// #endif
