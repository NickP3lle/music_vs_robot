#pragma once
#define u32 unsigned int
#include <algorithm>
#include <iostream>

template <class T> class Iterator {
private:
  T *ptr;
  u32 size;
  Iterator(T *begin, u32 size);
  static Iterator<T> copy(const Iterator<T> &other);

public:
  template <class R>
  // questa funzione è da sovrascrivere nel contenitore
  Iterator<R> static map(const T *begin, const T *end, R (*)(const T &));
  Iterator<T> map(void (*func)(T &));
  Iterator<T> filter(const T *begin, const T *end, bool (*)(const T &));
  T &operator[](u32);
  template <class R> R collect(); // per restituire R deve implementare []
  friend std::ostream &operator<<(std::ostream &os, const Iterator<T> &it);
  Iterator(const Iterator &);
  Iterator &operator=(const Iterator &);
  ~Iterator();
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Iterator<T> &it) {
  std::for_each(it.ptr, it.ptr + it.size, [&](const T &a) { os << a << " "; });
  return os;
}

template <class T>
Iterator<T>::Iterator(T *begin, u32 s) : ptr(begin), size(s) {}

template <class T> Iterator<T> Iterator<T>::copy(const Iterator<T> &other) {
  T *aux = new T[other.size];
  std::transform(other.begin, other.begin + other.size, aux,
            [](const T &a) { return a; });
  return Iterator(aux, other.size);
}

template <class T>
Iterator<T>::Iterator(const Iterator &it) : Iterator(new T[size], size) {
  std::transform(it.ptr, it.ptr + size, ptr, [](const T &a) { return a; });
}

template <class T> Iterator<T> &Iterator<T>::operator=(const Iterator &it) {
  if (this != &it) {
    delete[] ptr;
    ptr = new T[it.size];
    size = it.size;
    u32 i = 0;
    std::transform(it.ptr, it.ptr + it.size, ptr, [](const T &a) { return a; });
  }
  return *this;
}

template <class T> Iterator<T>::~Iterator() { delete[] ptr; }

template <class T> Iterator<T> Iterator<T>::map(void (*func)(T &)) {
  std::transform(ptr, ptr + size, ptr, func);
}

template <class T>
template <class R>
Iterator<R> Iterator<T>::map(const T *begin, const T *end, R (*f)(const T &)) {
  R *aux = new R[end - begin];
  std::transform(begin, end, aux, f);
  return Iterator(aux, end - begin);
}

template <class T>
Iterator<T> Iterator<T>::filter(const T *begin, const T *end,
                                bool (*f)(const T &)) {
  u32 count = 0;
  std::for_each(begin, end, [&](const T &a) {
    if (f(a))
      count++;
  });
  T *aux = new T[count];
  count = 0;
  while (begin != end)
    if (f(*begin))
      aux[count++] = *begin;
  return Iterator(aux, count);
}

template <class T> T &Iterator<T>::operator[](u32 i) { return ptr[i]; }

template <class T> template <class R> R Iterator<T>::collect() {
  R aux;
  while (size)
    aux.push_back(*ptr), size--;
  // anche aux[tmp]
  return aux;
}
