#pragma once
#include "deque.h"
#include "observer.h"

class ObservableInterface {
private:
  deque<ObserverInterface *> observers; // we can use deque as well

public:
  void notify() const;
  void addObserver(ObserverInterface *o);
  void removeObserver(ObserverInterface *o);
};
