#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>

class WrongAnimal {
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator = (const Animal& other);
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
};

#endif