#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {
    std::cout << "CREATED" << std::endl;
}

Weapon::~Weapon() {
    std::cout << "DESTROYED" << std::endl;
}

const std::string& Weapon::getType(void) const {
    return (_type);
}

void Weapon::setType(const std::string& type) {
    _type = type;
}