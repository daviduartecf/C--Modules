#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN& RPN::operator = (const RPN& other) {
    if (this != &other)
    {
        this->myStack = other.myStack;
    }
    return *this;
}

RPN::RPN(const RPN& other) {
    this->myStack = other.myStack;
}

RPN::RPN(std::string input) {
	std::stack<std::string> newStack;
	std::stringstream ss(input);
	std::string token;
	while (ss >> token) {
		if (atoi(token.c_str()) > INT_MAX || atoi(token.c_str()) < INT_MIN)
			std::cerr << "ERROR token: " << token << std::endl;
			//throw Exception();
		myStack.push(token);
	}
	while (!myStack.empty()) {
		newStack.push(myStack.top());
		myStack.pop();
	}
/* 	while (!newStack.empty()) {
		std::cout <<  newStack.top() << std::endl;
		newStack.pop();
	} */
	int result, num1, num2;
	std::string operand;
	while (!newStack.empty()) {
		num1 = atoi(newStack.top().c_str());
		newStack.pop();
		num2 = atoi(newStack.top().c_str());
		newStack.pop();
		operand = newStack.top();
		if (operand == "*") {
			result = num1 * num2;
		}
		else if (operand == '-') {
			result = num2 -
		}
	}
}
