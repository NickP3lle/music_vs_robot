#define u32 unsigned int

#include <iostream>

#ifndef CASH_H
#define CASH_H
class Cash {
  private:
    static Cash *instance;
    u32 total;
    Cash();

  public:
    static Cash *getInstance();
    void add(u32 amount);
    void sub(u32 amount);
    u32 getTotal();
};
#endif
