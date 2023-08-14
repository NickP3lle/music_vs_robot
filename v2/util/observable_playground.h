#pragma once
#include "deque.h"
#include "observer_playground.h"

template <typename T> class PlaygroundObservableInterface {
protected:
  deque<PlaygroundObserverInterface<T> *> obs;

public:
  void addObserver(PlaygroundObserverInterface<T> *observer);
  void removeObserver(PlaygroundObserverInterface<T> *observer);
  virtual void notifyObservers(u32 row, u32 col) const = 0;
  virtual ~PlaygroundObservableInterface() = default;
};

template <typename T>
void PlaygroundObservableInterface<T>::addObserver(
    PlaygroundObserverInterface<T> *observer) {
  obs.push_back(observer);
}

template <typename T>
void PlaygroundObservableInterface<T>::removeObserver(
    PlaygroundObserverInterface<T> *observer) {
  obs.remove(observer);
}
