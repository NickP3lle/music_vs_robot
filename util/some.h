#include <iostream>
#include "ptr.h"

#ifndef SOME
#define SOME

template<class T>
class Some: private ptr<T> {
    public:
		Some(const T&);
		Some(const T*);
        T unwrap();
        bool isSome() const;
        bool isNone() const;
};

template<class T>
Some<T>::Some(const T& t): ptr<T>::ptr(t) {}

template<class T>
Some<T>::Some(const T* t): ptr<T>::ptr(t) {}

template<class T>
T Some<T>::unwrap() {
    if (ptr<T>::isPtr()) {
        return ptr<T>::get();
    }
	throw On_unwrap;
}

template<class T>
bool Some<T>::isSome() const {
    return ptr<T>::isPtr();
}

template<class T>
bool Some<T>::isNone() const {
    return ptr<T>::isNone();
}
#endif
