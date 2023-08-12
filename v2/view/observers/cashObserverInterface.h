#ifndef CASH_OBSERVER_INTERFACE_H
#define CASH_OBSERVER_INTERFACE_H

class Cash;

class CashObserverInterface {
  public:
    virtual void updateCash() = 0;

    virtual ~CashObserverInterface() = default;
};

#endif