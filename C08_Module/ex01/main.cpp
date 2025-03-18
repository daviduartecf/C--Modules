#include "Span.hpp"
#include <iostream>

int main() {
	try {
		std::cout << "---------------Test 1---------------" << std::endl;
		Span spano(10000);

		for (int i = 0; i < 10000; i++) {
			spano.addNumber(i);
		}
        std::cout << "After adding numbers:" << std::endl;
        std::cout << "Shortest Span: " << spano.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spano.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "---------------Test 2---------------" << std::endl;
		Span spano(7);

		spano.addNumber(5);
		spano.addNumber(10);
		spano.addNumber(20);
		spano.addNumber(30);
		spano.addNumber(40);
		spano.addNumber(50);
		spano.addNumber(100);

        std::cout << "After adding numbers:" << std::endl;
        std::cout << "Shortest Span: " << spano.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spano.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "---------------Test 3---------------" << std::endl;
		Span spano(10000);
		std::vector<int> numbers;

    	for (int i = 0; i < 10000; i++) {
       		numbers.push_back(i);
		}
		spano.addNumber(numbers.begin(), numbers.end());
		std::cout << "Added " << numbers.size() << " numbers in one call!" << std::endl;

        std::cout << "After adding numbers:" << std::endl;
        std::cout << "Shortest Span: " << spano.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spano.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "---------------Test 4---------------" << std::endl;
		Span spano(3);

		spano.addNumber(2);
		spano.addNumber(10);
		spano.addNumber(20);
		spano.addNumber(30);

        std::cout << "After adding numbers:" << std::endl;
        std::cout << "Shortest Span: " << spano.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spano.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "---------------Test 5---------------" << std::endl;
		Span spano(3);

		spano.addNumber(2);

        std::cout << "After adding numbers:" << std::endl;
        std::cout << "Shortest Span: " << spano.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spano.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
