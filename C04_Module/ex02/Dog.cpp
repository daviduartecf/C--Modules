#include "Dog.hpp"

Dog::Dog(): AAnimal(), brain(new Brain()) {
    std::cout << "Dog default constructor called!" << std::endl;
    type = "Dog";
}


Dog::~Dog() {
    std::cout << "Dog destructor called!" << std::endl;
	delete brain;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other)
    {
        this->type = other.type;
		this->brain = new Brain(*other.brainGetter());
    }
    return *this;
}

Dog::Dog(const Dog& other): AAnimal(other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::brainGetter(void) const {
	return this->brain;
}
