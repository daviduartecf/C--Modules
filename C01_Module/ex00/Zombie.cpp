#include "Zombie.hpp"

Zombie::Zombie(void) : _name("") {}

Zombie::Zombie(std::string name) : _name(name) {} 

Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " died." << std::endl;
}

void    Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}