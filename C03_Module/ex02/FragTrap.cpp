#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
    std::cout << "Default FragTrap constructor called." << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDmg = 30;
}
FragTrap::~FragTrap() {
    std::cout << "Default FragTrap destructor called." << std::endl;
}

FragTrap& FragTrap::operator =(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}
FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    std::cout << "Name FragTrap constructor called." << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDmg = 30;
}

void    FragTrap::highFivesGuys(void) {
        std::cout << "FragTrap " << _name << " wants to high five!" << std::endl;
}