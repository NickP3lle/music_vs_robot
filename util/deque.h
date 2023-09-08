#pragma once
#define u32 unsigned int
#include <iostream>

template <typename T> class deque {
private:
  T *f;
  u32 c, s, a;
  bool isFull() const;
  void resize();
  static T *copy(const deque &);

public:
  deque(u32 capacity = 2);
  deque(const deque &);
  deque &operator=(const deque &);
  ~deque();

  void push_back(const T &);
  T pop_front();
  bool remove(const T &);
  T remove(u32);
  T &operator[](u32) const;
  u32 size() const;
  template <typename S> const deque &iter(S lambda) const;
  template <typename S, typename U> deque<U> iter(S lambda) const;
  template <typename S> deque<T *> filter(S lambda) const;
};

/// controlla che la size sia uguale alla capacità
template <typename T> bool deque<T>::isFull() const { return s == c; }

/// la capacità è raddoppiata
/// il puntatore al primo elemento è cambiato
/// l'indice di attualità è 0
/// la size rimane invariata
template <typename T> void deque<T>::resize() {
  if (c == 0) {
    c = 2;
    f = new T[c];
    return;
  }
  T *new_f = new T[c * 2];
  iter([f = new_f](T &e) mutable { *(f++) = e; });
  c *= 2, a = 0;
  delete[] f;
  f = new_f;
}

/// ritorna un puntatore al primo elemento
template <typename T> T *deque<T>::copy(const deque &d) {
  if (d.s == 0)
    return nullptr;
  T *f = new T[d.c];
  d.iter([f](const T &e) mutable { *(f++) = e; });
  return f;
}

/// costruttore di default
template <typename T>
deque<T>::deque(u32 capacity)
    : f(capacity == 0 ? nullptr : new T[capacity]), c(capacity), s(0), a(0) {}

/// costruttore di copia
template <typename T>
deque<T>::deque(const deque &d) : f(copy(d)), c(d.c), s(d.s), a(0) {}

/// operatore di assegnamento
template <typename T> deque<T> &deque<T>::operator=(const deque &d) {
  if (this != &d) {
    ~deque();
    f = copy(d);
    c = d.c;
    s = d.s;
    a = 0;
  }
  return *this;
}

/// distruttore
template <typename T> deque<T>::~deque() {
  if (f)
    delete[] f;
}

/// aggiunge un elemento in coda
/// se la size è uguale alla capacità, la capacità viene raddoppiata
template <typename T> void deque<T>::push_back(const T &e) {
  if (isFull())
    resize();
  (*this)[s++] = e;
}

/// rimuove il primo elemento
template <typename T> T deque<T>::pop_front() {
  if (s == 0)
    throw "deque is empty";
  s--;
  a = (a + 1) % c;
  return f[a > 0 ? a - 1 : c - 1];
}

/// rimuove l'elemento passato come parametro,
/// è necessaria l'uguaglianza tra elementi
/// l'ordine degli elementi non è preservato
template <typename T> bool deque<T>::remove(const T &e) {
  for (u32 i = 0; i < s; i++)
    if ((*this)[i] == e) {
      (*this)[i] = (*this)[0];
      pop_front();
      return true;
    }
  return false;
}

/// rimuove l'elemento all'indice passato come parametro
/// l'ordine degli elementi non è preservato
template <typename T> T deque<T>::remove(u32 i) {
  if (i >= s)
    throw "index out of range";
  T e = (*this)[i];
  (*this)[i] = (*this)[0];
  pop_front();
  return e;
}

/// ritorna un riferimento all'elemento all'indice passato come parametro
template <typename T> T &deque<T>::operator[](u32 i) const {
  if (i >= s)
    throw "index out of range";
  return f[(a + i) % c];
}

/// ritorna la size
template <typename T> u32 deque<T>::size() const { return s; }

template <typename T>
template <typename S>
const deque<T> &deque<T>::iter(S lambda) const {
  for (u32 i = 0; i < s; i++)
    lambda((*this)[i]);
  return *this;
}

template <typename T>
template <typename S, typename U>
deque<U> deque<T>::iter(S lambda) const {
  deque<U> d;
  for (u32 i = 0; i < s; i++)
    d.pushback(lambda((*this)[i]));
  return *this;
}

/// ritorna una deque contenente gli elementi per cui lambda ritorna true
/// per cui la firma di lambda deve essere fn(T &) -> bool
template <typename T>
template <typename S>
deque<T *> deque<T>::filter(S lambda) const {
  deque<T *> d;
  iter([&d, lambda](T &e) mutable {
    if (lambda(e))
      d.push_back(&e);
  });
  return d;
}
