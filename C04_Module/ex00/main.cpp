#include <iostream>
#include <string.h>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;  // Dog
    std::cout << i->getType() << std::endl;  // Cat

    i->makeSound();  // Meow! Meow!
    j->makeSound();  // Woof! Woof!
    meta->makeSound();  // Some generic animal sound!

    delete meta;  // Calls Animal destructor
    delete j;     // Calls Dog destructor
    delete i;     // Calls Cat destructor

    return 0;
}