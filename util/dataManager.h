#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <fstream>
#include <iostream>

class DataManagerInterface {
private:
  // virtual std::string toString();
  static bool fromString() { return true; } // std::string &s) { return true; }

public:
  virtual ~DataManagerInterface() = default;
  virtual std::string saveData() = 0;
  // virtual bool loadData() = 0;
};

#endif
