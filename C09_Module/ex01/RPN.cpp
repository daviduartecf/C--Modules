#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isValidNumber(const std::string& token) {
    if (token.length() != 1)
        return false;
    return token[0] >= '0' && token[0] <= '9';
}

double RPN::performOperation(double a, double b, const std::string& op) {
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/") {
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b;
    }
    throw std::runtime_error("Error");
}

double RPN::calculate(const std::string& arg) {
    while (!_stack.empty()) {
        _stack.pop();
	}

    std::istringstream iss(arg);
    std::string token;

    while (iss >> token) {
        if (isValidNumber(token)) {
            // push num to stack
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token)) {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            // Save values and pop from stack
            double b = _stack.top();
			_stack.pop();
            double a = _stack.top();
			_stack.pop();

            // Operation
            double result = performOperation(a, b, token);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
