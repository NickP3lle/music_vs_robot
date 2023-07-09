#ifndef CASH_H
#define CASH_H
#include "../util/dataManager.h"
#include "../view/observers/cashObserverInterface.h"
#include <iostream>
#include <vector>
#define u32 unsigned int

class Cash : public DataManagerInterface {
  private:
    static Cash *instance;
    u32 total;
    Cash();

    static std::vector<CashObserverInterface *> observers;
    static void notifyObservers();

  public:
    static Cash &getInstance();
    static Cash *getInstancePtr();
    static void cleanUp();
    static void add(u32 amount);
    static bool sub(u32 amount); // returns false if not enough cash
    static u32 get();            // getTotal -> get

    static void registerObserver(CashObserverInterface *obs);

    virtual std::string saveData() const override;
    virtual Cash *loadData(std::string) override;
};
#endif
