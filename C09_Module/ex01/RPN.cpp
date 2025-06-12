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

float RPN::doOp(float num1, float num2, std::string operat) {
	float result = 0;
	if (operat == "+") {
		result = num1 + num2;
	}
	else if (operat == "-") {
		result = num1 - num2;
	}
	else if (operat == "*") {
		result = num2 * num1;
	}
	else if (operat == "/") {
		result = num1 / num2;
	}
	return result;
}

bool RPN::isNumber(const std::string token) {
	char* end;
    float value = std::strtol(token.c_str(), &end, 10);

	if (*end != '\0')
		return false;
	if (value > 9 || value < INT_MIN)
		return false;
	return true;
}

bool RPN::isOperator(const std::string token) {
	if (token.length() == 1 && (token == "-" || token == "+" || token == "*" || token == "/"))
		return true;
	return false;
}

void RPN::validateOrder(std::stack<std::string>& newStack) {
	bool expectOperator = true;
	int numberCount = 0, operatorCount = 0;
	while (!myStack.empty()) {
		if (isNumber(myStack.top())) {
			if (myStack.size() == 1)
				expectOperator = false;
			if (expectOperator)
				throw WrongOrder();
			numberCount ++;
			expectOperator = true;
		}
		else if (isOperator(myStack.top())) {
			if (!expectOperator)
				throw WrongOrder();
			operatorCount ++;
			expectOperator = false;
		}
		newStack.push(myStack.top());
		myStack.pop();
	}
	if (!(numberCount >= 2 && operatorCount >= 1))
		throw WrongOrder();
}

float RPN::firstOp(std::stack<std::string>& newStack) {
	float result;
	float num1, num2;
	char *end;
	std::string operat;

	num1 = std::strtol(newStack.top().c_str(), &end, 10);
	newStack.pop();
	num2 = std::strtol(newStack.top().c_str(), &end, 10);
	newStack.pop();
	operat = newStack.top();
	newStack.pop();
	result = doOp(num1, num2, operat);

	return result;
}

RPN::RPN(std::string input) {
	std::stack<std::string> newStack;
	std::stringstream ss(input);
	std::string token;

	while (ss >> token) {
		if (!isOperator(token) && !isNumber(token))
			throw WrongOrder();
		myStack.push(token);
	}

	//validate order of stack and populate new stack in correct order
 	validateOrder(newStack);

	float result;
	float num;
	char *end;
	result = 0;
	std::string operat;
	//first op
	result = firstOp(newStack);
	while (!newStack.empty()) {
		num = std::strtol(newStack.top().c_str(), &end, 10);
		newStack.pop();
		operat = newStack.top();
		newStack.pop();
		result = doOp(result, num, operat);
	}
	//if (result > INT_MAX || result < INT_MIN)
	//	throw WrongOrder();
	std::cout << result << std::endl;
}

const char* RPN::WrongOrder::what() const throw() {
	return "Error";
}
