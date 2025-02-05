#include "AAnimal.hpp"
#include "colors.h"

AAnimal::AAnimal() {
    std::cout << GREEN "AAnimal default constructor called!" RESET << std::endl;
    type = "";
}


AAnimal::~AAnimal() {
    std::cout << RED "AAnimal destructor called!" RESET << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& other) {
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << GREEN "Copy constructor called" RESET << std::endl;
    *this = other;
}

void AAnimal::makeSound() const {
    std::cout << YELLOW "Some generic AAnimal sound!" RESET << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}
