#pragma once

#include "cloneable.h"
#include <type_traits>

template <typename T> class ptr {
  static_assert(std::is_base_of<ClonableInterface, T>::value,
                "T must inherit from ClonableInterface.");

private:
  T *p;

public:
  ptr(const T *const = nullptr);
  ptr(const ptr &);
  ptr &operator=(const ptr &);
  ~ptr();

  T *operator->() const;
  T &operator*() const;
  operator bool() const;
};

#include <iostream>
template <typename T>
ptr<T>::ptr(const T *const ptr)
    : p(ptr ? static_cast<T *>(ptr->clone()) : nullptr) {}

template <typename T>
ptr<T>::ptr(const ptr &o) : p(o ? static_cast<T *>(o.p->clone()) : nullptr) {}

template <typename T> ptr<T> &ptr<T>::operator=(const ptr &o) {
  if (this != &o) {
    delete p;
    p = o ? static_cast<T *>(o.p->clone()) : nullptr;
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
