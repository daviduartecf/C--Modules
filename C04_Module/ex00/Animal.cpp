#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called!" << std::endl;
    type = "";
}


Animal::~Animal() {
    std::cout << "Animal destructor called!" << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::Animal(const Animal& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}