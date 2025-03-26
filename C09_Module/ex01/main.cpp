#include "RPN.hpp"

int main(int argc, char * argv[]) {
	if (argc < 2) {
		std::cerr << "Wrong usage!" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
