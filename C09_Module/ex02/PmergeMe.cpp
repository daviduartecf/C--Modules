#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator = (const PmergeMe& other) {
    if (this != &other)
    {
        this->myDeque = other.myDeque;
		this->myVector = other.myVector;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->myDeque = other.myDeque;
	this->myVector = other.myVector;
}

PmergeMe::PmergeMe(char *input[], int argc) {
	for (int i = 1; i < argc; i ++) {
		std::string str(input[i]);
		if (!isValidNumber(str)) {
			//throw ExceptionF();
			return;
		}
		
	}
}

bool PmergeMe::isValidNumber(std::string token) {
	for (size_t i = 0; i < token.length(); i ++) {
		if (!isdigit(token[i]))
			return false;
	}
	try {
		long long num = std::stoll(token);
		if (num < INT_MIN || num > INT_MAX)
			return false;
	}
	catch (std::exception& e) {
		std::cout << e.what() <<std::endl;
	}
}
