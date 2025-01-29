#include "Fixed.hpp"

#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
/* std::cout << "a is " << a.getRawBits() << " raw bits" << std::endl;
std::cout << "b is " << b.getRawBits() << " raw bits" << std::endl;
std::cout << "c is " << c.getRawBits() << " raw bits" << std::endl;
std::cout << "d is " << d.getRawBits() << " raw bits" << std::endl; */
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
