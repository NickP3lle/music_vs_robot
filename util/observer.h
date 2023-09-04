#pragma once

template <typename T> class ObservableInterface;

template <typename T> class ObserverInterface {
public:
  virtual void update(const T *) = 0;
};
