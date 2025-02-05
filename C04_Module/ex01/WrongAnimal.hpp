#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

// Abstract class Animal
class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(WrongAnimal & ref);
		WrongAnimal & operator=(WrongAnimal const & rhs);

		// virtual member function = "method"
		// this makes the program to decide which method to use during the
		// execution (and not compilation)
		void makeSound() const;
		std::string getType( void ) const;
};

#endif
