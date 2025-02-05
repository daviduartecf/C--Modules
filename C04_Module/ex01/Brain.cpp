#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator =(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i ++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::Brain(const Brain& other) {
	*this = other;
}

void Brain::ideaSetter(const std::string& string, int i) {
	if (i >= 0 && i <= 99) {
		ideas[i] = string;
	}
	else
		std::cout << "Out of range" << std::endl;
}

std::string Brain::ideaGetter(int i) const {
	return ideas[i];
}
