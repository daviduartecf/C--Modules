#include "Cat.hpp"

Cat::Cat(): Animal(), brain(new Brain()) {
    std::cout << "Cat default constructor called!" << std::endl;
    type = "Cat";
}


Cat::~Cat() {
    std::cout << "Cat destructor called!" << std::endl;
	delete brain;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other)
    {
        this->type = other.type;
		this->brain = new Brain(*other.brainGetter());
    }
    return *this;
}

Cat::Cat(const Cat& other): Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::brainGetter(void) const {
	return this->brain;
}
