#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string.h>
#include <iostream>

class AAnimal {
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator = (const AAnimal& other);
        virtual void makeSound() const = 0;
        std::string getType() const;
    protected:
        std::string type;
};

#endif
