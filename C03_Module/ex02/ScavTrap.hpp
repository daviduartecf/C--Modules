#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string.h>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        //Orthodox Canonical Form
        ScavTrap();
        virtual ~ScavTrap();
        ScavTrap& operator =(const ScavTrap& other);
        ScavTrap(const ScavTrap& other);
        //Name Constructor
        ScavTrap(std::string name);
        //Public methods
        void guardGate(void);
    private:
        bool _guard_state;
};

#endif