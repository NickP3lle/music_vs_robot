#pragma once
#include <string>

class DataManagerInterface {
private:
  virtual std::string toString();
  static bool fromString(std::string &);

public:
  virtual bool saveData() = 0;
  virtual bool loadData() = 0;
};
