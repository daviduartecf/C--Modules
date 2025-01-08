#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name): _name(name) {
    std::cout << "HumanB created, his name is " << _name << std::endl;
}

HumanB::~HumanB() {
    std::cout << "HumanB " << _name << " died" << std::endl;
}

void    HumanB::attack(void) {
    std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}