#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(WrongAnimal & ref);
		WrongAnimal & operator=(WrongAnimal const & rhs);
		void makeSound() const;
		std::string getType( void ) const;
};

#endif
