#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	const WrongAnimal* l = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << "--------------------------" << std::endl;

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
	std::cout << l->getType() << std::endl;
    std::cout << k->getType() << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << "--------------------------" << std::endl;

	std::cout << "######CAT#######" << std::endl;
    i->makeSound();
	std::cout << "######DOG#######" << std::endl;
    j->makeSound();
	std::cout << "######ANIMAL#######" << std::endl;
    meta->makeSound();
	std::cout << "######WRONGANIMAL#######" << std::endl;
    k->makeSound();
	std::cout << "######CAT#######" << std::endl;
    l->makeSound();
	std::cout << "--------------------------" << std::endl;

    delete meta;
    delete j;
    delete i;
	delete l;
	delete k;

    return 0;
}
