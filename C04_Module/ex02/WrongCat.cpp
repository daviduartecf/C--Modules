#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "wrong cat";
	std::cout << "A wrong cat was constructed\n";
}

WrongCat::~WrongCat()
{
	std::cout << "A wrong cat was destroyed\n";
}

WrongCat::WrongCat(WrongCat& other)
{
	this->type = other.getType();
	std::cout << "A wrong cat was constructed from copy\n";
}

WrongCat & WrongCat::operator=(const WrongCat& other)
{
	this->type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Fake meow meow\n";
}
