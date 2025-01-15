#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap
{
    public:
        //Orthodox Canonical Form
        ClapTrap();
        ~ClapTrap();
        ClapTrap& operator = (const ClapTrap& other);
        ClapTrap(const ClapTrap& other);
        //Other public funcs
        ClapTrap(std::string name);
        //Action functions
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
    private:
        std::string _name;
        unsigned int         _hitPoints;
        unsigned int         _energyPoints;
        unsigned int         _attackDmg;
};

#endif