#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap frag1("Terminator");
    FragTrap frag2;
    frag2 = frag1;
    FragTrap frag3(frag1);

    frag1.highFivesGuys();
    frag2.attack("manel");
	frag2.beRepaired(10);
    frag2.highFivesGuys();

    return 0;
}
