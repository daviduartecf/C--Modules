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

WrongCat::WrongCat(WrongCat & ref)
{
	this->type = ref.getType();
	std::cout << "A wrong cat was constructed from copy\n";
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Fake meow meow\n";
}
