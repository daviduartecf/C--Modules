#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

// Function to randomly generate a Base instance
Base* generate() {
    int random = rand() % 3; // Generate a random number 0, 1, or 2
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

// Function to identify the type of object pointed by Base pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

// Function to identify the type of object pointed by Base reference
void identify(Base& p) {
    identify(&p); // Call the pointer version
}
