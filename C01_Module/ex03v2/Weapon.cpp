#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {
    std::cout << "CREATED" << std::endl;
}

Weapon::~Weapon() {
    std::cout << "DESTROYED" << std::endl;
}

const std::string& Weapon::getType(void) {
    return (_type);
}

void Weapon::setType(std::string type) {
    _type = type;
}