#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    // Generate random Base instance
    Base* instance = generate();
    
    // Identify the type using pointer
    std::cout << "Identifying using pointer: ";
    identify(instance);

    // Identify the type using reference
    std::cout << "Identifying using reference: ";
    identify(*instance);

    // Clean up
    delete instance;

    return 0;
}
