#include "observer_playground.h"

template <typename T>
void ObservablePlayground<T>::addObserver(ObserverPlayground<T> *observer) {
  obs.push_back(observer);
}

template <typename T>
void ObservablePlayground<T>::removeObserver(ObserverPlayground<T> *observer) {
  obs.remove(observer);
}
