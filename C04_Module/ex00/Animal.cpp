#include "Animal.hpp"
#include "colors.h"

Animal::Animal() {
    std::cout << GREEN "Animal default constructor called!" RESET << std::endl;
    type = "";
}


Animal::~Animal() {
    std::cout << RED "Animal destructor called!" RESET << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::Animal(const Animal& other) {
    std::cout << GREEN "Animal copy constructor called" RESET << std::endl;
    *this = other;
}

void Animal::makeSound() const {
    std::cout << YELLOW "Some generic animal sound!" RESET << std::endl;
}

std::string Animal::getType() const {
    return type;
}
