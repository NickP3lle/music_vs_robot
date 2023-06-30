#ifndef CASH_H
#define CASH_H
#include "../view/observers/cashObserverInterface.h"
#include <iostream>
#define u32 unsigned int
class Cash {
  private:
    static Cash *instance;
    u32 total;
    Cash();

    std::vector<CashObserverInterface *> observers;
    void notifyObservers();

  public:
    static Cash *getInstance();
    void add(u32 amount);
    bool sub(u32 amount); // returns false if not enough cash
    u32 getTotal();

    void registerObserver(CashObserverInterface *obs);
};
#endif
