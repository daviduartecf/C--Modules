#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    srand((time(0)));

	for (int i = 0; i < 5; i++) {
		Base* instance = generate();
		std::cout << "Identifying using pointer: ";
		identify(instance);

		std::cout << "Identifying using reference: ";
		identify(*instance);
    	delete instance;
	}

    return 0;
}
