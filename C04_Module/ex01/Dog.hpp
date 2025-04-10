#ifndef DOG_HPP
#define DOG_HPP

#include <string.h>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog& operator = (const Dog& other);
        void makeSound() const;
		Brain* brainGetter(void) const;
	private:
		Brain *brain;
};

#endif
