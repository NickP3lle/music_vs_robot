#pragma once
#include "deque.h"
#include "observer.h"

// where T is the class that extends ObservableInterface
template <typename T> class ObservableInterface {
  private:
    static deque<ObserverInterface<T> *> observers; // we can use deque as well

  public:
    void notify() const;
    void addObserver(ObserverInterface<T> *o);
    bool removeObserver(ObserverInterface<T> *o);
};

template <typename T> deque<ObserverInterface<T> *> ObservableInterface<T>::observers = deque<ObserverInterface<T> *>();

template <typename T> void ObservableInterface<T>::notify() const {
    observers.iter([&](auto o) { o->update(static_cast<const T *>(this)); });
}

template <typename T> void ObservableInterface<T>::addObserver(ObserverInterface<T> *o) { observers.push_back(o); }

template <typename T> bool ObservableInterface<T>::removeObserver(ObserverInterface<T> *o) { return observers.remove(o); }
