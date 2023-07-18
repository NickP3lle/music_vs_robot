#pragma once
#include "../include.h"

class Cash : public DataManagerInterface, public Observable {
  private:
    static Cash *instance;
    u32 cash;
    Cash();

  public:
    static Cash *getInstance();
    static void add(u32);
    static bool sub(u32);
    static u32 get();
    static void cleanUp();

    std::string toString() const override;
    Cash *fromString(std::string) override;
};
