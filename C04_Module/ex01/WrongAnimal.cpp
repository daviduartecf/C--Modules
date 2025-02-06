#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal was constructed\n";
	this->type = "animal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal was destroyed\n";
}

WrongAnimal::WrongAnimal(WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "Wrong Animal was constructed from a copy\n";
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const& other)
{
	this->type = other.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "... wrong animal sound ...\n";
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
