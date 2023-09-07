#pragma once
#include "deque.h"
#include "observer_playground.h"

template <typename T> class ObservablePlaygroundInterface {
  protected:
    static deque<ObserverPlaygroundInterface<T> *> obs;

  public:
    void addObserver(ObserverPlaygroundInterface<T> *observer);
    bool removeObserver(ObservablePlaygroundInterface<T> *observer);
    virtual void notifyObservers(u32 row, u32 col) const = 0;
    virtual ~ObservablePlaygroundInterface() = default;
};

template <typename T>
deque<ObserverPlaygroundInterface<T> *> ObservablePlaygroundInterface<T>::obs = deque<ObserverPlaygroundInterface<T> *>();

template <typename T> void ObservablePlaygroundInterface<T>::addObserver(ObserverPlaygroundInterface<T> *observer) {
    obs.push_back(observer);
}

template <typename T> bool ObservablePlaygroundInterface<T>::removeObserver(ObservablePlaygroundInterface<T> *observer) {
    return obs.remove(observer);
}
