#include "PmergeMe.hpp"

int main(int argc, char * argv[]) {
	if (argc < 2) {
		std::cerr << "Wrong usage!" << std::endl;
		return 1;
	}
	/* try {
		PmergeMe PmergeMe(argv, argc);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	} */
	PmergeMe PmergeMe(argv, argc);
}
