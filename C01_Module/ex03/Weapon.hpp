#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string& getType(void) const;
        void    setType(const std::string& type);
    private:
        std::string _type;
};

#endif