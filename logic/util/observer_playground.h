#pragma once
#include "deque.h"
#include "playground_observer.h"

template <typename T> class PlaygroundObservableInterface {
protected:
  deque<PlaygroundObserverInterface<T> *> obs;

public:
  void addObserver(PlaygroundObserverInterface<T> *observer);
  void removeObserver(PlaygroundObserverInterface<T> *observer);
  virtual void notifyObservers(u32 row, u32 col) const = 0;
  virtual ~PlaygroundObservableInterface() = default;
};
