#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav1("Guardian");
    ScavTrap scav2;
    scav2 = scav1;
    ScavTrap scav3(scav1);

	scav3.attack("olo");
    for (int i = 0; i < 50; i++)
        scav3.attack("clone");
    scav1.guardGate();
	scav1.guardGate();
    return 0;
}
