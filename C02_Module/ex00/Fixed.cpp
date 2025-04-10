#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator = (const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

int  Fixed::getRawBits(void) const {
    std::cout << "getRawBits function called" << std::endl;
    return _value;
}

void  Fixed::setRawBits(int const raw) {
    _value = raw;
}
