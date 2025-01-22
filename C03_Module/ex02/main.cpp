#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "Creating a FragTrap named 'Terminator'" << std::endl;
    FragTrap frag1("Terminator");

    std::cout << "\nCreating a FragTrap named 'Destroyer' via default constructor" << std::endl;
    FragTrap frag2;
    frag2 = frag1;

    std::cout << "\nCopy constructing 'Replicator' from 'Terminator'" << std::endl;
    FragTrap frag3(frag1);

    std::cout << "\nUsing FragTrap 'Terminator' to demonstrate functionality" << std::endl;
    frag1.highFivesGuys();
    frag2.attack("manel");
    frag2.highFivesGuys();

    std::cout << "\nDemonstrating destruction order" << std::endl;
    return 0;
}
