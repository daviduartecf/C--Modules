#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

//To store a int as a fixed-point just scale up 2^fractionalbits 
//shift left
Fixed::Fixed(int const num) {
    std::cout << "Int constructor called" << std::endl;
    _value = num << _fractionalBits;
}

//To store a float as a fixed-point we cant bitshift because 
//floating-point nums are not integers
//BIT SHIFT only work on integers
//So we multiply by 2^fractionalbits
Fixed::Fixed(float const num) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(num * (1 << _fractionalBits));
}

float   Fixed::toFloat(void) const {
    return (float)(_value / (float)(1 << _fractionalBits));
}

int     Fixed::toInt(void) const {
    return (_value >> _fractionalBits);
}
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
    return _value;
}

void  Fixed::setRawBits(int const raw) {
    _value = raw;
}