#include "Fixed.hpp"

#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	//the unit is added to _value
	//std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	//std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	Fixed x( Fixed(b) / Fixed(2) );
	std::cout << x << std::endl;
	Fixed l;
	l++;
	Fixed y(Fixed(1000) * l);
	std::cout << y.getRawBits() << std::endl;
	std::cout << y << std::endl;

	Fixed k(0.00390625f);
	std::cout << k.getRawBits() << std::endl;
	std::cout << k << std::endl;
	std::cout << k + k << std::endl;
	return 0;
}
