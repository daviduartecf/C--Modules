#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define BLUE "\e[34m"
#define RESET "\e[0m"

int main()
{
    std::cout << "===== Creating Individual Animals =====" << std::endl;

    const Dog* j = new Dog();
    const Animal* i = new Cat();

    j->brainGetter()->ideaSetter("This is one stupid idea", 0);
    std::cout << BLUE << j->brainGetter()->ideaGetter(0) << RESET << std::endl;

    const Dog* k = new Dog(*j);
    std::cout << BLUE << k->brainGetter()->ideaGetter(0) << RESET << std::endl;

    std::cout << "===== Deleting Individual Animals =====" << std::endl;
    delete k;
    delete j;
    delete i;

    std::cout << "===== Creating Array of Animals =====" << std::endl;
    const int size = 6;
    Animal* animals[size];

    for (int x = 0; x < size / 2; x++)
        animals[x] = new Dog();
    for (int x = size / 2; x < size; x++)
        animals[x] = new Cat();

    std::cout << "===== Deleting Array of Animals =====" << std::endl;
    for (int x = 0; x < size; x++)
        delete animals[x];

    return 0;
}
