#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    std::cout << "ScavTrap Default constructor called." << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDmg = 20;
    _guard_state = false;
}
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap& ScavTrap::operator =(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _guard_state = other._guard_state;
    }
    return *this;
}
ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    _guard_state = other._guard_state;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    std::cout << "ScavTrap Name constructor called." << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDmg = 20;
    _guard_state = false;
}

void    ScavTrap::guardGate(void) {
    if (_guard_state == false) {
        std::cout << "ScavTrap " << _name << "is now in guard keeper mode." << std::endl;
        _guard_state = true;
    }
    else
        std::cout << "ScavTrap " << _name << "is already in guard keeper mode." << std::endl;
}