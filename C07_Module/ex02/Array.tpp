#include <iostream>

template<typename T>
Array<T>::Array(): _array(new T[0]), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) {}


template<typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& other) {
	if (this != &other) {
		delete [] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator [] (unsigned int index) {
	if (index >= _size) {
		throw OutOfRange();
	}
	else
		return _array[index];
}

template <typename T>
const T& Array<T>::operator [](unsigned int index) const {
    if (index >= _size) {
        throw OutOfRange();
    }
    return _array[index];
}


template <typename T>
Array<T>::Array(const Array<T>& other): _size(other._size) {
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

template <typename T>
const char *Array<T>::OutOfRange::what() const throw()
{
	return ("Index out of bounds");
}
