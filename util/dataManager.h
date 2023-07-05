#pragma once
#include <string>

class DataManagerInterface {
private:
  virtual std::string toString();
  static bool fromString() { return true; } // std::string &s) { return true; }

public:
  virtual bool saveData() = 0;
  virtual bool loadData() = 0;
};
