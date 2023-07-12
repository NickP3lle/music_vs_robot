#pragma once
#include "deque.h"
#include "observer.h"

class Observable {
private:
  deque<Observer *> observers; // we can use deque as well

public:
  void notify() const;
  void addObserver(Observer *o);
  void removeObserver(Observer *o);
};
