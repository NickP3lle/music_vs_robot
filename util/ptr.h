#ifndef PTR_SAFE
#define PTR_SAFE
#include <iostream>
#include <typeinfo>

template <class T> class ptr {
private:
  T *data;
  unsigned int *refCount;

public:
  ptr(T *const = nullptr);
  ptr(const T &);
  ptr(const ptr &);
  ptr &operator=(const ptr &);
  ~ptr();
  operator bool() const;
  const T &get() const;
  const T &operator*() const;
  T &get_mut();
};

template <class T>
ptr<T>::ptr(T *ptr_t)
    : data(ptr_t), refCount(ptr_t ? new unsigned int(1) : nullptr) {}

template <class T> ptr<T>::ptr(const T &t) : ptr(new T(t)) {}

template <class T>
ptr<T>::ptr(const ptr &Ptr) : data(Ptr.data), refCount(Ptr.refCount) {
  if (refCount)
    ++(*refCount);
}

template <class T> ptr<T>::~ptr() {
  if (data) {
    (*refCount)--;
    if (*refCount == 0) {
      delete data;
      data = nullptr;
      delete refCount;
    }
  }
}

template <class T> ptr<T> &ptr<T>::operator=(const ptr &s) {
  if (this != &s) {
    if (data) {
      if (--(*refCount) == 0) {
        delete data;
        data = nullptr;
        delete refCount;
      }
    }
    data = s.data;
    refCount = s.refCount;
    if (*this)
      (*refCount)++;
  }
  return *this;
}

template <class T> ptr<T>::operator bool() const { return data; }

template <class T> const T &ptr<T>::get() const { return *data; }

template <class T> const T &ptr<T>::operator*() const { return *data; }

template <class T> T &ptr<T>::get_mut() {
  if (*refCount > 1) {
    (*refCount)--;
    refCount = new unsigned int(1);
    data = data->clone();
  }
  return *data;
}
#endif
