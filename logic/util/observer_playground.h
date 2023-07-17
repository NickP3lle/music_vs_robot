#pragma once
#define u32 unsigned int
#include "deque.h"

template <typename T> class ObserverPlayground {
public:
  virtual void update(u32 row, u32 col, T *e) = 0;
};

template <typename T> class ObservablePlayground {
protected:
  deque<ObserverPlayground<T> *> obs;

public:
  void addObserver(ObserverPlayground<T> *observer);
  void removeObserver(ObserverPlayground<T> *observer);
  virtual void notifyObservers(u32 row, u32 col) const = 0;
  virtual ~ObservablePlayground() = default;
};
