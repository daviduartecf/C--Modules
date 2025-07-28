#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN {
private:
    std::stack<double> _stack;
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    double calculate(const std::string& expression);
	bool isOperator(const std::string& token);
    bool isValidNumber(const std::string& token);
    double performOperation(double a, double b, const std::string& op);
};

#endif
