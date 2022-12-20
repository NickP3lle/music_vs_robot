#ifndef DEQUE_H
#define DEQUE_H
#define u32 unsigned int
#include "ptr.h"

template <class T> class deque {
private:
  u32 size, capacity, actual;
  T *first;
  bool isFull() const;
  void resize();
  static deque *copy(const deque &);
public:
  deque(u32 = 3);
  deque &push_back(const T &);
  ptr<T> pop_front();
  u32 len() const;
  T &operator[](u32) const;
//  template <class R> Iterator<R> map(R (*)(const T &)) const; // constante ?
	friend std::ostream &operator<<(std::ostream &, const deque &);
  deque(const deque &);
  deque &operator=(const deque &);
  ~deque();
};

template <class T> std::ostream &operator<<(std::ostream &os, const deque<T> &d) {
  for (u32 i = 0; i < d.len(); i++) {
	os << d[i] << " ";
  }
  return os;
}

template <class T> deque<T> *deque<T>::copy(const deque &d) {
  deque *tmp = new deque(d.capacity);
  for (u32 i = 0; i < d.size; i++)
    tmp->push_back(d.first[(d.actual + i) % d.capacity]);
  return tmp;
}

template <class T>
deque<T>::deque(u32 c) : size(0), capacity(c), actual(0), first(new T[c]) {}

template <class T>
deque<T>::deque(const deque &d)
    : size(d.size), capacity(d.capacity), actual(0), first(new T[capacity]) {
  for (u32 i = 0; i < size; i++)
    first[i] = d.first[(actual + i) % capacity];
}

template <class T> deque<T> &deque<T>::operator=(const deque &d) {
  if (this != &d) {
    if (capacity != d.capacity) {
      delete[] first;
      first = new T[d.capacity];
      capacity = d.capacity;
      actual = 0;
    }
    for (size = 0; size < d.size; size++)
      first[size] = d.first[(d.actual + size) % capacity];
  }
  return *this;
}

template <class T> deque<T>::~deque() { delete[] first; }

template <class T> bool deque<T>::isFull() const { return size == capacity; }

template <class T> void deque<T>::resize() {
  capacity *= 2;
  *this = *copy(*this);
}

template <class T> deque<T> &deque<T>::push_back(const T &t) {
  if (isFull())
    resize();
  first[(actual + size) % capacity] = t;
  size++;
  return *this;
}

template <class T> ptr<T> deque<T>::pop_front() {
  if (size == 0)
    return ptr<T>(nullptr);
  actual = (actual + 1) % capacity;
  return ptr<T>(this->first[actual == 0 ? capacity - 1 : actual - 1]);
}

template <class T> u32 deque<T>::len() const { return size; }

template <class T> T &deque<T>::operator[](u32 index) const {
  return first[(actual + index) % capacity];
}

/*
template <class T>
template <class R>
Iterator<R> deque<T>::map(R (*f)(const T &)) const {
  deque *tmp = copy(*this);
  return Iterator<T>::map(tmp->first, tmp->first + size, f);
}
*/
#endif
