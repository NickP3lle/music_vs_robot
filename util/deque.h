#define u32 unsigned int
#include "some.h"

#ifndef DEQUE_H
#define DEQUE_H
template <class T>
class deque {
	private:
		u32 size, capacity, actual;
		T* first ;
		bool isFull() const;
		void resize();
		static deque* copy(const deque&); 

	public:
		deque(u32 =3);
		void push_back(const T&);
		Some<T> pop_front();
		
		deque(const deque&);
		deque& operator=(const deque&);
		~deque();
};

template<class T>
deque<T>* deque<T>::copy(const deque& d) {
	deque* tmp = new deque(d.capacity);
	for (u32 i = 0; i < d.size; i++)
		tmp->push_back(d.first[(d.actual+i)%d.capacity]);
	return tmp;
}

template <class T>
deque<T>::deque(u32 c):
	size(0), capacity(c), actual(0), first(new T[c]) {};

template <class T>
deque<T>::deque(const deque& d):
	size(d.size), capacity(d.capacity), actual(0), first(new T[capacity]) {
		for (u32 i=0; i<size; i++)
			first[i] = d.first[(actual+i)%capacity];
}

template <class T>
deque<T>& deque<T>::operator=(const deque& d) {
	if (this != &d) {
		if (capacity != d.capacity) {
			delete[] first;
			first = new T[d.capacity];
			capacity = d.capacity;
			actual = 0;
		}
		for (size=0; size<d.size; size++)
			first[size] = d.first[(d.actual+size)%capacity];
	}
	return *this;
}

template <class T>
deque<T>::~deque() {
	delete[] first;
}

template <class T>
bool deque<T>::isFull() const {
	return size == capacity;
}

template <class T>
void deque<T>::resize() {
	capacity *= 2;
	*this = *copy(*this);
}

template<class T>
void deque<T>::push_back(const T& t) {
	if (isFull()) resize();
	first[(actual+size)%capacity] = t;
	size++;
}

template<class T>
Some<T> deque<T>::pop_front() {
	if (size==0) return Some<T>(nullptr);
	actual = (actual+1)%capacity;
	return Some<T>(this->first[actual==0?capacity-1:actual-1]);
}
#endif
