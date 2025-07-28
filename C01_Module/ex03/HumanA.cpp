#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon) {
	std::cout << "Human A " << _name << " created" << std::endl;
	new alguma;
}

HumanA::~HumanA() {
     std::cout << "Human A " << _name << " died" << std::endl;
	delete alguma;
	}

void HumanA::attack(void) {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
