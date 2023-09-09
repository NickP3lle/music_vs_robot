#pragma once
#include "../include.h"

class Timer : public DataManagerInterface, public ObservableInterface<Timer> {
  private:
    static Timer *instance;
    u32 t;
    Timer();

  public:
    static Timer *getInstance();
    static void add(u32);
    static void oneSecond();
    static u32 get();
    static void cleanUp();
    static void start();
    static u32 minutes();
    static u32 seconds();

    std::string toString() const override;
    Timer *fromString(std::string) override;
};
