#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "Creating a FragTrap named 'Terminator'" << std::endl;
    FragTrap frag1("Terminator"); // Call name constructor

    std::cout << "\nCreating a FragTrap named 'Destroyer' via default constructor" << std::endl;
    FragTrap frag2; // Call default constructor
    frag2 = frag1;  // Call assignment operator

    std::cout << "\nCopy constructing 'Replicator' from 'Terminator'" << std::endl;
    FragTrap frag3(frag1); // Call copy constructor

    std::cout << "\nUsing FragTrap 'Terminator' to demonstrate functionality" << std::endl;
    frag1.highFivesGuys(); // Call FragTrap's special method

    std::cout << "\nDemonstrating destruction order" << std::endl;
    return 0;
}
