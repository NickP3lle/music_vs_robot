#pragma once
#include <fstream>
#include <iostream>

class DataManager {
public:
  static void saveAll(); // TODO!
  virtual std::string toString() const = 0;
};
