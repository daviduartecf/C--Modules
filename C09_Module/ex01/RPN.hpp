#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include <sstream>
# include <fstream>
# include <climits>
# include <cstdlib>

class RPN {
    public:
		//ORTHODOX CANONICAL FORM
        RPN(); //posso deixar este?
        ~RPN();
        RPN(const RPN& other);
        RPN& operator = (const RPN& other);
		RPN(std::string input);
		long firstOp(std::stack<std::string>& newStack);
		long doOp(long num1, long num2, std::string operat);
		bool isNumber(const std::string token);
		bool isOperator(const std::string token);
		void validateOrder(std::stack<std::string>& newStack);
		class WrongOrder: public std::exception {
			public:
				const char* what() const throw();
		};
    private:
        std::stack<std::string> myStack;
};

#endif // RPN_HPP
