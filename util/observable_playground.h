#pragma once
#include "deque.h"
#include "observer_playground.h"

template <typename T> class ObservablePlaygroundInterface {
protected:
  deque<ObserverPlaygroundInterface<T> *> obs;

public:
  void addObserver(ObserverPlaygroundInterface<T> *observer);
  void removeObserver(ObservablePlaygroundInterface<T> *observer);
  virtual void notifyObservers(u32 row, u32 col) const = 0;
  virtual ~ObservablePlaygroundInterface() = default;
};

template <typename T>
void ObservablePlaygroundInterface<T>::addObserver(
    ObserverPlaygroundInterface<T> *observer) {
  obs.push_back(observer);
}

template <typename T>
void ObservablePlaygroundInterface<T>::removeObserver(
    ObservablePlaygroundInterface<T> *observer) {
  obs.remove(observer);
}
