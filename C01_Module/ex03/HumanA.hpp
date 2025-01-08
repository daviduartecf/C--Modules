#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void    attack(void);
    private:
        std::string _name;
        Weapon& _weapon;
};

#endif