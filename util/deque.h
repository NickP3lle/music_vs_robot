#ifndef DEQUE_H
#define DEQUE_H
#define u32 unsigned int
#include <iostream>

template <class T> class deque {
private:
  T *first;
  u32 capacity, size, actual;
  void resize();
  bool isFull() const;
  static T *copy(const deque &);

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
  template <typename S> const deque &iter(S lambda, u32 begin = 0) const;
  template <typename S> const deque &iter(S lambda, u32 begin, u32 end) const;
};

template <class T> T *deque<T>::copy(const deque &d) {
  T *n_first = new T[d.capacity];
  d.iter([first = n_first](T &x) mutable { *first++ = x; });
  return n_first;
}

template <class T>
deque<T>::deque(u32 cap)
    : first(cap == 0 ? nullptr : new T[cap]), capacity(cap), size(0),
      actual(0) {}

template <class T> void deque<T>::resize() {
  if (first == nullptr) {
    first = new T[2];
    capacity = 2;
    return;
  }

  T *n_first = new T[capacity * 2];
  iter([first = n_first](T &x) mutable { *first++ = x; });
  delete[] first;
  first = n_first;
  capacity *= 2;
  actual = 0;
}

template <class T>
deque<T>::deque(const deque &d)
    : first(copy(d)), capacity(d.capacity), size(d.size), actual(d.actual) {}

template <class T> deque<T> &deque<T>::operator=(const deque &d) {
  if (this != &d) {
    if (first != nullptr)
      delete[] first;
    first = copy(d);
    actual = 0;
    capacity = d.capacity;
    size = d.size;
  }
  return *this;
}

template <class T> deque<T>::~deque() {
  if (first != nullptr)
    delete[] first;
}

template <class T> deque<T> &deque<T>::push_back(const T &t) {
  if (size == capacity) {
    resize();
  }
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
    // throw "Deque is empty";
    std::cerr << "Deque is empty" << std::endl;
  else if (pos >= size)
    // throw "Index out of range";
    std::cerr << "Index out of range" << std::endl;
  T tmp = (*this)[pos];
  (*this)[pos] = (*this)[0];
  (*this)[0] = tmp;
  return pop_front();
}

template <class T> u32 deque<T>::len() const { return size; }

template <class T> T &deque<T>::operator[](u32 index) const {
  return first[(actual + index) % capacity];
}

// ciclo for sulla deque
template <class T>
template <typename S>
const deque<T> &deque<T>::iter(S lambda, u32 begin) const {
  return iter(lambda, begin, size);
}

// ciclo for sulla deque
template <class T>
template <typename S>
const deque<T> &deque<T>::iter(S lambda, u32 begin, u32 end) const {
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
