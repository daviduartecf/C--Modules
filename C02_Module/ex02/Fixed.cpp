#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed& Fixed::min(Fixed& one, Fixed& two) {
    if (two < one)
        return two;
    return one;
}

Fixed& Fixed::max(Fixed& one, Fixed& two) {
    if (two > one)
        return two;
    return one;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two) {
    if (two.toFloat() < one.toFloat())
        return two;
    return one;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two) {
    if (two.toFloat() > one.toFloat())
        return two;
    return one;
}

//Post-increment operator
//The int parameter is a "dummy parameter", just there to diferenciate from the pre-increment operator
Fixed Fixed::operator ++(int) {
    Fixed tmp = *this;
    _value ++;
    return tmp;
}
//In post operators we return the Object (Fixed) and not a reference (Fixed&) because we want to
//return the state of the object before the operator (through a copy). If we send the reference, it will always
//be updated.
//Post-decrement operator
Fixed Fixed::operator --(int) {
    Fixed tmp = *this;
    _value --;
    return tmp;
}

//Pre operators
Fixed& Fixed::operator ++(void) {
    _value ++;
    return *this;
}

Fixed& Fixed::operator --(void) {
    _value --;
    return *this;
}

float Fixed::operator * (const Fixed& other) {
    return (this->toFloat() * other.toFloat());
}

float Fixed::operator / (const Fixed& other) {
    return (this->toFloat() / other.toFloat());
}

float Fixed::operator + (const Fixed& other) {
    return (this->toFloat() + other.toFloat());
}

float Fixed::operator - (const Fixed& other) {
    return (this->toFloat() - other.toFloat());
}

bool Fixed::operator == (const Fixed& other) {
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator != (const Fixed& other) {
    return (this->toFloat() != other.toFloat());
}

bool Fixed::operator <= (const Fixed& other) {
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator >= (const Fixed& other) {
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator < (const Fixed& other) {
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator > (const Fixed& other) {
    return (this->toFloat() > other.toFloat());
}

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