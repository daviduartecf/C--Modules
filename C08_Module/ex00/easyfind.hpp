#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

class NotFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return "Value not found!";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int num) {
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
}

#endif
