#include "Array.hpp"

int main() {
	Array<int> arr(5);

	try {
		for (unsigned int i = 0; i < 5; i++) {
				arr[i] = (i + 1) * 10;
			}

		std::cout << "Array elements: ";
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		Array<int> arrCopy = arr;
		std::cout << "Copied array elements: ";
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << arrCopy[i] << " ";
		}
		std::cout << std::endl;

		Array<int> arrAssigned(3);  // Different size array
		arrAssigned = arr;  // Now same size as arr
		std::cout << "Assigned array elements: ";
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << arrAssigned[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Trying to access index 10..." << std::endl;
		std::cout << arr[10] << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
