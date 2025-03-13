#include "Array.hpp"

int main() {
	Array<int> arr(5);
	Array<int> const_array(5);
	Array<int> arr2;

	//TESTING EMPTY ARRAY
	try {
		std::cout << "\033[1;33m" "Testing empty array:" "\033[0m" << std::endl;
		for (unsigned int i = 0; i < 5; i++) {
				arr2[i] = (i + 1) * 10;
			}
		std::cout << "Array2 elements: ";
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "\033[1;31m" "Exception caught: " "\033[0m" << e.what() << std::endl;
	}
	//TESTING NORMAL ARRAY
	try {
		std::cout << "\033[1;33m" "Testing normal array:" "\033[0m" << std::endl;
		for (unsigned int i = 0; i < 5; i++) {
				arr[i] = (i + 1) * 10;
			}

		std::cout << "Array elements: ";
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << "\033[1;32m" << arr[i] << " " << "\033[0m";
		}
		std::cout << std::endl;

		Array<int> arrCopy = arr;
		std::cout << "Copied array elements: ";
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << "\033[1;32m" << arrCopy[i] << " " << "\033[0m";
		}
		std::cout << std::endl;

		//TESTING CONST ARRAY
		Array<int> const constArray = arr;
		std::cout << "Assigned const array elements: ";
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << "\033[1;32m" << constArray[i] << " " << "\033[0m";
		}
		std::cout << std::endl;

		std::cout << "\033[1;33m" "Trying to access index 10..." "\033[0m" << std::endl;
		std::cout << arr[10] << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "\033[1;31m" "Exception caught: " "\033[0m" << e.what() << std::endl;
    }
    return 0;
}
