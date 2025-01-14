#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

float   Fixed::toFloat(void) const {
    return (float)(_value / (float)(1 << _fractionalBits));
}

int     Fixed::toInt(void) const {
    return (_value >> _fractionalBits);
}

Fixed::Fixed(int const num) {
    std::cout << "Int constructor called" << std::endl;
    _value = num << _fractionalBits;
}

Fixed::Fixed(float const num) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(num * (1 << _fractionalBits));
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