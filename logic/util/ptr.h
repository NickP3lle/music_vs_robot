#pragma once

#include "cloneable.h"
#include <type_traits>

template <typename T> class ptr {
  static_assert(std::is_base_of<Cloneable, T>::value,
                "T must inherit from Cloneable.");

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

template <typename T> ptr<T>::ptr(T *const p) : p(p->clone()) {}

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
}

template <typename T> T *ptr<T>::operator->() const { return p; }

template <typename T> T &ptr<T>::operator*() const { return *p; }

template <typename T> ptr<T>::operator bool() const { return p != nullptr; }
