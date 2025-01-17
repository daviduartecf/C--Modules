#ifndef FragTRAP_HPP
#define FragTRAP_HPP

#include <iostream>
#include <string.h>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        //Orthodox Canonical Form
        FragTrap();
        virtual ~FragTrap();
        FragTrap& operator =(const FragTrap& other);
        FragTrap(const FragTrap& other);
        //Name Constructor
        FragTrap(std::string name);
        //Public methods
        void highFivesGuys(void);
    private:
        bool _guard_state;
};

#endif