#ifndef PTR_SAFE
#define PTR_SAFE
#include <iostream>

template <class T> class ptr {
private:
  T *data;

public:
  ptr(const T &);
  ptr();
  ptr(T *const);
  ptr(T *, bool);
  ptr(const ptr &);
  ptr &operator=(const ptr &);
  ~ptr();
  bool isPtr() const;
  bool isNone() const;
  const T &get() const;
  const T &operator*() const;
  T &get_mut();
  void free();
};

template <class T> ptr<T>::ptr() : ptr(nullptr, false) {}

template <class T> ptr<T>::ptr(T *const t) : data(t ? new T(*t) : t) {}

template <class T> ptr<T>::ptr(T *t, bool dealloc) : data(t) {
  if (dealloc)
    throw "using wrong constructor";
}

template <class T> ptr<T>::ptr(const T &t) : data(new T(t)) {}

template <class T> ptr<T>::ptr(const ptr &Ptr) : data(new T(*Ptr.data)) {}

template <class T> ptr<T>::~ptr() {
  if (data) {
    delete data;
    data = nullptr;
  }
}

template <class T> ptr<T> &ptr<T>::operator=(const ptr &s) {
  if (this != &s && s.data) {
    if (data)
      delete data;
    data = s.data;
    const_cast<ptr<T> &>(s).data = nullptr;
  }
  return *this;
}

template <class T> bool ptr<T>::isPtr() const { return data; }

template <class T> bool ptr<T>::isNone() const { return !data; }

template <class T> const T &ptr<T>::get() const { return *data; }

template <class T> const T &ptr<T>::operator*() const { return *data; }

template <class T> T &ptr<T>::get_mut() { return *data; }

template <class T> void ptr<T>::free() {
  if (data) {
    delete data;
    data = nullptr;
  }
}
#endif
