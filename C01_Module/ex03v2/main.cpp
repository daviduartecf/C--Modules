#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int main()
{
    {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }
    {
    std::cout << "-----CREATION OF WEAPON-----" << std::endl;
    Weapon club = Weapon("crude spiked club");
    std::cout << "-----constructor oh humanB and humanA-----" << std::endl;
    HumanB toze("toze");
    HumanA berto("berto", club);
    std::cout << "-----ATTACK WITHOUT WEAPON-----" << std::endl;
    toze.attack();
    std::cout << "-----SET WEAPON-----" << std::endl;
    toze.setWeapon(club);
    std::cout << "-----ATTACK WITH WEAPON-----" << std::endl;
    toze.attack();
    berto.attack();
    std::cout << "-----CHANGE WEAPON TYPE-----" << std::endl;
    club.setType("some other type of club");
    std::cout << "-----ATTACK WITH WEAPON-----" << std::endl;
    toze.attack();
    berto.attack();
    }
    return 0;
}