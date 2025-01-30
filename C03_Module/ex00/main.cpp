#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b("Manel");
    ClapTrap c = b;

    std::cout << "\033[34mTesting\033[0m" << std::endl;
    a.attack("some other robot");
    a.takeDamage(10);
    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("some other other robot");
    b.beRepaired(3);
    for (int i = 0; i < 12; i++)
        b.attack("clone");
    b.beRepaired(3);
	std::cout << "b energy: " << b.getEnergy() << std::endl;
	std::cout << "b attack: " << b.getAttackdmg() << std::endl;
	std::cout << "b hitpoints: " << b.getHitpoints() << std::endl;
	ClapTrap x = b;
	x.attack("fukk");
	std::cout << "x attack: " << x.getAttackdmg() << std::endl;
    return 0;
}
