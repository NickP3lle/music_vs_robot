#ifndef DEQUE_H
#define DEQUE_H
#define u32 unsigned int
#include <iostream>

template <class T> class deque {
private:
  T *first;
  u32 capacity, size, actual;
  deque(T *, u32, u32, u32);
  void resize();
  bool isFull() const;
  static deque *copy(const deque &);

public:
  deque(u32 = 2);
  deque(const deque &);
  deque &operator=(const deque &);
  ~deque();

  deque &push_back(const T &);
  T pop_front();
  T remove(u32 pos);
  u32 len() const;
  T &operator[](u32) const;
  template <typename S> deque iter(S lambda, u32 begin = 0) const;
  template <typename S> deque iter(S lambda, u32 begin, u32 end) const;
};

template <class T>
deque<T>::deque(T *ptr, u32 capacity, u32 size, u32 actual)
    : first(ptr), capacity(capacity), size(size), actual(actual) {}

template <class T>
deque<T>::deque(u32 cap)
    : deque((T *)malloc(sizeof(T) * (cap ? cap : 1)), cap ? cap : 1, 0, 0) {}

// @bug: potrebbe non funzionare nel modo corretto
template <class T> void deque<T>::resize() {
  capacity = capacity * 2;
  first = (T *)realloc(first, sizeof(T) * capacity);
}

template <class T>
deque<T>::deque(const deque &d) : deque(new T[d.capacity], d.capacity, 0, 0) {
  for (; size < d.size; size++)
    first[size] = d[size];
}

template <class T> deque<T> &deque<T>::operator=(const deque &d) {
  if (this != &d) {
    if (capacity < d.size) {
      delete[] first;
      first = new T[d.capacity];
      capacity = d.capacity;
      actual = 0;
    }
    size = d.size;
    d.iter([first = first](T &x) mutable { *first++ = x; });
  }
  return *this;
}

template <class T> deque<T>::~deque() { delete[] first; }

template <class T> deque<T> &deque<T>::push_back(const T &t) {
  if (size == capacity)
    resize();
  (*this)[size++] = t;
  return *this;
}

template <class T> T deque<T>::pop_front() {
  if (size == 0)
    throw "Deque is empty";
  actual = (actual + 1) % capacity;
  size--;
  return first[actual == 0 ? capacity - 1 : actual - 1];
}

// per l'uso che faccio di deque, in realtà l'ordine non ha molta importanza
// per cui remove cambia l'ordine degli elementi: porta l'elemento in posizione
// 0 nel posto dell'elemento in posizione pos, poi fa un pop_front
template <class T> T deque<T>::remove(u32 pos) {
  if (size == 0)
    throw "Deque is empty";
  T tmp = (*this)[pos];
  (*this)[pos] = (*this)[0];
  (*this)[0] = tmp;
  (*this)[pos] = (*this)[0];
  return pop_front();
}

template <class T> u32 deque<T>::len() const { return size; }

template <class T> T &deque<T>::operator[](u32 index) const {
  return first[(actual + index) % capacity];
}

// ciclo for sulla deque
template <class T>
template <typename S>
deque<T> deque<T>::iter(S lambda, u32 begin) const {
  return iter(lambda, begin, size);
}

// ciclo for sulla deque
template <class T>
template <typename S>
deque<T> deque<T>::iter(S lambda, u32 begin, u32 end) const {
  for (; begin < end; begin++)
    lambda((*this)[begin]);
  return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const deque<T> &d) {
  d.iter([&os](const T &t) { os << t << " "; });
  return os;
}
#endif
