#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon) {
    std::cout << "HumanA created, his name is " << _name << std::endl;
}

HumanA::~HumanA() {
    std::cout << "HumanA " << _name << " died" << std::endl;
}

void    HumanA::attack(void) {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}


