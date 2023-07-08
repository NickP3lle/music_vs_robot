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
  void pop(u32 pos);
  u32 len() const;
  T &operator[](u32) const;
  template <typename S> deque iter(S lambda, u32 begin = 0) const;
  template <typename S> deque iter(S lambda, u32 begin, u32 end) const;
};

template <class T>
deque<T>::deque(T *ptr, u32 capacity, u32 size, u32 actual)
    : first(ptr), capacity(capacity), size(size), actual(actual) {}

template <class T>
deque<T>::deque(u32 cap) : deque(new T[cap ? cap : 1], cap ? cap : 1, 0, 0) {}

// @bug: potrebbe non funzionare nel modo corretto
template <class T> void deque<T>::resize() {
  T *n_first = new T[capacity * 2];
  for (u32 i = 0; i < size; i++) {
    n_first[i] = (*this)[i];
  }
  delete[] first;
  first = n_first;
  capacity *= 2;
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
  if (size == capacity) {
    std::cout << "resize\n";
    resize();
    std::cout << "end resize\n";
  }
  std::cout << "push 1\n";
  (*this)[size++] = t;
  std::cout << "push 2\n";
  return *this;
}

template <class T> T deque<T>::pop_front() {
  if (size == 0)
    throw "Deque is empty";
  T tmp = first[actual];
  actual = (actual + 1) % capacity;
  size--;
  return tmp;
}

// per l'uso che faccio di deque, in realtà l'ordine non ha molta importanza
// per cui remove cambia l'ordine degli elementi: porta l'elemento in posizione
// 0 nel posto dell'elemento in posizione pos, poi fa un pop_front
template <class T> T deque<T>::remove(u32 pos) {
  if (size == 0)
    throw "Deque is empty";
  else if (pos >= size)
    throw "Index out of range";
  else if (pos > 0) {
    T tmp = (*this)[pos];
    (*this)[pos] = (*this)[0];
    actual = (actual + 1) % capacity;
    size--;
    return tmp;
  } else {
    return pop_front();
  }
}

template <class T> void deque<T>::pop(u32 pos) {
  std::cout << "pop 1\n";
  (*this)[pos] = (*this)[0];
  std::cout << "pop 2\n";
  actual = (actual + 1) % capacity;
  std::cout << "pop 3\n";
  size--;
  std::cout << "pop 4\n";
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
