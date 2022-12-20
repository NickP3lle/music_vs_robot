#pragma once
#define u32 unsigned int
#include <algorithm>
#include <iostream>

template <class T> class Iterator {
private:
  T *ptr;
  u32 size;
  Iterator(T *begin, T *end);
  static Iterator<T> copy(const Iterator<T> &other);
  static u32 tmp;
public:
  template <class R>
  Iterator<R> static map(const T *begin, const T *end, R (*)(const T &));
  template <class R>
  Iterator<R> filter(const T *begin, const T *end, R (*)(const T &));
  T &operator[](u32);
  template <class R> R collect() const; // per restituire R deve implementare []
  friend std::ostream &operator<<(std::ostream &os, const Iterator<T> &it);
  Iterator(const Iterator &);
  Iterator &operator=(const Iterator &);
  ~Iterator();
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Iterator<T> &it) {
  std::for_each(it.ptr, it.ptr + it.size, [=](const T &a) { os << a << " "; });
  return os;
}

template <class T>
Iterator<T>::Iterator(T* begin, T* end) : ptr(begin), size(end - begin) {}

template <class T> Iterator<T> Iterator<T>::copy(const Iterator<T> &other) {
  return Iterator<T>(other.ptr, other.ptr + other.size);
}

template <class T>
Iterator<T>::Iterator(const Iterator &it) : Iterator(it.ptr, it.ptr + it.size) {}

template <class T> Iterator<T> &Iterator<T>::operator=(const Iterator &it) {
  if (this != &it) {
    delete[] ptr;
	ptr = new T[it.size];
	size = it.size;
	u32 i = 0;
	transform(it.ptr, it.ptr + it.size, ptr, [](const T &a) { return a; });
  }
  return *this;
}

template <class T> Iterator<T>::~Iterator() { delete[] ptr; }

template <class T>
template <class R>
Iterator<R> Iterator<T>::map(const T *begin, const T *end, R (*f)(const T &)) {
	
}

template <class T>
template <class R>
Iterator<R> Iterator<T>::filter(const T *begin, const T *end,
                                R (*f)(const T &)) {
  u32 count = 0;
  for (tmp = 0; tmp < size; tmp++) {
    if (f(ptr[tmp])) {
      count++;
    }
  }
  Iterator<R> aux(count);
  for (tmp = 0; tmp < size; tmp++) {
    if (f(ptr[tmp])) {
      aux[tmp] = ptr[tmp];
    }
  }
  return aux;
}

template <class T> T &Iterator<T>::operator[](u32 i) { return ptr[i]; }

template <class T> template <class R> R Iterator<T>::collect() const {
  R aux;
  for (tmp = 0; tmp < size; tmp++) {
    aux.push_back(ptr[tmp]);
  }
  return aux;
}
