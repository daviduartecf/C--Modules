#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon) {
    std::cout << "Human A <" << _name << "> created" << std::endl;
}

HumanA::~HumanA() {
     std::cout << "Human A <" << _name << "> died" << std::endl;
}

void HumanA::attack(void) {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}