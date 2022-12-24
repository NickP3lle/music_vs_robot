#pragma once
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
  T &operator[](u32) const;
  u32 len() const;
  template <typename S> Iterator map(S &&lambda) const;
  // fa la copia, non si possono passare puntatori per qualche motivo
  template <typename R> Iterator<T *> filter(R &&lambda) const;
  template <class R>
  R collect() const; // per restituire R deve implementare
                     // push_back
  /*
     template <class R, class S>
    Iterator<R> map(const T *begin, const T *end, R (*)(S)) const;
    template <typename S> Iterator<T> map(S &&labda);
    template <class R> Iterator<T> map(void (*func)(R));
    Iterator<T> filter(const T *begin, const T *end, bool (*)(const T &));
  */
  Iterator(const Iterator &);
  Iterator &operator=(const Iterator &);
  ~Iterator();
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Iterator<T> &it) {
  it.map([&](T &a) { os << a << " "; });
  return os;
}

template <class T>
Iterator<T>::Iterator(T *begin, u32 s, bool flag)
    : ptr(begin), size(s), dealloc(flag) {}

template <class T>
Iterator<T>::Iterator(const Iterator &it) : Iterator(new T[it.size], it.size) {
	std::copy(it.ptr, it.ptr + it.size, ptr);
}

template <class T> Iterator<T> &Iterator<T>::operator=(const Iterator &it) {
  if (this != &it) {
    delete[] ptr;
    size = it.size;
    ptr = new T[size];
    std::transform(it.ptr, it.ptr + size, ptr, [](const T &a) { return a; });
  }
  return *this;
}

template <class T> Iterator<T>::~Iterator() {
  if (dealloc)
    delete[] ptr;
}

template <class T> T &Iterator<T>::operator[](u32 index) const {
  return ptr[index];
}

template <class T> u32 Iterator<T>::len() const { return size; }

template <class T>
template <typename S>
Iterator<T> Iterator<T>::map(S &&lambda) const {
  std::for_each(ptr, ptr + size, lambda);
  return *this;
}

template <class T>
template <typename R>
Iterator<T *> Iterator<T>::filter(R &&lambda) const {
  u32 count = 0;
  map([&](const T &a) {
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

/*
template <class T>
template <class R>
Iterator<T> Iterator<T>::map(void (*func)(R)) {
  std::for_each(ptr, ptr + size, func);
}

template <class T>
template <class R, class S>
Iterator<R> Iterator<T>::map(const T *begin, const T *end, R (*f)(S)) const {
  R *aux = new R[end - begin];
  std::transform(begin, end, aux, f);
  return Iterator(aux, end - begin);
}

template <class T>
template <typename S>
Iterator<T> Iterator<T>::map(S &&lambda) {
  std::for_each(ptr, ptr + size, lambda);
  return *this;
}

template <class T>
template <class R, typename S>
Iterator<R> Iterator<T>::map(S &&lambda) {
  R *aux = new R[size];
  std::transform(ptr, ptr + size, aux, lambda);
  return Iterator(aux, size);
}

template <class T>
Iterator<T> Iterator<T>::filter(const T *begin, const T *end,
                                bool (*f)(const T &)) {
  u32 count = 0;
  T *aux = new T[count];
  map([&](const T &a) {
    if (f(a))
      count++;
  });
  aux = new T[count];
  map([=](const T &a) mutable {
    if (f(a)) {
      *(aux++) = a;
    }
  });
  return Iterator(aux, count);
}


  */
