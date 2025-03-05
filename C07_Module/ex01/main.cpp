#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void printElement(T &elem) {
    std::cout << elem << " ";
}

template<typename T> //T can be any type
void addOne(T &elem) {
    elem = elem + 1;
}

template<> //specialization of addOne
void addOne<std::string>(std::string &elem) { //fixing the type (string)
	elem += '1';
}

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, 5, printElement<int>);
	std::cout << std::endl;
	iter(intArr, 5, addOne<int>);
	iter(intArr, 5, printElement<int>);
    std::cout << std::endl;

    double doubleArr[] = {1.1, 2.2, 3.3};
    iter(doubleArr, 3, printElement<double>);
	std::cout << std::endl;
	iter(doubleArr, 3, addOne<double>);
	iter(doubleArr, 3, printElement<double>);
	std::cout << std::endl;

    std::string strArr[] = {"Hello", "42", "School"};
	iter(strArr, 3, printElement<std::string>);
	std::cout << std::endl;
	iter(strArr, 3, addOne<std::string>);
	iter(strArr, 3, printElement<std::string>);
	std::cout << std::endl;
}
