#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		void makeSound() const;
};

#endif
