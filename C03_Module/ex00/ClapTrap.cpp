#include "ClapTrap.hpp"

unsigned int	ClapTrap::getEnergy(void) const {
	return _energyPoints;
}

unsigned int	ClapTrap::getHitpoints(void) const {
	return _hitPoints;
}

unsigned int	ClapTrap::getAttackdmg(void) const {
	return _attackDmg;
}

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called" << std::endl;
    _name = "Default";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDmg = 0;
}

ClapTrap::~ClapTrap() {
    std::cout << "Default destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator =(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDmg = other._attackDmg;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
    std::cout << "Name constructor called" << std::endl;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDmg = 0;
}

void    ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " doesn't have energy points!" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " can't attack, it is dead!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
    else if (this->_hitPoints > amount) {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage and has " << this->_hitPoints << " left." << std::endl;
    }
    else {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " of damage and died!" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " repaired itself and got " << amount << " hit points, he has " << this->_hitPoints << std::endl;
    }
    else if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " can't be repaired. No energy!" << std::endl;
    else if (this->_hitPoints == 0)
        std::cout << "ClapTrap " << this->_name << " can't be repaired. He is dead!" << std::endl;
}
