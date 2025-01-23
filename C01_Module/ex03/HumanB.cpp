#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
    std::cout << "Human B " << _name << " created" << std::endl;
}

HumanB::~HumanB() {
     std::cout << "Human B " << _name << " died" << std::endl;
}

void HumanB::attack(void) {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " does not have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}
