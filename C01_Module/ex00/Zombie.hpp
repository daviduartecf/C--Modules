#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include "Zombie.hpp"

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif