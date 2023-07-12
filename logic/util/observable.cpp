#include "observable.h"

void Observable::notifyObservers() const {
  observers.iter([](Observer *o) { o->update(); });
}

void Observable::addObserver(Observer *o) { observers.push_back(o); }

void Observable::removeObserver(Observer *o) { observers.remove(o); }
