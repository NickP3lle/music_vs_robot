#pragma once
#include "../include.h"

class Timer : public DataManagerInterface, public ObservableInterface {
private:
  static Timer *instance;
  u32 t;
  Timer();

public:
  static Timer *getInstance();
  static void add(u32);
  static bool sub(u32);
  static u32 get();
  static void cleanUp();

  std::string toString() const override;
  Timer *fromString(std::string) override;
};
