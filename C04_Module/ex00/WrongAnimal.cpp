#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal was constructed\n";
	this->type = "";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal was destroyed\n";
}

WrongAnimal::WrongAnimal(WrongAnimal & ref)
{
	this->type = ref.type;
	std::cout << "Wrong Animal was constructed from a copy\n";
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "... wrong animal sound ...\n";
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}
