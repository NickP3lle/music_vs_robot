#include "observable_playground.h"

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
