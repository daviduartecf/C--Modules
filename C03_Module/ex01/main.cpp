#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating a ScavTrap named 'Guardian'" << std::endl;
    ScavTrap scav1("Guardian"); // Call name constructor

    std::cout << "\nCreating a ScavTrap named 'Sentinel' via default constructor" << std::endl;
    ScavTrap scav2; // Call default constructor
    scav2 = scav1;  // Call assignment operator

    std::cout << "\nCopy constructing 'Defender' from 'Guardian'" << std::endl;
    ScavTrap scav3(scav1); // Call copy constructor

    std::cout << "\nUsing ScavTrap 'Guardian' to demonstrate functionality" << std::endl;
    scav1.guardGate(); // Call guardGate function

    std::cout << "\nDemonstrating destruction order" << std::endl;
    return 0;
}