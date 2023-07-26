#include "observable.h"

void ObservableInterface::notify() const {
  observers.iter([](ObserverInterface *o) { o->update(); });
}

void ObservableInterface::addObserver(ObserverInterface *o) {
  observers.push_back(o);
}

void ObservableInterface::removeObserver(ObserverInterface *o) {
  observers.remove(o);
}
