#ifndef ITERATOR_H
#define ITERATOR_H
#define u32 unsigned int
#include <algorithm>
#include <iostream>
#include <typeinfo>

template <class T> class Iterator;

template <class T>
std::ostream &operator<<(std::ostream &, const Iterator<T> &);

// ci sono due modi per implementare map:
// 1) map ritorna un iteratore che itera su un nuovo vettore (comodo
// templatizzare il vettore)
// 2) map ritorna un iteratore che itera su un vettore esistente
// nel secondo caso l'iteratore non è generato nuovamente ogni volta,
// ma è molto meno flessibile
template <class T> class Iterator {
  friend std::ostream &operator<< <T>(std::ostream &, const Iterator &);

private:
  T *ptr;
  u32 size;
  bool dealloc;

public:
  Iterator(T *begin, u32 size, bool Deallocate = true);
  T *const begin() const;
  T *const end() const;
  T &operator[](u32) const;
  u32 len() const;
  template <typename S> Iterator map(S lambda) const;
  template <typename S> Iterator<T *> filter(S lambda) const;
  template <class R>
  R collect() const; // per restituire R deve implementare
                     // push_back
  Iterator(const Iterator &);
  Iterator &operator=(const Iterator &);
  ~Iterator();
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Iterator<T> &it) {
  it.map([&os](T &a) { os << a << " "; });
  return os;
}

template <class T>
Iterator<T>::Iterator(T *begin, u32 s, bool flag)
    : ptr(begin), size(s), dealloc(flag) {}

template <class T>
Iterator<T>::Iterator(const Iterator &it)
    : Iterator(new T[it.len()], it.len()) {
  std::copy(it.begin(), it.end(), begin());
}

template <class T> Iterator<T> &Iterator<T>::operator=(const Iterator &it) {
  if (this != &it) {
    delete[] ptr;
    size = it.len();
    ptr = new T[len()];
    std::transform(it.ptr, it.ptr + size, ptr, [](const T &a) { return a; });
  }
  return *this;
}

template <class T> Iterator<T>::~Iterator() {
  if (dealloc)
    delete[] ptr;
}

template <class T> T *const Iterator<T>::begin() const { return ptr; }

template <class T> T *const Iterator<T>::end() const { return ptr + len(); }

template <class T> T &Iterator<T>::operator[](u32 index) const {
  return ptr[index];
}

template <class T> u32 Iterator<T>::len() const { return size; }

template <class T>
template <typename S>
Iterator<T> Iterator<T>::map(S lambda) const {
  std::for_each(begin(), end(), lambda);
  return *this;
}

template <class T>
template <typename S>
Iterator<T *> Iterator<T>::filter(S lambda) const {
  u32 count = 0;
  map([&](T &a) {
    if (lambda(a))
      count++;
  });
  T **new_ptr = new T *[count];
  map([&, new_ptr](T &a) mutable {
    if (lambda(a))
      *new_ptr++ = &a;
  });
  return Iterator<T *>(new_ptr, count);
}

template <class T> template <class R> R Iterator<T>::collect() const {
  R aux;
  map([&aux](const T &a) { aux.push_back(a); });
  return aux;
}
#endif
