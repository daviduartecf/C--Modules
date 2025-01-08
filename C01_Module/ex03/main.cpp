#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main(void) {
//     Weapon gun("pistol");
//     std::cout << "type: " << gun.getType() << std::endl;
//     gun.setType("machine gun");
//     std::cout << "type: " << gun.getType() << std::endl;

//     HumanA humanA("Fernando", gun);
//     HumanB humanB("Ruiquelme");

//     humanA.attack();
//     humanB.attack();
// }

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
    return 0;
}