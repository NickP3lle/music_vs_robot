#pragma once

#include <iostream>
#include <type_traits>

template <typename T> class ptr {

private:
  T *p;

public:
  ptr(T *const = nullptr);
  ptr(const ptr &);
  ptr &operator=(const ptr &);
  ~ptr();

  T *operator->() const;
  T &operator*() const;
  operator bool() const;
};

template <typename T> ptr<T>::ptr(T *const p) : p(p) {}

template <typename T>
ptr<T>::ptr(const ptr &o) : p(o ? o.p->clone() : nullptr) {}

template <typename T> ptr<T> &ptr<T>::operator=(const ptr &o) {
  if (this != &o) {
    delete p;
    p = o ? o.p->clone() : nullptr;
  }
  return *this;
}

template <typename T> ptr<T>::~ptr() {
  if (p != nullptr)
    delete p;
  p = nullptr;
}

template <typename T> T *ptr<T>::operator->() const {
  if (!p)
    std::cout << "Error on ->" << std::endl;
  else
    std::cout << "All right on ->" << std::endl;
  return p;
}

template <typename T> T &ptr<T>::operator*() const { return *p; }

template <typename T> ptr<T>::operator bool() const { return p != nullptr; }
