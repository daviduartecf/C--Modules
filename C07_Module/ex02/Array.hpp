#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array& operator = (const Array& other);
		T& operator [] (unsigned int index);
		Array(const Array& other);
		class OutOfRange: public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		T* _array;
		unsigned int _size;
};

#include "Array.tpp"

#endif
